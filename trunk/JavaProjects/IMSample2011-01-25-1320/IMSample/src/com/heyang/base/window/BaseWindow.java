package com.heyang.base.window;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Box;
import javax.swing.JFrame;
import javax.swing.JPanel;

import com.heyang.common.gui.button.XuanButton;

/**
 * 窗口基类
 * 此类作为登录窗口，展示窗口等类的基类。
 * 说明：
 * 作者：heyang(heyang78@gmail.com)
 * 创建时间：2010-2-22 下午03:24:13
 * 修改时间：2010-2-22 下午03:24:13
 */
public abstract class BaseWindow extends JFrame{
	private static final long serialVersionUID = -1459439635286038892L;
	
	// 中心面板,用户组件都放在这里
	protected JPanel centerPanel;
	
	// 南侧面板,按钮放在这里
	protected JPanel southPanel;
	
	// 确认按钮
	protected XuanButton confirmButton;
	
	// 取消按钮
	protected XuanButton cancelButton;
	
	/**
	 * 构造函数
	 * @param titleText
	 */
	public BaseWindow(String titleText,int width,int height){
		super(titleText);
		
		this.setAlwaysOnTop(true);
    	this.setResizable(false);
    	this.setUndecorated(true);
		
		centerPanel=new JPanel();
		addComponentsToCenterPanel();
		
		southPanel=new JPanel();
		addComponentsToSouthPanel();
		setButtonText();
		
		this.setLayout(new BorderLayout());
		this.add(centerPanel,BorderLayout.CENTER);
		this.add(southPanel,BorderLayout.SOUTH);
		
		setWindowSize(width,height);
		setVisible(true);
	}
	
	/**
	 * 将组件添加到中心面板
	 * 这是用户应该覆写的方法,你可以在其中实例化你自己的组件并把它们添加到中心面板上去
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * 创建人：何杨 2010-2-17 上午12:48:25
	 * 修改人：何杨 2010-2-17 上午12:48:25
	 */
	protected abstract void addComponentsToCenterPanel();
	
	/**
	 * 将组件添加到南侧面板
	 * 如果需要的对话框中有确认和取消按钮,请不要覆写此方法.
	 * 如果只有一个按钮,请屏蔽掉你不需要的部分
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * 创建人：何杨 2010-2-17 上午12:50:19
	 * 修改人：何杨 2010-2-17 上午12:50:19
	 */
	protected void addComponentsToSouthPanel(){
		confirmButton=new XuanButton("确认");
		
		cancelButton=new XuanButton("取消");
		cancelButton.addActionListener(
			new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					handleCancel();
				}
			}
		);
		
		southPanel.add(confirmButton);
		southPanel.add(Box.createRigidArea(new Dimension(5, 0)));
		southPanel.add(cancelButton);
	}
	
	/**
	 * 按下取消按钮后的事件处理,一般来说用户不需要覆写此方法
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * 创建人：何杨 2010-2-17 上午01:00:09
	 * 修改人：何杨 2010-2-17 上午01:00:09
	 */
	protected void handleCancel(){
		this.dispose();
	}
	
	/**
	 * 设置按钮的文字,如果觉得缺省按钮文字不符合需要可以覆写这个方法
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * 创建人：何杨 2010-2-17 上午01:04:33
	 * 修改人：何杨 2010-2-17 上午01:04:33
	 */
	protected void setButtonText(){
		confirmButton.setText("确认");
		cancelButton.setText("取消");
	}
	
	/**
	 * 设置对话框的宽度和高度
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param width
	 * @param height
	 * 创建人：何杨 2010-2-17 上午01:07:59
	 * 修改人：何杨 2010-2-17 上午01:07:59
	 */
	protected void setWindowSize(int width, int height) {
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		this.setSize(width, height);
		this.setLocation(screenSize.width / 2 - width / 2, screenSize.height
				/ 2 - height / 2);
	}

	public XuanButton getConfirmButton() {
		return confirmButton;
	}

	public XuanButton getCancelButton() {
		return cancelButton;
	}
}