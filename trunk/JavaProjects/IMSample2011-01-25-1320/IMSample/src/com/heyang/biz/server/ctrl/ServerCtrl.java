package com.heyang.biz.server.ctrl;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.IOException;
import java.net.BindException;
import java.net.SocketException;

import javax.swing.JFrame;

import com.heyang.base.mvc.BaseCtrl;
import com.heyang.biz.server.model.ServerModel;
import com.heyang.biz.server.view.ServerView;
import com.heyang.util.DlgUtil;

/**
 * MVC之控制
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-25 上午07:49:16
 * 修改时间：2010-12-25 上午07:49:16
 */
public class ServerCtrl extends BaseCtrl{
	// 视图指针
	private ServerView view;
	
	// 数据中心指针
	private ServerModel model;
	
	// 服务线程
	private Thread serviceThread;
	
	@Override
	protected void initialModelAndView() {
		// 实例化Model
		model=new ServerModel();
		
		// 实例化View
		view=new ServerView();
		
		view.showRegisteredUsers(model.getRegisteredUsers());
		
		// 设置对话框框架
		DlgUtil.setProgramFrame(view);
	}

	@Override
	public void addListeners() {
		view.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		view.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				model.saveUsersToFile();
				System.exit(0);
			}
		});
		
		view.getListenBtn().addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String strPort=view.getPortTxt().getText();
				int port=0;
				
				// 数字校验
				try{
					port=Integer.parseInt(strPort);
				}catch(Exception ex){
					view.showAbnormalMsg("端口必须是整数。");
					view.getPortTxt().getRightComponent().requestFocus();
					return;					
				}
				
				// 范围校验
				if(port<1 || port>65535){
					view.showAbnormalMsg("服务端口必须是1-65535之间的整数。");
					view.getPortTxt().getRightComponent().requestFocus();
					return;	
				}
				
				final int listenPort=port;
				serviceThread=new Thread(new Runnable(){
					public void run(){
						try {
							model.startLinsten(listenPort,view);
						} 
						catch (BindException e) {
							view.showAbnormalMsg("端口"+listenPort+"已经被占用.");
						}
						catch (SocketException e) {
							view.showAbnormalMsg("端口"+listenPort+"上的服务已经被停止.");
						}
						catch (IOException e) {
							view.showAbnormalMsg("开始监听时出现异常，原因是："+e.getMessage());
							e.printStackTrace();
						}
					}
				});
				serviceThread.start();
				
				view.getListenBtn().setEnabled(false);
				view.getStopListenBtn().setEnabled(true);
				view.showNormalMsg("开始服务");
			}
		});
		
		view.getStopListenBtn().addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 停止监听
				try{
					model.stopLinsten();
					System.out.println("服务停止.");
				}catch(Exception ex){
					
				}
				
				view.getStopListenBtn().setEnabled(false);
				view.getListenBtn().setEnabled(true);
				view.showAbnormalMsg("停止服务");
			}
		});
	}
	


	/***********************************
	 * 以下是getter/setter部分
	 ***********************************/
	public ServerView getView() {
		return view;
	}

	public ServerModel getModel() {
		return model;
	}
}