package com.heyang.base.panel;

import java.awt.Color;
import java.awt.Component;
import java.awt.Font;

import javax.swing.BorderFactory;
import javax.swing.JPanel;

import com.heyang.common.gui.intro.IntroBase;

/**
 * 面板的抽象基类，如果没有特别要求，所有的面板都应该继承它
 * 
 * 说明：要修改请与何杨商议，切忌自行修改！
 * 创建人：何杨
 * 创建时间：2010-2-14 下午09:33:28
 * 
 * 修改人：何杨
 * 修改时间：2010-2-14 下午09:33:28
 */
public abstract class BasePanel extends JPanel{
	private static final long serialVersionUID = -2136398526477864695L;
	
	// 标题分隔线的颜色
	private static final Color lineColor=new Color(192,206,220);
	
	public BasePanel(){
		initComponents();
		setLayoutAndAddComponents();
		addComponentListeners();
	}
	
	/**
	 * 初始化子组件
	 * 
	 * 创建人:何杨
	 * 创建日期:2009-11-4
	 * 创建时间:上午09:21:08
	 */
	protected abstract void initComponents();
	
	/**
	 * 设置布局并添加子组件
	 * 
	 * 创建人:何杨
	 * 创建日期:2009-11-4
	 * 创建时间:上午09:21:21
	 */
	protected abstract void setLayoutAndAddComponents();
	
	/**
	 * 添加组件的事件监听器
	 * 注意作为MVC的V部分要把监听放在Ctroller中写,而一些不用从model找数据的监听可以直接写在这里.
	 * 对于一些简单面板,可以直接把监听写在这里.
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * 创建人：何杨 2010-2-14 下午10:13:02
	 * 修改人：何杨 2010-2-14 下午10:13:02
	 */
	protected abstract void addComponentListeners();
	/**
	 * 刷新界面
	 * 
	 * 创建人:何杨
	 * 创建日期:2009-10-22
	 * 创建时间:下午12:50:27
	 */
	public void refreshGui(){
		// 由有需要的面板覆盖。
	}
	
	/**
	 * 传入一个文本,以此来刷新界面上的值
	 * 
	 * @author：何杨
	 * @date：2009-12-17
	 * @time：下午01:51:19
	 * @param text
	 */
	public void refreshGuiBy(String text){
		// 由需要的面板覆写
	}
	
	/**
	 * 设置面板的标题
	 * @param title
	 */
	public void setTitle(String title){
		setBorder(BorderFactory.createTitledBorder(BorderFactory
				.createTitledBorder(BorderFactory.createMatteBorder(1, 0, 1, 0,
						lineColor)), title, 1, 1, new Font(
				"宋体", Font.BOLD, 16)));
	}
	
	/**
	 * 设置子面板的标题(小)
	 * @param title
	 */
	public void setSmallTitle(String title){
		setBorder(BorderFactory.createTitledBorder(BorderFactory
				.createTitledBorder(BorderFactory.createMatteBorder(1, 0, 0, 0,
						lineColor)), title, 1, 1, new Font(
				"宋体", Font.PLAIN, 12)));
		
		//setBorder(BorderFactory.createEtchedBorder());
	}
	
	public void resetGui(){
		Component[] arr=this.getComponents();
		for(Component comp:arr ){			
			if(comp instanceof IntroBase){
				IntroBase intro=(IntroBase)comp;
				
				intro.setText("");
			}
		}
	}
}