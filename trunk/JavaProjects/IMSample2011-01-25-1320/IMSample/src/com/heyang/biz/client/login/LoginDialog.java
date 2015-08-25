package com.heyang.biz.client.login;

import java.awt.Color;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Map;
import java.util.Scanner;
import java.util.prefs.Preferences;

import javax.swing.JFrame;
import javax.swing.JLabel;

import org.apache.commons.codec.binary.Base64;

import com.heyang.base.dlg.BaseDialog;
import com.heyang.biz.client.ClientUtil;
import com.heyang.biz.client.userlist.ctrl.UserlistCtrl;
import com.heyang.common.cipher.IMMsgDecryptException;
import com.heyang.common.cipher.IMMsgDecrypter;
import com.heyang.common.cipher.IMMsgEncryptException;
import com.heyang.common.cipher.IMMsgEncrypter;
import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.RSASecurityCoder;
import com.heyang.common.gui.button.XuanButton;
import com.heyang.common.gui.intro.IntroPassword;
import com.heyang.common.gui.intro.IntroText;

/**
 * 用于登录的对话框
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-30 下午01:49:25
 * 修改时间：2010-12-30 下午01:49:25
 */
public class LoginDialog extends BaseDialog{
	private static final long serialVersionUID = 3750582058500482195L;
	
	// 消息显示标签
	private JLabel msgLbl;
	private IntroText nameTxt;// 姓名
	private IntroPassword pswdTxt;// 密码
	
	/**
	 * 构造函数
	 * @param titleText
	 * @param width
	 * @param height
	 */
	public LoginDialog(String titleText, int width, int height) {
		super(titleText, width, height);
	}

	@Override
	protected void addComponentsToCenterPanel() {
		msgLbl=new JLabel("欢迎您的登录");
		nameTxt=new IntroText("姓名:");
		nameTxt.setText("何杨");
		pswdTxt=new IntroPassword("密码:");
		pswdTxt.setText("123");
		
		// 取出保存的上次登录的用户名密码
		Preferences prefs = Preferences.userNodeForPackage(ClientUtil.class);
		nameTxt.setText(prefs.get(ClientUtil.LAST_LOGIN_USER, ""));
		pswdTxt.setText(prefs.get(ClientUtil.LAST_LOGIN_PSWD, ""));
		
		// 设定布局
		int gridx, gridy, gridwidth, gridheight, anchor, fill, ipadx, ipady;
		double weightx, weighty;
		GridBagConstraints c;
		Insets inset;
		GridBagLayout gridbag = new GridBagLayout();
		centerPanel.setLayout(gridbag);

		// 0,0
		gridx = 0;
		gridy = 0;
		gridwidth = 1;
		gridheight = 1;
		weightx = 1.00;
		weighty = 0.00;
		anchor = GridBagConstraints.CENTER;
		fill = GridBagConstraints.NONE;
		inset = new Insets(5, 0, 0, 0);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		gridbag.setConstraints(msgLbl, c);
		centerPanel.add(msgLbl);
		
		gridx = 0;// 1
		gridy = 1;// 1
		gridwidth = 1;
		gridheight = 1;
		weightx = 1.00;// 2
		weighty = 0.00;// 2
		anchor = GridBagConstraints.WEST;
		fill = GridBagConstraints.BOTH;
		inset = new Insets(5, 5, 0, 40);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		gridbag.setConstraints(nameTxt, c);// 3
		centerPanel.add(nameTxt);// 3
		
		gridx = 0;
		gridy = 2;
		gridwidth = 1;
		gridheight = 1;
		weightx = 1.00;
		weighty = 0.00;
		anchor = GridBagConstraints.WEST;
		fill = GridBagConstraints.BOTH;
		inset = new Insets(5, 5, 0, 40);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		gridbag.setConstraints(pswdTxt, c);
		centerPanel.add(pswdTxt);
		
		this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		this.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
	}
	
	protected void addComponentsToSouthPanel(){
		confirmButton=new XuanButton("登录");
		confirmButton.addActionListener(
			new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					handleConfirm();
				}
			}
		);
		southPanel.add(confirmButton);
		
		cancelButton=new XuanButton("注册");
		cancelButton.addActionListener(
			new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					handleCancel();
				}
			}
		);
		
		southPanel.add(cancelButton);
	}

	@Override
	protected void handleConfirm() {
		String name=nameTxt.getText().trim();
		String pswd=pswdTxt.getText().trim();
		
		if(name.length()<1){
			showAbnormalMsg("请输入用户名!");
			nameTxt.getRightComponent().requestFocus();
			return;
		}
		else{
			showNormalMsg("用户名检验通过.");
		}
		
		if(pswd.length()<1){
			showAbnormalMsg("请输入密码!");
			pswdTxt.getRightComponent().requestFocus();
			return;
		}
		else{
			showNormalMsg("密码检验通过.");
		}
		
		// 准备开始注册用户
		String response="";
		
		try{
			// 与服务器交互
			response=login(name,pswd);
		}
		catch(Exception e){
			showAbnormalMsg("登录出现异常,原因是"+e.getMessage()+".");
			e.printStackTrace();
			return;
		}
		
		try{
			// 分析返回的结果
			boolean success=false;
			Map<String,String> map=ClientUtil.parseResponse(response);
			success=map.get("status").equals("ok");
			
			if(success==true){
				showNormalMsg(map.get("msg"));
				this.dispose();
				
				// 将登录成功的用户名密码保存起来
				ClientUtil.setLogininedUser(name, pswd);
				
				// 将用户输入保存起来
				Preferences prefs = Preferences.userNodeForPackage(ClientUtil.class);
				prefs.put(ClientUtil.LAST_LOGIN_USER, name);
				prefs.put(ClientUtil.LAST_LOGIN_PSWD, pswd);
				
				// 显示客户端主框架
				//new ClientCtrl();
				new UserlistCtrl();
			}
			else{
				showAbnormalMsg(map.get("msg"));
				return;
			}
		}
		catch(Exception e){
			showAbnormalMsg("登录出现异常,原因是"+e.getMessage()+".");
			e.printStackTrace();
			return;
		}
	}
	
	protected void handleCancel(){
		new RegisterDialog("注册用户",300,200);
		
		this.dispose();
	}
	
	public void showNormalMsg(String text){
		msgLbl.setForeground(Color.black);
		msgLbl.setText(text);
	}
	
	public void showAbnormalMsg(String text){
		msgLbl.setForeground(Color.RED);
		msgLbl.setText(text);
	}
	
	private String login(String userName,String password) throws Exception{
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
        sb1.append("<command>login</command>");
        sb1.append("<username>"+userName+"</username>");
        sb1.append("<password>"+password+"</password>");
        
        // 得到可以监听的端口并记录下来
        int listenPort=findUnusedPort();
        ClientUtil.setListenPort(listenPort);
        
        sb1.append("<port>"+listenPort+"</port>");
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
	 * 找出本机一个未被使用的端口来
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-12-30 下午10:18:58
	 */
	private int findUnusedPort(){
		int port=8888;
		boolean isFind=false;
		
		do{
			try {
	            ServerSocket s=new ServerSocket(port);
	            s.setSoTimeout(100000);
	            
	            isFind=true;
	            s.close();
	            
	            return port;
			}
			catch(Exception ex){
				port++;
				continue;
			}
		}while(!isFind);
		
		
		return port;
	}
}