package com.heyang.biz.server.model;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;
import org.dom4j.io.OutputFormat;
import org.dom4j.io.SAXReader;
import org.dom4j.io.XMLWriter;

import com.heyang.biz.server.view.ServerView;
import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.RSASecurityCoder;

/**
 * MVC之业务，数据
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-25 上午07:49:00
 * 修改时间：2010-12-25 上午07:49:00
 */
public class ServerModel{
	private static final String RES_USERS_XML = "res/users.xml";

	// 负责监听的服务器套接字
	private ServerSocket serverSocket;
	
	// 注册用户哈希表
	private Map<String,String> userMap;
	
	// 用于RSA加密解密的编码器
	private RSASecurityCoder rsaCoder;
	
	// 用于AES加密解密的编码器
	private AESSecurityCoder aesCoder;
	
	// 已登录用户哈希表
	private Map<String,LoginUser> loginedUserMap;
	
	/**
	 * 构造函数
	 */
	public ServerModel(){
		initialize();
	}
	
	/**
	 * 初始化成员变量
	 * 
	 * 说明：
	 * 创建时间：2010-4-29 下午10:06:10
	 * 修改时间：2010-4-29 下午10:06:10
	 */
	public void initialize(){
		userMap=new HashMap<String,String>();
		loginedUserMap=new HashMap<String,LoginUser>();
		
		// 从XML文件中读取注册用户信息 
		File file=new File(RES_USERS_XML);
		
		if(file.exists()){
			try {
				SAXReader reader = new SAXReader();
	            Document  document = reader.read(file);
	            Element rootElm = document.getRootElement();
	            
	            List<?> nodes = rootElm.elements("user");

	            for (Iterator<?> it = nodes.iterator(); it.hasNext();) {
	               Element elm = (Element) it.next();
	               
	               userMap.put(elm.elementText("name"), elm.elementText("pswd"));
	            }
			} catch (Exception e) {
				System.out.println("无法从XML文件中读取注册用户信息，原因为"+e.getMessage());
				e.printStackTrace();
			}
		}
		
		
		try {
			rsaCoder=new RSASecurityCoder();
			aesCoder=new AESSecurityCoder();
			
		} catch (Exception e) {
			System.out.println("无法加载RSA或AES编码器，原因为"+e.getMessage());
			e.printStackTrace();
		}
	}
	
	// 将注册用户列表存储到文件中
	public void saveUsersToFile(){
		try {
			OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(RES_USERS_XML),"UTF-8");   
            OutputFormat format = OutputFormat.createPrettyPrint();
            format.setEncoding("UTF-8");    // 指定XML编码       
            XMLWriter writer = new XMLWriter(osw,format);
            
            Document document = DocumentHelper.createDocument();
    		Element root = document.addElement("users");

    		for(String user:userMap.keySet()){
    			Element userElm=root.addElement("user");
    			userElm.addElement("name").addText(user);
    			userElm.addElement("pswd").addText(userMap.get(user));
    		}
           
            writer.write(document);
            writer.close();
		} catch (Exception e) {
			System.out.println("无法将注册用户信息存储到文件中，原因为"+e.getMessage());
			e.printStackTrace();
		}
	}
	
	/**
	 * 开始监听
	 * 
	 * 说明：
	 * @param port
	 * 创建时间：2010-12-24 下午03:47:23
	 * @throws IOException 
	 */
	public void startLinsten(int port,ServerView view) throws IOException{
		serverSocket=new ServerSocket(port);
		System.out.println("服务开始.");
		
		while(true){
            Socket incoming=serverSocket.accept();
            // InetAddress address=incoming.getInetAddress();
            // System.out.println("开始与"+address+"进行通讯.");
            
            new Thread(new Communicator(incoming,view,this)).start();
        }
	}
	
	/**
	 * 停止监听
	 * 
	 * 说明：
	 * @throws IOException
	 * 创建时间：2010-12-31 上午11:55:37
	 */
	public void stopLinsten() throws IOException{
		serverSocket.close();
	}
	
	/**
	 * 向合法用户哈希表中添加一个用户
	 * 
	 * 说明：
	 * @param userName
	 * @param password
	 * @return
	 * 创建时间：2010-12-24 下午08:32:23
	 */
	public boolean addUser(String userName,String password){
		if(userMap.containsKey(userName)){
			return false;
		}
		else{
			userMap.put(userName, password);
			return true;
		}
	}
	
	/**
	 * 判断用户名密码是否是已注册用户
	 * 
	 * 说明：
	 * @param userName
	 * @param password
	 * @return
	 * 创建时间：2010-12-28 下午05:02:37
	 */
	public boolean isRegisterredUser(String userName,String password){
		if(userMap.containsKey(userName)==false){
			return false;
		}
		else{
			String pswd=userMap.get(userName);
			
			return pswd.equals(password);
		}
	}
	
	/**
	 * 是否登录用户
	 * 
	 * 说明：
	 * @param userName
	 * @param password
	 * @return
	 * 创建时间：2010-12-28 下午09:36:50
	 */
	public boolean isLoginnedUser(String userName){
		return loginedUserMap.containsKey(userName);
	}
	
	/**
	 * 取得登录用户
	 * 
	 * 说明：
	 * @param userName
	 * @return
	 * 创建时间：2010-12-28 下午10:21:09
	 */
	public LoginUser getLoginnedUser(String userName){
		return loginedUserMap.get(userName);
	}
	
	/**
	 * 从登录用户中删除
	 * 
	 * 说明：
	 * @param userName
	 * 创建时间：2010-12-28 下午09:40:06
	 */
	public void removeLoginnedUser(String userName){
		loginedUserMap.remove(userName);
	}
	
	/**
	 * 添加一个登录用户
	 * 
	 * 说明：
	 * @param userName
	 * @param rsaPublicKey
	 * @param port
	 * @return
	 * 创建时间：2010-12-28 下午04:59:24
	 */
	public boolean addLoginUser(String userName,String rsaPublicKey,String clientIpAddr,int port){
		if(loginedUserMap.containsKey(userName)){
			return false;
		}
		else{
			loginedUserMap.put(userName, new LoginUser(userName,rsaPublicKey,clientIpAddr,port));
			return true;
		}
	}
	
	/**
	 * 得到服务器的RSA公钥
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-12-24 下午09:17:56
	 */
	public String getPublicKey(){
		return rsaCoder.getPublicKeyString();
	}

	/**
	 * 取得RSA编码器
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-12-25 下午12:30:55
	 */
	public RSASecurityCoder getRsaCoder() {
		return rsaCoder;
	}

	/**
	 * 取得AES编码器
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-12-25 下午12:31:09
	 */
	public AESSecurityCoder getAesCoder() {
		return aesCoder;
	}
	
	/**
	 * 取得已注册用户列表
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-12-28 下午01:27:48
	 */
	public Object[] getRegisteredUsers(){
		Set<String> set=userMap.keySet();
		return set.toArray();
	}
	
	/**
	 * 取得已登录用户列表
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-12-28 下午09:27:38
	 */
	public Object[] getLoginnedUsers(){
		Set<String> set=loginedUserMap.keySet();
		return set.toArray();
	}
}