package com.heyang.biz.client.userlist.model;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

import org.apache.commons.codec.binary.Base64;
import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;

import com.heyang.biz.client.ClientUtil;
import com.heyang.biz.client.chat.ctrl.ChatCtrl;
import com.heyang.biz.client.userlist.view.UserlistView;
import com.heyang.common.cipher.IMMsgDecryptException;
import com.heyang.common.cipher.IMMsgDecrypter;
import com.heyang.common.cipher.IMMsgEncryptException;
import com.heyang.common.cipher.IMMsgEncrypter;
import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.RSASecurityCoder;

/**
 * User List Window's data center
 * @author heyang
 *
 */
public class UserlistModel{
	// 聊天窗口的哈希表，用于控制
	private Map<String,ChatCtrl> chatWindowMap;
	
	// 负责监听的服务器套接字
	private ServerSocket serverSocket;
	
	/**
	 * Contructor
	 */
	public UserlistModel(){
		chatWindowMap=new HashMap<String,ChatCtrl>();
	}
	
	/**
	 * 添加或者激活一个聊天窗口，返回值为聊天窗口的引用
	 * @param opponentName
	 * @return
	 */
	public ChatCtrl addOrActiveChatWindow(String opponentName){
		if(chatWindowMap.containsKey(opponentName)){
			ChatCtrl ctrl=chatWindowMap.get(opponentName);
			return ctrl;
		}
		else{
			ChatCtrl ctrl=new ChatCtrl();
			ctrl.getView().setTitle("与"+opponentName+"聊天 "+ctrl.getView().getTitle());
			ctrl.getModel().setOpponentName(opponentName);
			ctrl.getModel().setUserListModel(this);
			chatWindowMap.put(opponentName, ctrl);
			return ctrl;
		}
	}
	
	/**
	 * 删除一个聊天窗口
	 * @param opponentName
	 * @return
	 */
	public boolean removeChatWindow(String opponentName){
		if(chatWindowMap.containsKey(opponentName)){
			chatWindowMap.remove(opponentName);
			return true;
		}
		else{
			return false;
		}
	}
	
	/**
	 * 取得已登录的用户列表
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-12-30 下午11:15:32
	 */
	public List<String> getLoginnedUsers(){
		List<String> list=new ArrayList<String>();
		
		try{
			String response=getUserListString();
			Document doc=DocumentHelper.parseText(response);		
	    	Element root=doc.getRootElement();
	    	
	    	List<?> nodes = root.element("users").elements();

	    	for (Iterator<?> it = nodes.iterator(); it.hasNext();) {
	    	   Element elm = (Element) it.next();

	    	   list.add(elm.getText());
	    	}
	    	return list;
		}catch(Exception e){
			e.printStackTrace();
			return list;
		}
	}
	
	private String getUserListString() throws Exception{
		RSASecurityCoder rsaCoder=ClientUtil.getRsaCoder();
		byte[] serverPublicKey=ClientUtil.getServerRSAPublicKey();
		AESSecurityCoder aesCoder=ClientUtil.getAesCoder();
		
		Socket s=new Socket(ClientUtil.getServerIP(),ClientUtil.getServerPort());
		
		InputStream  inStram=s.getInputStream();
        OutputStream outStream=s.getOutputStream();
        
        // 输出
        PrintWriter out=new PrintWriter(outStream,true);
        
        // 待加密的明文
        StringBuilder sb1=new StringBuilder();
        sb1.append("<request>");
        sb1.append("<command>getUserList</command>");
        sb1.append("<username>"+ClientUtil.getLogininedUsername()+"</username>");
        sb1.append("<password>"+ClientUtil.getLogininedPassword()+"</password>");
        sb1.append("</request>");
        String plainText=sb1.toString();
        
        String request="";
        try{
    		// 加密过程
    		IMMsgEncrypter encrypter=new IMMsgEncrypter(plainText,Base64.encodeBase64String(serverPublicKey),rsaCoder,aesCoder);
    		request=encrypter.getCipheredMsg();
    	}
    	catch(IMMsgEncryptException e){
    		System.out.println("无法对客户端请求进行加密");
    		throw e;
    	}
      
        out.print(request);
        out.flush();
        s.shutdownOutput();// 输出结束
        
        // 输入
        Scanner in=new Scanner(inStram);
        StringBuilder sb=new StringBuilder();
        while(in.hasNextLine()){
        	String line=in.nextLine();
        	sb.append(line);
        }
        String response=sb.toString();
        s.close();
    	
    	try{
    		// 解密过程
    		IMMsgDecrypter decrypter=new IMMsgDecrypter(response,rsaCoder,aesCoder);
    		String plainResponse=decrypter.getPlainMsg();
    		return plainResponse;
    	}catch(IMMsgDecryptException e){
    		System.out.println("无法对服务器端响应进行解密");
    		throw e;
    	}
	}
	
	/**
	 * 开始监听
	 * @param view
	 * @throws IOException
	 */
	public void startListen(UserlistView view) throws IOException{
		serverSocket=new ServerSocket(ClientUtil.getListenPort());
		
		while(true){
            Socket incoming=serverSocket.accept();
            
            new Thread(new Receiver(incoming,this)).start();
        }
	}
}