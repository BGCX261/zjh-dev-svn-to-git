package com.heyang.common.gui.button;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Image;
import java.awt.Insets;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.List;
import java.util.Vector;

import javax.swing.JLabel;
import javax.swing.JPanel;

import com.heyang.util.ResourceUtil;

/**
 * 具有鼠标感应效果的"炫"按钮
 * 
 * 说明：要修改请与何杨商议，切忌自行修改！
 * 创建人：何杨
 * 创建时间：2010-2-15 下午12:28:37
 * 
 * 修改人：何杨
 * 修改时间：2010-2-15 下午12:28:37
 */
public class XuanButton extends JPanel  implements MouseListener{
	private static final long serialVersionUID = 4213031476793725929L;
	
	// 鼠标移出时显示的图片
	private static final Image normalImage=ResourceUtil.XuanButton_NormalImage;
	
	// 鼠标移入时显示的图片
	private static final Image activeImage=ResourceUtil.XuanButton_ActiveImage;
	
	// 此引用指向以上图片之一
	private Image currImage;
	
	// 用于显示按钮文本的标签
	private JLabel textLbl;
	
	// 监听者列表
	private List<ActionListener> actionListenerList;
	
	/**
	 * 构造函数
	 * @param text
	 */
	public XuanButton(String text){
		// 实例化成员
		currImage=normalImage;
		textLbl=new JLabel(text);
		textLbl.setForeground(Color.black);
		actionListenerList=new Vector<ActionListener>();
		
		// 设定布局
		int gridx, gridy, gridwidth, gridheight, anchor, fill, ipadx, ipady;
		double weightx, weighty;
		GridBagConstraints c;
		Insets inset;
		GridBagLayout gridbag = new GridBagLayout();
		setLayout(gridbag);

		gridx = 0;// 1
		gridy = 0;// 1
		gridwidth = 1;
		gridheight = 1;
		weightx = 0.00;// 2
		weighty = 1.00;// 2
		anchor = GridBagConstraints.CENTER;
		fill = GridBagConstraints.NONE;
		inset = new Insets(0, 0, 0, 0);
		ipadx = 0;
		ipady = 0;
		c = new GridBagConstraints(gridx, gridy, gridwidth, gridheight,
				weightx, weighty, anchor, fill, inset, ipadx, ipady);
		gridbag.setConstraints(textLbl, c);// 3
		add(textLbl);// 3
		
		Dimension dm = new Dimension(72, 28);
		this.setMaximumSize(dm);
		this.setMinimumSize(dm);
		this.setPreferredSize(dm);
		this.setSize(dm);
		
		// 添加鼠标监听
		this.addMouseListener(this);
	}
	
	/**
	 * 重载此方法,重新绘制组件,在鼠标移入移出时会被调用
	 */
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		
		if(currImage!=null){
			g.drawImage(currImage, 0, 0, getWidth(), getHeight(), 0, 0, currImage
					.getWidth(null), currImage.getHeight(null), null);
		}
	}
	
	/**
	 * 添加事件监听器
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param actionListener
	 * 创建人：何杨 2010-2-15 下午12:32:11
	 * 修改人：何杨 2010-2-15 下午12:32:11
	 */
	public void addActionListener(ActionListener actionListener){
		actionListenerList.add(actionListener);
	}
	
	/**
	 * 鼠标进入时绘制成活动状态图片
	 */
	public void mouseEntered(MouseEvent e) {
		textLbl.setForeground(Color.white);
		currImage=activeImage;
		repaint();
	}

	/**
	 * 鼠标进出时绘制成正常状态图片
	 */
	public void mouseExited(MouseEvent e) {
		textLbl.setForeground(Color.black);
		currImage=normalImage;
		repaint();
	}
	
	public void mousePressed(MouseEvent e) {
		// do nothing
	}

	/**
	 * 在点击松开后通知所有监听者
	 */
	public void mouseReleased(MouseEvent e) {
		if(e.getButton()==1){
			for(ActionListener actionListener:actionListenerList){
				actionListener.actionPerformed(null);
			}
		}
	}

	public void mouseClicked(MouseEvent e) {
		// do nothing
	}
	
	/**
	 * 设置按钮的文本
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param text
	 * 创建人：何杨 2010-2-15 下午12:33:55
	 * 修改人：何杨 2010-2-15 下午12:33:55
	 */
	public void setText(String text){
		textLbl.setText(text);
	}
}