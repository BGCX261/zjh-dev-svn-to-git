package com.heyang.biz.server.model;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;

import com.heyang.biz.server.view.ServerView;
import com.heyang.common.cipher.IMMsgDecryptException;
import com.heyang.common.cipher.IMMsgDecrypter;
import com.heyang.common.cipher.IMMsgEncryptException;
import com.heyang.common.cipher.IMMsgEncrypter;

/**
 * 用于与客户端交流的线程
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-24 下午04:10:26
 * 修改时间：2010-12-24 下午04:10:26
 */
public class Communicator implements Runnable{
	private Socket incoming;
	private ServerView view;
	private ServerModel model;
    
	/**
	 * 构造函数
	 * @param incoming
	 * @param view
	 */
    public Communicator(Socket incoming,ServerView view,ServerModel model){
        this.incoming=incoming;
        this.view=view;
        this.model=model;
    }
    
    
    public void run(){
    	try{
    		String remoteIp=incoming.getRemoteSocketAddress().toString();
    		
            InputStream  inStram=incoming.getInputStream();
            OutputStream outStream=incoming.getOutputStream();
            
            Scanner in=new Scanner(inStram);
            PrintWriter out=new PrintWriter(outStream,true);
            
            // 得到客户端的请求
            StringBuilder sb=new StringBuilder();
            while(in.hasNextLine()){
                String line=in.nextLine();
                sb.append(line);
            }
            
            String request=sb.toString();
            String response="";
            if("getPublicKey".equals(request)){
            	// 求服务器公钥
            	response=model.getPublicKey();
            }
            else{
            	String plainRequest="";
            	String clientRSAPublicKey="";
            	
            	try{
            		// 解密过程
            		IMMsgDecrypter decrypter=new IMMsgDecrypter(request,model.getRsaCoder(),model.getAesCoder());
            		plainRequest=decrypter.getPlainMsg();
            		clientRSAPublicKey=decrypter.getOtherSideRSAPublicKey();
            		
            		view.getMsgArea().insertBlueMsg(plainRequest,remoteIp);
            	}catch(IMMsgDecryptException e){
            		view.getMsgArea().insertRedMsg("无法解密"+request,remoteIp);
            		response="<response><status>ng<status><msg>"+e.getMessage()+"</msg></response>";
            	}
            	
            	// 消息处理过程
            	String clientIpAddr=incoming.getInetAddress().getHostAddress();
        		response=getResponse(plainRequest,clientRSAPublicKey,clientIpAddr);
        		view.getMsgArea().insertBlackMsg(response,remoteIp);
            	
            	try{
            		// 加密过程
            		IMMsgEncrypter encrypter=new IMMsgEncrypter(response,clientRSAPublicKey,model.getRsaCoder(),model.getAesCoder());
            		response=encrypter.getCipheredMsg();
            	}
            	catch(IMMsgEncryptException e){
            		view.getMsgArea().insertRedMsg("无法加密"+response,remoteIp);
            		response="<response><status>ng<status><msg>"+e.getMessage()+"</msg></response>";
            	}
            }
            
            // 向客户端送出反馈
            out.print(response);
            out.flush();
            out.close();
        }
        catch(Exception ex){
            ex.printStackTrace();
        }
        finally{
            try {
                incoming.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
   
    /**
     * 根据客户端的请求得到服务器端的反馈
     * 
     * 说明：
     * @param request
     * @return
     * 创建时间：2010-12-24 下午08:43:19
     */
    private String getResponse(String request,String clientRsaPublicKey,String clientIpAddr){
    	String retval="<response><status>ng<status><msg>无法解析客户端的请求</msg></response>";
    	Map<String,String> requestMap=null;
    	
    	// 将文本形式的XML转化为Key-Value的形式
    	try{
    		requestMap=parseRequest(request);
    	}
    	catch(Exception e){
    		retval="<response><status>ng<status><msg>无法识别的请求格式</msg></response>";
    	}
    	
    	// 判断命令是否合法
    	String command=requestMap.get("command");
    	if("register_login_logout_dispatch_getUserList".contains(command)==false){
    		retval="<response><status>ng<status><msg>"+command+"不在许可的命令模式中"+"</msg></response>";
    	}
    	
    	if(command.equals("register")){
    		// 注册
    		
    		String username=requestMap.get("username");
    		String password=requestMap.get("password");
    		
    		if(model.addUser(username, password)){
    			view.showRegisteredUsers(model.getRegisteredUsers());
    			retval="<response><status>ok</status><msg>"+"用户名:'"+username+"'注册成功"+"</msg></response>";
    		}
    		else{
    			retval="<response><status>ng</status><msg>"+"用户名:'"+username+"'已经被别人注册了，请换个名称"+"</msg></response>";
    		}
    	}else if(command.equals("login")){
    		// 登录
    		String userName=requestMap.get("username");
    		String password=requestMap.get("password");
    		
    		if(model.isRegisterredUser(userName, password)){
    			String rsaPublicKey=clientRsaPublicKey;
        		int port=Integer.parseInt(requestMap.get("port"));
    			
    			if(model.addLoginUser(userName, rsaPublicKey,clientIpAddr,port)){
    				view.showLoginnededUsers(model.getLoginnedUsers());
    				retval="<response><status>ok</status><msg>允许'"+userName+"'通过登录</msg></response>";
    			}
    			else{
    				retval="<response><status>ng</status><msg>用户‘"+userName+"’已经登录了。</msg></response>";
    			}
    		}
    		else{
    			retval="<response><status>ng</status><msg>用户名或密码不正确</msg></response>";
    		}
    	}else if(command.equals("logout")){
    		// 登出
    		String userName=requestMap.get("username");
    		String password=requestMap.get("password");
    		
    		if(model.isRegisterredUser(userName, password) && model.isLoginnedUser(userName)){
    			model.removeLoginnedUser(userName);
    			view.showLoginnededUsers(model.getLoginnedUsers());
    			
    			retval="<response><status>ok</status><msg>用户'"+userName+"'已经退出登录</msg></response>";
    		}
    		else{
    			retval="<response><status>ng</status><msg>用户'"+userName+"'并非注册用户或登录用户</msg></response>";
    		}
    	}else if(command.equals("dispatch")){
    		// 转发
    		String userName=requestMap.get("username");
    		String password=requestMap.get("password");
    		
    		if(model.isRegisterredUser(userName, password) && model.isLoginnedUser(userName)){
    			String toUserName=requestMap.get("to");
    			
    			if(model.isLoginnedUser(toUserName)){
    				LoginUser user=model.getLoginnedUser(toUserName);    				
    				String msg=requestMap.get("msg");
    				
    				// 开始向第三方发出消息的线程
    				new DispatchMsgThread(userName,user,msg,model.getRsaCoder(),model.getAesCoder()).start();
    				
    				retval="<response><status>ok</status><msg>将向用户'"+toUserName+"'发送您给出的信息</msg></response>";
    			}
    			else{
    				retval="<response><status>ng</status><msg>用户'"+toUserName+"'并非登录用户</msg></response>";
    			}
    		}
    		else{
    			retval="<response><status>ng</status><msg>用户'"+userName+"'并非注册用户或登录用户</msg></response>";
    		}
    	}else if(command.equals("getUserList")){
    		// 转发
    		String userName=requestMap.get("username");
    		String password=requestMap.get("password");
    		
    		if(model.isRegisterredUser(userName, password) && model.isLoginnedUser(userName)){
    			Object[] objs=model.getLoginnedUsers();
    			
    			StringBuilder sb=new StringBuilder("<response><status>ok</status><users>");
    			
    			for(Object obj:objs){
    				sb.append("<user>"+obj+"</user>");
    			}
    			sb.append("</users></response>");
    			
    			retval=sb.toString();
    		}
    		else{
    			retval="<response><status>ng</status><msg>用户'"+userName+"'并非注册用户或登录用户</msg></response>";
    		}
    	}
        
        return retval;
    }
    
    /**
     * 将文本形式的XML转化为Key-Value的形式
     * 抛出任何异常说明传入不符合格式
     * 说明：
     * @param request
     * @return
     * @throws Exception
     * 创建时间：2010-12-24 下午08:48:33
     */
    private Map<String,String> parseRequest(String requestXML) throws Exception{
    	Document doc=DocumentHelper.parseText(requestXML);		
    	Element root=doc.getRootElement();
    	
    	if(!root.getName().equals("request")){
    		throw new Exception("根节点不合法");
    	}
    	
    	Map<String,String> retvalMap=new HashMap<String,String>();
    	List<?> nodes = root.elements();

    	for (Iterator<?> it = nodes.iterator(); it.hasNext();) {
    	   Element elm = (Element) it.next();

    	   retvalMap.put(elm.getName(), elm.getText());
    	}
    	
    	return retvalMap;
    }
}