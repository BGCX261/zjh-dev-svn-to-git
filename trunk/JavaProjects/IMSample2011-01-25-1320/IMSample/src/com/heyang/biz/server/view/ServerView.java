package com.heyang.biz.server.view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Toolkit;

import javax.swing.Box;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;

import com.heyang.common.gui.intro.IntroText;
import com.heyang.util.ResourceUtil;

/**
 * MVC之视图
 * 
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-25 上午07:48:39
 * 修改时间：2010-12-25 上午07:48:39
 */
public class ServerView extends JFrame{
	private static final long serialVersionUID = -5100794608937579830L;
	
	// 消息显示标签
	private JLabel msgLbl;
	
	// 监听端口
	private IntroText portTxt;
	
	// 开始监听按钮
	private JButton listenBtn;
	
	// 停止监听按钮
	private JButton stopListenBtn;
	
	// 容纳消息窗口和用户列表的分割窗格
	private JSplitPane splitPane;
	
	// 消息显示窗口
	private InputTextPane msgArea;
	
	// 用户列表
	private JList  userList;
	
	// 已登录用户列表
	private JList loginnedUserList;
	
	// 容纳上面两个列表的垂直分隔窗格
	private JSplitPane vsplitPane;

	/**
	 * 构造函数
	 *
	 */
	public ServerView(){
		// 设置程序标题
		setTitle("TCP服务器端 作者：何杨(heyang78@gmail.com)");
		
		// 设置大小,位置
		setSizeAndCentralizeMe(600, 600);
		
		// 设置程序图标
		setIconImage(ResourceUtil.Program_Logo_Server);
				
		// 初始化子组件
		initComponents();
		
		// 点击窗口右上角的关闭按钮关闭窗口,直接退出程序
		// this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// 显示自己
		setVisible(true);
	}
	
	/**
	 * 初始化子组件,设定布局
	 */
	private void initComponents() {
		msgLbl=new JLabel("消息显示");
		
		Dimension dm1=new Dimension(80,25);
		Dimension dm2=new Dimension(60,25);
		portTxt=new IntroText("服务端口:");
		portTxt.setText("8888");
		portTxt.setLeftDemension(dm1);
		portTxt.setRightDemension(dm2);
		
		listenBtn=new JButton("开始服务");
		stopListenBtn=new JButton("停止服务");
		stopListenBtn.setEnabled(false);
		
		msgArea=new InputTextPane();
		userList=new JList();
		loginnedUserList=new JList();
		
		vsplitPane= new JSplitPane(JSplitPane.VERTICAL_SPLIT,
				false, new JScrollPane(userList), new JScrollPane(loginnedUserList));
		vsplitPane.setDividerLocation(200);
		vsplitPane.setOneTouchExpandable(true);
		vsplitPane.setDividerSize(10);
		
		// 创建分隔窗口
		splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,
				false, new JScrollPane(msgArea), vsplitPane);
		splitPane.setDividerLocation(280);
		splitPane.setOneTouchExpandable(true);
		splitPane.setDividerSize(10);
		
		// 设定布局
		int gridx, gridy, gridwidth, gridheight, anchor, fill, ipadx, ipady;
		double weightx, weighty;
		GridBagConstraints c;
		Insets inset;
		GridBagLayout gridbag = new GridBagLayout();
		this.setLayout(gridbag);
		
		// 0,0
		gridx = 0;
		gridy = 0;
		gridwidth = 2;
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
		this.add(msgLbl);
		
		Box hBox=Box.createHorizontalBox();
		hBox.add(portTxt);
		hBox.add(Box.createRigidArea(new Dimension(10,0)));
		hBox.add(listenBtn);
		hBox.add(Box.createRigidArea(new Dimension(10,0)));
		hBox.add(stopListenBtn);
		
		// 0,1
		gridx = 0;
		gridy = 1;
		gridwidth = 2;
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
		gridbag.setConstraints(hBox, c);
		this.add(hBox);
		
		// 0,2
		gridx = 0;
		gridy = 2;
		gridwidth = 1;
		gridheight = 1;
		weightx = 0.00;
		weighty = 0.00;
		anchor = GridBagConstraints.WEST;
		fill = GridBagConstraints.NONE;
		inset = new Insets(5, 5, 0, 0);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		JLabel lb1=new JLabel("消息显示区");
		gridbag.setConstraints(lb1, c);
		this.add(lb1);
		
		// 1,2
		gridx = 1;
		gridy = 2;
		gridwidth = 1;
		gridheight = 1;
		weightx = 0.00;
		weighty = 0.00;
		anchor = GridBagConstraints.EAST;
		fill = GridBagConstraints.NONE;
		inset = new Insets(5, 0, 0, 5);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		JLabel lb2=new JLabel("注册用户列表/登录用户列表");
		gridbag.setConstraints(lb2, c);
		this.add(lb2);
		
		// 0,3
		gridx = 0;
		gridy = 3;
		gridwidth = 2;
		gridheight = 1;
		weightx = 1.00;
		weighty = 1.00;
		anchor = GridBagConstraints.CENTER;
		fill = GridBagConstraints.BOTH;
		inset = new Insets(5, 5, 5, 5);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		gridbag.setConstraints(splitPane, c);
		this.add(splitPane);
	}
	
	/**
	 * 设置程序大小并定位程序在屏幕正中
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param width
	 * @param height
	 * 创建人：何杨 2010-2-12 下午11:40:50
	 * 修改人：何杨 2010-2-12 下午11:40:50
	 */
	private void setSizeAndCentralizeMe(int width, int height) {
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		this.setSize(width, height);
		this.setLocation(screenSize.width / 2 - width / 2, screenSize.height
				/ 2 - height / 2);
	}
	
	public void showNormalMsg(String text){
		msgLbl.setForeground(Color.black);
		msgLbl.setText(text);
	}
	
	public void showAbnormalMsg(String text){
		msgLbl.setForeground(Color.RED);
		msgLbl.setText(text);
	}
	
	// 显示注册用户
	public void showRegisteredUsers(Object[] users){
		userList.setListData(users);
	}
	
	// 显示登录用户
	public void showLoginnededUsers(Object[] users){
		loginnedUserList.setListData(users);
	}

	public JLabel getMsgLbl() {
		return msgLbl;
	}

	public IntroText getPortTxt() {
		return portTxt;
	}

	public JButton getListenBtn() {
		return listenBtn;
	}

	public JButton getStopListenBtn() {
		return stopListenBtn;
	}

	public InputTextPane getMsgArea() {
		return msgArea;
	}

	public JList getUserList() {
		return userList;
	}

	public JList getLoginnedUserList() {
		return loginnedUserList;
	}
}