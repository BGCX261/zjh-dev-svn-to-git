package com.heyang.biz.client.login;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.InputStream;
import java.io.InterruptedIOException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;
import java.util.prefs.Preferences;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.JFrame;
import javax.swing.JLabel;

import org.apache.commons.codec.binary.Base64;

import com.heyang.base.dlg.BaseDialog;
import com.heyang.biz.client.ClientUtil;
import com.heyang.common.gui.button.XuanButton;
import com.heyang.common.gui.intro.IntroText;

/**
 * 用于探测服务器IP和端口的对话框
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-30 下午01:49:25
 * 修改时间：2010-12-30 下午01:49:25
 */
public class ProbeDialog extends BaseDialog {
	

	private static final long serialVersionUID = 3750582058500482195L;

	// 消息显示标签
	private JLabel msgLbl;
	private IntroText serverIpTxt;// 服务器IP地址
	private IntroText serverPortTxt;// 服务器监听端口

	/**
	 * 构造函数
	 * @param titleText
	 * @param width
	 * @param height
	 */
	public ProbeDialog(String titleText, int width, int height) {
		super(titleText, width, height);
	}

	@Override
	protected void addComponentsToCenterPanel() {
		msgLbl = new JLabel("欢迎您使用IMClient");
		
		Dimension dm1=new Dimension(130,25);
		Dimension dm2=new Dimension(170,25);
		
		serverIpTxt = new IntroText("服务器IP地址:");
		serverIpTxt.setLeftDemension(dm1);
		serverIpTxt.setRightDemension(dm2);
		
		serverPortTxt = new IntroText("服务器监听端口:");
		serverPortTxt.setLeftDemension(dm1);
		serverPortTxt.setRightDemension(dm2);
		
		Preferences prefs = Preferences.userNodeForPackage(ClientUtil.class);

		serverIpTxt.setText(prefs.get(ClientUtil.LAST_SERVER_IP, "127.0.0.1"));
		serverPortTxt.setText(prefs.get(ClientUtil.LAST_SERVER_PORT, "8888"));

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
		gridbag.setConstraints(serverIpTxt, c);// 3
		centerPanel.add(serverIpTxt);// 3

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
		gridbag.setConstraints(serverPortTxt, c);
		centerPanel.add(serverPortTxt);

		this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		this.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
	}

	protected void addComponentsToSouthPanel() {
		confirmButton = new XuanButton("登录");
		confirmButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				handleConfirm();
			}
		});
		southPanel.add(confirmButton);

		cancelButton = new XuanButton("注册");
		cancelButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				handleCancel();
			}
		});

		southPanel.add(cancelButton);
	}

	/**
	 * 判断服务器是否存在，以取回服务器RSA公钥为标志
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-12-30 下午02:36:42
	 */
	private boolean isServerExist() {
		String serverIP = serverIpTxt.getText().trim();
		String serverPort = serverPortTxt.getText().trim();

		if (serverIP.length() < 1) {
			showAbnormalMsg("请输入服务器IP地址!");
			serverIpTxt.getRightComponent().requestFocus();
			return false;
		} else {
			showNormalMsg("服务器IP地址检验通过.");
		}

		if(isValidIpAddr(serverIP)==false){
			showAbnormalMsg("服务器IP地址不符合规范.");
			serverIpTxt.getRightComponent().requestFocus();
			return false;
		} else {
			showNormalMsg("服务器IP地址规范检验通过.");
		}

		if (serverPort.length() < 1) {
			showAbnormalMsg("请输入服务器监听端口!");
			serverPortTxt.getRightComponent().requestFocus();
			return false;
		} else {
			showNormalMsg("服务器监听端口检验通过.");
		}
		
		int port=0;
		
		try{
			port=Integer.parseInt(serverPort);
			
			if(port<1 || port>65535){
				showAbnormalMsg("监听端口必须在1到65535之间!");
				serverPortTxt.getRightComponent().requestFocus();
				return false;
			}
		}
		catch(Exception e){
			showAbnormalMsg("监听端口必须是整数!");
			serverPortTxt.getRightComponent().requestFocus();
			return false;
		}
		
		// 取得服务器公钥
		byte[] serverPublicKey=null;
		try{
			serverPublicKey=getPublicKey(serverIP,port);
			ClientUtil.setServerRSAPublicKey(serverPublicKey);
			ClientUtil.setServerIP(serverIP);
			ClientUtil.setServerPort(port);
			
			// 将用户输入保存起来
			Preferences prefs = Preferences.userNodeForPackage(ClientUtil.class);
			prefs.put(ClientUtil.LAST_SERVER_IP, serverIP);
			prefs.put(ClientUtil.LAST_SERVER_PORT, serverPort);
			
			return true;
		}
		catch(java.net.ConnectException e){
			showAbnormalMsg("无法与服务器建立连接.");
			return false;
		}
		catch(InterruptedIOException e){
			showAbnormalMsg("在与服务器建立连接时超过了指定的时间十秒.");
			return false;
		}
		catch(Exception e){
			showAbnormalMsg("取得服务器RSA公钥时发生异常，原因是："+e.getMessage()+".");
			e.printStackTrace();
			return false;
		}
	}
	
	/**
	 * 取得服务器端的公钥
	 * 
	 * 说明：
	 * @param serverIp
	 * @param port
	 * @return
	 * @throws Exception
	 * 创建时间：2010-12-30 下午03:15:32
	 */
	private byte[] getPublicKey(String serverIp,int port) throws Exception{
		Socket s=new Socket(serverIp,port);
		s.setSoTimeout(10000);// 设置十秒为超时时间
		
		InputStream  inStram=s.getInputStream();
        OutputStream outStream=s.getOutputStream();
        
        // 输出
        PrintWriter out=new PrintWriter(outStream,true);
        
        out.print("getPublicKey");
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
        
        byte[] arr=Base64.decodeBase64(response);
        
        s.close();
        return arr;
	}

	@Override
	protected void handleConfirm() {
		if (isServerExist()) {
			this.dispose();
			new LoginDialog("用户登录", 300, 200);
		}
	}

	protected void handleCancel() {
		if (isServerExist()) {
			this.dispose();
			new RegisterDialog("注册用户", 300, 200);
		}
	}

	public static boolean isValidIpAddr(String ipAddr) {
		String regx = "(\\d+).(\\d+).(\\d+).(\\d+)";

		if (Pattern.matches(regx, ipAddr)) {
			Pattern pattern = Pattern.compile(regx);

			Matcher mather = pattern.matcher(ipAddr);
			while (mather.find()) {
				for (int i = 1; i <= mather.groupCount(); i++) {
					String str = mather.group(i);

					int temp = Integer.parseInt(str);

					if (temp > 255 || temp < 0) {
						return false;
					}
				}
			}
		} else {
			return false;
		}

		return true;
	}

	public void showNormalMsg(String text) {
		msgLbl.setForeground(Color.black);
		msgLbl.setText(text);
	}

	public void showAbnormalMsg(String text) {
		msgLbl.setForeground(Color.RED);
		msgLbl.setText(text);
	}
}