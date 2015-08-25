package com.heyang.biz.client.chat.view;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Toolkit;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;

import com.heyang.biz.client.ClientUtil;
import com.heyang.biz.server.view.InputTextPane;
import com.heyang.common.gui.button.XuanButton;
import com.heyang.util.ResourceUtil;

/**
 * Chat Window's View
 * @author heyang
 *
 */
public class ChatView extends JFrame{
	private static final long serialVersionUID = -5100794608937579830L;
	
	// 消息显示窗口
	private InputTextPane msgArea;
	
	// 要发送的消息文本框
	private JTextArea msgTxt;
	
	// 发送按钮
	private XuanButton sendBtn;
	
	// 分隔窗格
	private JSplitPane splitPanel;
	
	// 下方面板，作为三个组件的容器
	private JPanel downPanel;

	/**
	 * 构造函数
	 *
	 */
	public ChatView(){
		// 设置程序标题
		setTitle("聊天窗口 登录用户'"+ClientUtil.getLogininedUsername()+"' TCP客户端 作者：何杨(heyang78@gmail.com)");
		
		// 设置大小,位置
		setSizeAndCentralizeMe(800, 600);
		
		// 设置程序图标
		setIconImage(ResourceUtil.Program_Logo_Client);
				
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
		msgArea=new InputTextPane();
		
		msgTxt=new JTextArea("");
		sendBtn=new XuanButton("发送");
		JLabel lbl=new JLabel("请输入您的信息，按Ctrl+回车键发送");
		downPanel=new JPanel();
		downPanel.setLayout(new BorderLayout());
		downPanel.add(lbl,BorderLayout.NORTH);
		downPanel.add(new JScrollPane(msgTxt),BorderLayout.CENTER);
		Box hBox=Box.createHorizontalBox();
		hBox.setBorder(BorderFactory.createEmptyBorder(5, 0, 0, 0));
		hBox.add(Box.createHorizontalGlue());
		hBox.add(sendBtn);
		downPanel.add(hBox,BorderLayout.SOUTH);
		downPanel.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
		
		splitPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT,
				false, msgArea, downPanel);
		splitPanel.setDividerLocation(400);
		splitPanel.setOneTouchExpandable(true);
		splitPanel.setDividerSize(8);
		
		this.setLayout(new GridLayout(1,1,5,5));
		this.add(splitPanel);
		
		// 设定布局
		/*int gridx, gridy, gridwidth, gridheight, anchor, fill, ipadx, ipady;
		double weightx, weighty;
		GridBagConstraints c;
		Insets inset;
		GridBagLayout gridbag = new GridBagLayout();
		this.setLayout(gridbag);
		
		// 0,0
		gridx = 0;
		gridy = 0;
		gridwidth = 1;
		gridheight = 1;
		weightx = 1.00;
		weighty = 0.70;
		anchor = GridBagConstraints.CENTER;
		fill = GridBagConstraints.BOTH;
		inset = new Insets(5, 5, 0, 5);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		JScrollPane js=new JScrollPane(msgArea);
		gridbag.setConstraints(js, c);
		this.add(js);
		
		// 0,1
		gridx = 0;
		gridy = 1;
		gridwidth = 1;
		gridheight = 1;
		weightx = 1.00;
		weighty = 0.00;
		anchor = GridBagConstraints.CENTER;
		fill = GridBagConstraints.BOTH;
		inset = new Insets(5, 5, 0, 5);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		JLabel lbl=new JLabel("请输入您的信息，按回车发送");
		gridbag.setConstraints(lbl, c);
		this.add(lbl);
		
		// 0,1
		gridx = 0;
		gridy = 2;
		gridwidth = 1;
		gridheight = 1;
		weightx = 1.00;
		weighty = 0.30;
		anchor = GridBagConstraints.CENTER;
		fill = GridBagConstraints.BOTH;
		inset = new Insets(0, 5, 0, 5);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		JScrollPane js2=new JScrollPane(msgTxt);
		gridbag.setConstraints(js2, c);
		this.add(js2);
		
		// 2,1
		gridx = 0;
		gridy = 3;
		gridwidth = 1;
		gridheight = 1;
		weightx = 0.00;
		weighty = 0.00;
		anchor = GridBagConstraints.EAST;
		fill = GridBagConstraints.NONE;
		inset = new Insets(5, 5, 5, 5);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		gridbag.setConstraints(sendBtn, c);
		this.add(sendBtn);*/
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

	public InputTextPane getMsgArea() {
		return msgArea;
	}

	public JTextArea getMsgTxt() {
		return msgTxt;
	}

	public XuanButton getSendBtn() {
		return sendBtn;
	}
}