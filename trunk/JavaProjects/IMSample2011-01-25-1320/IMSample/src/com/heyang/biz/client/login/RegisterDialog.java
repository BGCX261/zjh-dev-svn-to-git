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
import java.net.Socket;
import java.util.Map;
import java.util.Scanner;

import javax.swing.JFrame;
import javax.swing.JLabel;

import org.apache.commons.codec.binary.Base64;

import com.heyang.base.dlg.BaseDialog;
import com.heyang.biz.client.ClientUtil;
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
 * 用于注册的对话框
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-30 下午01:49:25
 * 修改时间：2010-12-30 下午01:49:25
 */
public class RegisterDialog extends BaseDialog{
	private static final long serialVersionUID = 3750582058500482195L;
	
	// 消息显示标签
	private JLabel msgLbl;
	private IntroText nameTxt;// 姓名
	private IntroPassword pswdTxt;// 密码
	private IntroPassword repswdTxt;// 再次输入密码
	
	/**
	 * 构造函数
	 * @param titleText
	 * @param width
	 * @param height
	 */
	public RegisterDialog(String titleText, int width, int height) {
		super(titleText, width, height);
	}

	@Override
	protected void addComponentsToCenterPanel() {
		msgLbl=new JLabel("欢迎您的注册");
		nameTxt=new IntroText("姓名:");
		pswdTxt=new IntroPassword("密码:");
		repswdTxt=new IntroPassword("重复密码:");
		
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
		
		gridx = 0;
		gridy = 3;
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
		gridbag.setConstraints(repswdTxt, c);
		centerPanel.add(repswdTxt);
		
		
		this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		this.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
	}
	
	protected void addComponentsToSouthPanel(){
		confirmButton=new XuanButton("注册");
		confirmButton.addActionListener(
			new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					handleConfirm();
				}
			}
		);
		southPanel.add(confirmButton);
		
		cancelButton=new XuanButton("退出");
		cancelButton.addActionListener(
			new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					System.exit(0);
				}
			}
		);
		
		southPanel.add(cancelButton);
	}

	@Override
	protected void handleConfirm() {
		String name=nameTxt.getText().trim();
		String pswd=pswdTxt.getText().trim();
		String repswd=repswdTxt.getText().trim();
		
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
		
		if(repswd.equals(pswd)==false){
			showAbnormalMsg("两次密码内容必须一致!");
			repswdTxt.getRightComponent().requestFocus();
			return;
		}
		else{
			showNormalMsg("二次密码检验通过.");
		}
		
		// 准备开始注册用户
		String response="";
		
		try{
			// 与服务器交互
			response=register(name,pswd);
		}
		catch(Exception e){
			showAbnormalMsg("注册出现异常,原因是"+e.getMessage()+".");
			e.printStackTrace();
			return;
		}
		
		try{
			// 分析返回的结果
			boolean success=false;
			Map<String,String> map=ClientUtil.parseResponse(response);
			success=map.get("status").equals("ok");
			
			if(success==true){
				this.dispose();
				new LoginDialog("用户登录", 300, 200);
			}
			else{
				showAbnormalMsg(map.get("msg"));
				return;
			}
		}
		catch(Exception e){
			showAbnormalMsg("注册出现异常,原因是"+e.getMessage()+".");
			e.printStackTrace();
			return;
		}
	}
	
	public void showNormalMsg(String text){
		msgLbl.setForeground(Color.black);
		msgLbl.setText(text);
	}
	
	public void showAbnormalMsg(String text){
		msgLbl.setForeground(Color.RED);
		msgLbl.setText(text);
	}
	
	/**
	 * 注册用户，返回的是服务器端返回的XML文本内容
	 * 
	 * 说明：
	 * @param userName
	 * @param password
	 * @return
	 * @throws Exception
	 * 创建时间：2010-12-30 下午08:38:32
	 */
	private String register(String userName,String password) throws Exception{
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
        sb1.append("<command>register</command>");
        sb1.append("<username>"+userName+"</username>");
        sb1.append("<password>"+password+"</password>");
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
}