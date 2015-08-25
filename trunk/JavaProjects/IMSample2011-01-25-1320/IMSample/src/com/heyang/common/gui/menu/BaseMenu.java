package com.heyang.common.gui.menu;

import javax.swing.JMenu;

/**
 * ����˵���
 * @author ����
 * @date 2009-10-12
 * @time ����09:03:37
 */
public abstract class BaseMenu extends JMenu{
	public BaseMenu(String text){
		super(text);
		addSubMenuItems();
	}
	
	protected abstract void addSubMenuItems();
}