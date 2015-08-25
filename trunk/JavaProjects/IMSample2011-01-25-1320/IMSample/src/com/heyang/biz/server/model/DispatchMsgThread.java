package com.heyang.biz.server.model;

import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;

import com.heyang.common.cipher.IMMsgEncryptException;
import com.heyang.common.cipher.IMMsgEncrypter;
import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.RSASecurityCoder;


/**
 * 向第三方转发消息的线程
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-28 下午10:22:18
 * 修改时间：2010-12-28 下午10:22:18
 */
public class DispatchMsgThread extends Thread{
	// 消息来源的用户名
	private String fromUserName;
	
	// 消息目的地的用户
	private LoginUser user;
	
	// 要转发的消息
	private String msg;
	
	// 服务器RSA编码器
	private RSASecurityCoder rsaCoder;
	
	// 服务器AES编码器
	private AESSecurityCoder aesCoder;
	
	/**
	 * 构造函数
	 * @param fromUserName
	 * @param user
	 * @param msg
	 * @param rsaCoder
	 * @param aesCoder
	 */
	public DispatchMsgThread(String fromUserName,LoginUser user,String msg,RSASecurityCoder rsaCoder,AESSecurityCoder aesCoder){
		this.fromUserName=fromUserName;
		this.user=user;
		this.msg=msg;
		this.rsaCoder=rsaCoder;
		this.aesCoder=aesCoder;
	}
	
	public void run(){
		try{
			Socket s=new Socket(user.getIp(),user.getPort());
			
	        OutputStream outStream=s.getOutputStream();
	        
	        // 输出
	        PrintWriter out=new PrintWriter(outStream,true);
	        
	        // 待加密的明文
	        StringBuilder sb1=new StringBuilder();
	        sb1.append("<dispatch>");
	        sb1.append("<from>"+fromUserName+"</from>");
	        sb1.append("<to>"+user.getName()+"</to>");
	        sb1.append("<msg>"+msg+"</msg>");
	        sb1.append("</dispatch>");
	        String plainText=sb1.toString();
	        
	        String dispatchMsg="";
	        try{
	    		// 加密过程
	    		IMMsgEncrypter encrypter=new IMMsgEncrypter(plainText,user.getRsaPublicKey(),rsaCoder,aesCoder);
	    		dispatchMsg=encrypter.getCipheredMsg();
	    	}
	    	catch(IMMsgEncryptException e){
	    		System.out.println("无法对客户端请求进行加密");
	    		e.printStackTrace();
	    		//view.getMsgArea().insertRedMsg("无法加密客户要求服务器转发的文本'"+plainText+"'",fromUserName);
	    	}
	      
	        out.print(dispatchMsg);
	        out.flush();
	        s.shutdownOutput();// 输出结束
	        s.close();
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}
}