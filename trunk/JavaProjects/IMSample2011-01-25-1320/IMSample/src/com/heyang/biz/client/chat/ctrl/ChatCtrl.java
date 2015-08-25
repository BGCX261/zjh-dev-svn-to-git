package com.heyang.biz.client.chat.ctrl;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Map;
import java.util.Scanner;

import javax.swing.JFrame;

import org.apache.commons.codec.binary.Base64;
import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;

import com.heyang.base.mvc.BaseCtrl;
import com.heyang.biz.client.ClientUtil;
import com.heyang.biz.client.chat.model.ChatModel;
import com.heyang.biz.client.chat.view.ChatView;
import com.heyang.common.cipher.IMMsgDecryptException;
import com.heyang.common.cipher.IMMsgDecrypter;
import com.heyang.common.cipher.IMMsgEncryptException;
import com.heyang.common.cipher.IMMsgEncrypter;
import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.RSASecurityCoder;
import com.heyang.util.DlgUtil;

/**
 * Chat Window's Controller
 * @author heyang
 *
 */
public class ChatCtrl extends BaseCtrl{
	// 视图指针
	private ChatView view;
	
	// 数据中心指针
	private ChatModel model;
	
	@Override
	protected void initialModelAndView() {
		// 实例化Model
		model=new ChatModel();
		
		// 实例化View
		view=new ChatView();
	}

	@Override
	public void addListeners() {
		view.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		view.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				model.removeMydataInUserlistWondow();
				view.dispose();
			}
		});
		
		
		// 准备发送信息
		view.getSendBtn().addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				sendMsg();
			}
		});
		
		view.getMsgTxt().addKeyListener(new KeyListener(){
			@Override
			public void keyReleased(KeyEvent arg0) {
				 if ( arg0.getKeyCode() == KeyEvent.VK_ENTER && 
					((arg0.getModifiersEx() & KeyEvent.CTRL_DOWN_MASK) != 0) && 
					((arg0.getModifiersEx() & KeyEvent.SHIFT_DOWN_MASK) == 0)   ) {
					 sendMsg();
					 view.getMsgTxt().setText("");
				 }
			}
			
			@Override
			public void keyPressed(KeyEvent arg0) {
				// do nothing
				
			}

			@Override
			public void keyTyped(KeyEvent arg0) {
				// do nothing
				
			}
		});
	}
	
	private void sendMsg(){
		String msg=view.getMsgTxt().getText();
		
		if(msg.trim().length()<1){
			// DlgUtil.popupMessageDialog("请输入您要发送的文字");
			view.getMsgTxt().requestFocus();
			return;
		}
		
		String toUserName=model.getOpponentName();
		
		String response="";
		try{
			response=sendMsg(msg,toUserName);
			
			view.getMsgArea().insertSendMsg(msg, toUserName);
		}catch(Exception ex){
			ex.printStackTrace();
			DlgUtil.popupErrorDialog("发送消息时发生异常,原因是"+ex.getMessage()+".");
		}
		
		try{
			// 分析返回的结果
			boolean success=false;
			Map<String,String> map=ClientUtil.parseResponse(response);
			success=map.get("status").equals("ok");
			
			if(success==true){
				// view.getMsgArea().insertDispatchMsg(msg+"已经被服务器转发", ClientUtil.getServerIP());
			}
			else{
				view.getMsgArea().insertRedMsg(msg+"无法被服务器转发,原因是"+map.get("msg"), ClientUtil.getServerIP());
				return;
			}
		}
		catch(Exception ex){
			DlgUtil.popupErrorDialog("发送消息时发生异常,原因是"+ex.getMessage()+".");
			ex.printStackTrace();
			return;
		}
	}
	
	/**
	 * 发送信息，通过Server转发
	 * 
	 * 说明：
	 * @param msg
	 * @param toUserName
	 * 创建时间：2010-12-30 下午11:35:16
	 */
	public String sendMsg(String msg,String toUserName) throws Exception{
		RSASecurityCoder rsaCoder=ClientUtil.getRsaCoder();
		byte[] serverPublicKey=ClientUtil.getServerRSAPublicKey();
		AESSecurityCoder aesCoder=ClientUtil.getAesCoder();
		
		Socket s=new Socket(ClientUtil.getServerIP(),ClientUtil.getServerPort());
		
		InputStream  inStram=s.getInputStream();
        OutputStream outStream=s.getOutputStream();
        
        // 输出
        PrintWriter out=new PrintWriter(outStream,true);
        
        // 待加密的明文
        /*StringBuilder sb1=new StringBuilder();
        sb1.append("<request>");
        sb1.append("<command>dispatch</command>");
        sb1.append("<username>"+ClientUtil.getLogininedUsername()+"</username>");
        sb1.append("<password>"+ClientUtil.getLogininedPassword()+"</password>");
        sb1.append("<to>"+toUserName+"</to>");
        sb1.append("<msg>"+UTF8Coder.encode(msg)+"</msg>");
        sb1.append("</request>");
        String plainText=sb1.toString();*/
        
        String plainText=generateDispatchXml(ClientUtil.getLogininedUsername(),ClientUtil.getLogininedPassword(),toUserName,msg);
        
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
	 * 生成分发的XML
	 * @param username
	 * @param password
	 * @param to
	 * @param msg
	 * @return
	 */
	private String generateDispatchXml(String username,String password,String to,String msg){
		Document document = DocumentHelper.createDocument();
        Element root = document.addElement("request");// 创建根节点
		
        root.addElement("command").setText("dispatch");
        root.addElement("username").setText(username);
        root.addElement("password").setText(password);
        root.addElement("to").setText(to);
        root.addElement("msg").addCDATA(msg);
        
		
		return document.asXML();
	}

	/***********************************
	 * 以下是getter/setter部分
	 ***********************************/
	public ChatView getView() {
		return view;
	}

	public ChatModel getModel() {
		return model;
	}
}