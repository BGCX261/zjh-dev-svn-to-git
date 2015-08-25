package com.heyang.common.gui.panel;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.net.MalformedURLException;
import java.net.URL;

import javax.swing.ImageIcon;

import com.heyang.base.panel.BasePanel;

/**
 * 用于显示图片的面板
 * 说明：
 * 作者：heyang(heyang78@gmail.com)
 * 创建时间：2010-2-24 上午08:17:17
 * 修改时间：2010-2-24 上午08:17:17
 */
public class PicturePanel extends BasePanel{
	private static final long serialVersionUID = 654654654L;
	
	// 边界颜色
	//private static Color BorderColor=new Color(30,54,90);

	// 用于展示图片
	private Image pictureImage=null;//ResourceUtil.SplashWindow_BackgroundImage;
	
	public PicturePanel(){
		setBackground(Color.white);
		//setBorder(BorderFactory.createLineBorder(BorderColor));
	}
	
	@Override
	public void paintComponent(Graphics g) {
		if(pictureImage!=null){
			g.drawImage(pictureImage, 0, 0, getWidth(), getHeight(), 0, 0, pictureImage
					.getWidth(null), pictureImage.getHeight(null), null);
		}
	}
	
	/**
	 * 用于显示本地图片
	 * 
	 * 说明：
	 * @param pictureImage
	 * 创建时间：2010-2-24 上午08:22:47
	 * 修改时间：2010-2-24 上午08:22:47
	 */
	public void showPicture(Image pictureImage){
		this.pictureImage=pictureImage;
		
		// 进行重绘
		repaint();
	}	
	
	/**
	 * 用于显示网络图片
	 * 
	 * 说明：
	 * @param pictureUrl
	 * 创建时间：2010-2-25 下午10:37:57
	 * 修改时间：2010-2-25 下午10:37:57
	 */
	public void showPicture(String pictureUrl){
		try {
			pictureImage= new ImageIcon(new URL(pictureUrl)).getImage();
			// 进行重绘
			repaint();
		} catch (MalformedURLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	@Override
	protected void addComponentListeners() {
		// do nothing
	}


	@Override
	protected void initComponents() {
		// do nothing
		
	}

	@Override
	protected void setLayoutAndAddComponents() {
		// do nothing
		
	}
}