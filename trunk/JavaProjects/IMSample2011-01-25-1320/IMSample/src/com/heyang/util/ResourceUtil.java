package com.heyang.util;

import java.awt.Image;

import javax.swing.ImageIcon;

/**
 * 保存图片等资源的实用工具类
 * 凡是在程序中用到的资源都应该在这里注册,
 * 此文件中注册的资源必须与res目录中一致.
 * 
 * 说明：这个类可以根据自己的需要修改,但必须遵守编程规约且动别人代码前需要和别人商议,而且每个资源要说明用途,添加人,添加时间.
 * 创建人：何杨
 * 创建时间：2010-2-12 下午12:53:18
 * 
 * 修改人：何杨
 * 修改时间：2010-2-12 下午12:53:18
 */
public final class ResourceUtil{
	// 炫按钮使用的鼠标进入时状态图片，何杨添加，2010年2月14日22:52:17
	public static final Image XuanButton_NormalImage=new ImageIcon(ResourceUtil.class.getResource("/xuanbutton_normal.gif")).getImage();
	
	// 炫按钮使用的鼠标移出时状态图片，何杨添加，2010年2月14日22:52:17
	public static final Image XuanButton_ActiveImage=new ImageIcon(ResourceUtil.class.getResource("/xuanbutton_active.gif")).getImage();

	// 程序logo图片，何杨添加，2010年2月12日23:23:29
	public static final Image Program_Logo_Server= new ImageIcon( ResourceUtil.class.getResource("/server.gif")).getImage();
	public static final Image Program_Logo_Client= new ImageIcon( ResourceUtil.class.getResource("/client.gif")).getImage();
	public static final Image Program_Logo_Client_Userlist= new ImageIcon( ResourceUtil.class.getResource("/userlist.gif")).getImage();
}