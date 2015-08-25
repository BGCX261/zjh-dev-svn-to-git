package com.heyang.biz.client.userlist.ctrl;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.BindException;
import java.net.Socket;
import java.util.Map;
import java.util.Scanner;

import javax.swing.JFrame;

import org.apache.commons.codec.binary.Base64;

import com.heyang.base.mvc.BaseCtrl;
import com.heyang.biz.client.ClientUtil;
import com.heyang.biz.client.chat.ctrl.ChatCtrl;
import com.heyang.biz.client.userlist.model.UserlistModel;
import com.heyang.biz.client.userlist.view.UserlistView;
import com.heyang.common.cipher.IMMsgDecryptException;
import com.heyang.common.cipher.IMMsgDecrypter;
import com.heyang.common.cipher.IMMsgEncryptException;
import com.heyang.common.cipher.IMMsgEncrypter;
import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.RSASecurityCoder;
import com.heyang.util.DlgUtil;

/**
 * User List Window's Control Center
 * @author heyang
 *
 */
public class UserlistCtrl extends BaseCtrl{
	// 视图指针
	private UserlistView view;
	
	// 数据中心指针
	private UserlistModel model;
	
	// 服务线程
	private Thread listenThread;
	
	@Override
	protected void initialModelAndView() {
		// 实例化Model
		model=new UserlistModel();
		
		// 实例化View
		view=new UserlistView();
		
		// 自动更新用户列表
		new Thread(new Runnable(){
			public void run(){
				while(true){
					//userList.setListData
					view.showLoginUsers(model.getLoginnedUsers());

					try {
						Thread.sleep(1000);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
		}).start();
		
		// 设置对话框框架
		DlgUtil.setProgramFrame(view);
		
		listenThread=new Thread(new Runnable(){
			public void run(){
				startListen();
			}
		});
		listenThread.start();
	}
	
	private void startListen(){
		try {
			model.startListen(view);
		} 
		catch (BindException e) {
			DlgUtil.popupWarningDialog("端口"+ClientUtil.getListenPort()+"已经被占用");
			e.printStackTrace();
		}
		catch (IOException e) {
			DlgUtil.popupWarningDialog("客户端在"+ClientUtil.getListenPort()+"进行监听时发生异常，原因是"+e.getMessage()+".");
			e.printStackTrace();
		}
	}

	@Override
	public void addListeners() {
		view.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		view.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				try{
					// 与服务器交互
					String response=logout();
					
					boolean success=false;
					Map<String,String> map=ClientUtil.parseResponse(response);
					success=map.get("status").equals("ok");
					
					if(success==true){
					}
					else{
					}
				}
				catch(Exception ex){
					ex.printStackTrace();
					return;
				}
				finally{
					System.exit(0);
				}
			}
		});
		
		// 准备聊天
		view.getChatBtn().addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String opponentName=(String)view.getUserList().getSelectedValue();
				
				if(opponentName==null){
					DlgUtil.popupMessageDialog("请选择您要与之聊天的用户.");
					return;
				}
				else if(ClientUtil.getLogininedUsername().equals(opponentName)){
					DlgUtil.popupWarningDialog("与自己有什么好聊的呢!");
					return;
				}
				else{
					ChatCtrl ctrl=model.addOrActiveChatWindow(opponentName);
					ctrl.getView().setExtendedState(JFrame.NORMAL);
					ctrl.getView().toFront();
				}
				//System.out.print(opponentName);
			}
		});
		
		view.getUserList().addMouseListener(new MouseAdapter() {
			public void mouseReleased(MouseEvent e) {
	        	System.out.println(e.getClickCount());
	        	
	        	if(e.getClickCount() == 2){
	        		String opponentName=(String)view.getUserList().getSelectedValue();
	        		
	        		if(opponentName!=null && ClientUtil.getLogininedUsername().equals(opponentName)==false){
	        			ChatCtrl ctrl=model.addOrActiveChatWindow(opponentName);
						ctrl.getView().setExtendedState(JFrame.NORMAL);
						ctrl.getView().toFront();
	        		}
	        	}
	        }
		});
		
		// 刷新用户列表
		view.getRefreshBtn().addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				view.showLoginUsers(model.getLoginnedUsers());
			}
		});
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
        StringBuilder sb1=new StringBuilder();
        sb1.append("<request>");
        sb1.append("<command>dispatch</command>");
        sb1.append("<username>"+ClientUtil.getLogininedUsername()+"</username>");
        sb1.append("<password>"+ClientUtil.getLogininedPassword()+"</password>");
        sb1.append("<to>"+toUserName+"</to>");
        sb1.append("<msg>"+msg+"</msg>");
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
	 * 通知服务器登出动作
	 * 
	 * 说明：
	 * 创建时间：2010-12-30 下午09:35:41
	 */
	private String logout() throws Exception{
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
        sb1.append("<command>logout</command>");
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

	/***********************************
	 * 以下是getter/setter部分
	 ***********************************/
	public UserlistView getView() {
		return view;
	}

	public UserlistModel getModel() {
		return model;
	}
}