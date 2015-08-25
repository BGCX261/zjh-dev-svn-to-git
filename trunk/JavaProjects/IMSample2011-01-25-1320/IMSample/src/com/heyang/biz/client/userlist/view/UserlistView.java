package com.heyang.biz.client.userlist.view;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Toolkit;
import java.util.List;

import javax.swing.Box;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;

import com.heyang.biz.client.ClientUtil;
import com.heyang.common.gui.button.XuanButton;
import com.heyang.util.ResourceUtil;

/**
 * 用户列表窗口
 * @author heyang
 *
 */
public class UserlistView extends JFrame{
	private static final long serialVersionUID = -5100794608937579830L;
	
	// 用户列表
	private JList  userList;
	
	// 发送按钮
	private XuanButton chatBtn;
	
	// 刷新按钮
	private XuanButton refreshBtn;

	/**
	 * 构造函数
	 *
	 */
	public UserlistView(){
		// 设置程序标题
		setTitle("用户列表窗口 TCP客户端"+"登录用户'"+ClientUtil.getLogininedUsername()+"' 作者：何杨(heyang78@gmail.com)");
		
		// 设置大小并居中
		setSizeAndCentralizeMe(200, 400);
		
		// 设置程序图标
		setIconImage(ResourceUtil.Program_Logo_Client_Userlist);
				
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
		userList=new JList();
		userList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		// Dimension dm1=new Dimension(120,25);
		chatBtn=new XuanButton("聊天");
		refreshBtn=new XuanButton("刷新");
		
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
		gridwidth = 1;
		gridheight = 1;
		weightx = 1.00;
		weighty = 1.00;
		anchor = GridBagConstraints.CENTER;
		fill = GridBagConstraints.BOTH;
		inset = new Insets(5, 5, 0, 5);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		JScrollPane js=new JScrollPane(userList);
		gridbag.setConstraints(js, c);
		this.add(js);
		
		// 0,1
		gridx = 0;
		gridy = 1;
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
		
		Box hBox=Box.createHorizontalBox();
		hBox.add(refreshBtn);
		hBox.add(Box.createRigidArea(new Dimension(10,0)));
		hBox.add(chatBtn);
		
		gridbag.setConstraints(hBox, c);
		this.add(hBox);
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
	
	/**
	 * 显示注册用户名单
	 * @param userNameList
	 */
	public void showLoginUsers(List<String> userNameList){
		int selInx=userList.getSelectedIndex();
		
		String[] users=new String[userNameList.size()];
		
		for(int i=0;i<users.length;i++){
			users[i]=userNameList.get(i);
		}
		
		userList.setListData(users);
		
		userList.setSelectedIndex(selInx);
	}

	public XuanButton getChatBtn() {
		return chatBtn;
	}

	public JList getUserList() {
		return userList;
	}

	public XuanButton getRefreshBtn() {
		return refreshBtn;
	}
}