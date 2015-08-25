package com.heyang.biz.client;

import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;

import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.RSASecurityCoder;


/**
 * 客户端实用工具类
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-30 下午02:25:01
 * 修改时间：2010-12-30 下午02:25:01
 */
public class ClientUtil{
	// 准备在监听的端口，用来接收服务器转发过来的信息
	private static int listenPort;
	
	// 登录成功的用户名
	private static String logininedUsername="";
	
	// 登录成功的用户密码
	private static String logininedPassword="";
	
	/**
	 * 设置登录成功的用户名和密码
	 * 
	 * 说明：
	 * @param name
	 * @param pswd
	 * 创建时间：2010-12-30 下午09:39:39
	 */
	public static void setLogininedUser(String name,String pswd){
		logininedUsername=name;
		logininedPassword=pswd;
	}
	
	// 上次登录进来的用户名
	public static final String LAST_LOGIN_USER = "LAST_LOGIN_USER";

	// 上次登录进来的密码
	public static final String LAST_LOGIN_PSWD = "LAST_LOGIN_PSWD";
	
	// 上次测试通过的端口
	public static final String LAST_SERVER_PORT = "Last_Server_Port";

	// 上次测试通过的IP地址
	public static final String LAST_SERVER_IP = "Last_Server_IP";
	
	// 用于RSA加密解密的编码器
	private static  RSASecurityCoder rsaCoder;
	
	// 用于AES加密解密的编码器
	private static  AESSecurityCoder aesCoder;
	
	// 服务器端RSA公钥
	private static byte[] serverRSAPublicKey;
	
	// 服务器Ip
	private static String serverIP;
	
	// 服务器端口
	private static int serverPort;
	
	static{
		try {
			rsaCoder=new RSASecurityCoder();
			aesCoder=new AESSecurityCoder();
			
		} catch (Exception e) {
			System.out.println("无法加载RSA或AES编码器，原因为"+e.getMessage());
			e.printStackTrace();
		}
	}
	
	/**
	 * 解析从服务器返回的XML文本
	 * 
	 * 说明：
	 * @param responseXML
	 * @return
	 * @throws Exception
	 * 创建时间：2010-12-30 下午08:36:22
	 */
	public static Map<String,String> parseResponse(String responseXML) throws Exception{
    	Document doc=DocumentHelper.parseText(responseXML);		
    	Element root=doc.getRootElement();
    	
    	/*if(!root.getName().equals("response")){
    		throw new Exception("根节点不合法");
    	}*/
    	
    	Map<String,String> retvalMap=new HashMap<String,String>();
    	List<?> nodes = root.elements();

    	for (Iterator<?> it = nodes.iterator(); it.hasNext();) {
    	   Element elm = (Element) it.next();

    	   retvalMap.put(elm.getName(), elm.getText());
    	}
    	
    	return retvalMap;
    }

	public static RSASecurityCoder getRsaCoder() {
		return rsaCoder;
	}

	public static AESSecurityCoder getAesCoder() {
		return aesCoder;
	}

	public static byte[] getServerRSAPublicKey() {
		return serverRSAPublicKey;
	}

	public static void setServerRSAPublicKey(byte[] serverRSAPublicKey) {
		ClientUtil.serverRSAPublicKey = serverRSAPublicKey;
	}

	public static String getServerIP() {
		return serverIP;
	}

	public static void setServerIP(String serverIP) {
		ClientUtil.serverIP = serverIP;
	}

	public static int getServerPort() {
		return serverPort;
	}

	public static void setServerPort(int serverPort) {
		ClientUtil.serverPort = serverPort;
	}

	public static String getLogininedUsername() {
		return logininedUsername;
	}

	public static String getLogininedPassword() {
		return logininedPassword;
	}

	public static int getListenPort() {
		return listenPort;
	}

	public static void setListenPort(int listenPort) {
		ClientUtil.listenPort = listenPort;
	}
}