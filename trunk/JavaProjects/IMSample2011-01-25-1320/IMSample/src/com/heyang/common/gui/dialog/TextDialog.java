package com.heyang.common.gui.dialog;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import com.heyang.base.dlg.BaseDialog;
import com.heyang.common.gui.button.XuanButton;

/**
 * 显示文本的对话框
 * 
 * 说明：要修改请与何杨商议，切忌自行修改！
 * 创建人：何杨
 * 创建时间：2010-2-17 上午01:12:49
 * 
 * 修改人：何杨
 * 修改时间：2010-2-17 上午01:12:49
 */
public class TextDialog extends BaseDialog{
	private static final long serialVersionUID = 3750582058500482195L;
	
	// 用于显示错误详细信息的文本框
	private JTextArea detailTxt;
	
	public TextDialog(String titleText, String text,int width, int height) {
		super(titleText, width, height);
		detailTxt.setText(text);
	}

	@Override
	protected void addComponentsToCenterPanel() {
		detailTxt=new JTextArea("",5,20);
		detailTxt.setWrapStyleWord(true);
		detailTxt.setLineWrap(true);
		
		centerPanel.setLayout(new BorderLayout());
		centerPanel.add(new JScrollPane(detailTxt),BorderLayout.CENTER);
	}
	
	protected void addComponentsToSouthPanel(){
		confirmButton=new XuanButton("确认");
		confirmButton.addActionListener(
			new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					handleConfirm();
				}
			}
		);
		
		cancelButton=new XuanButton("取消");
		cancelButton.addActionListener(
			new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					handleCancel();
				}
			}
		);
		
		southPanel.add(cancelButton);
	}

	@Override
	protected void handleConfirm() {
		// do nothing
	}
	
	/**
	 * 设置文本框的文字
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param text
	 * 创建人：何杨 2010-2-17 上午01:18:47
	 * 修改人：何杨 2010-2-17 上午01:18:47
	 */
	public void setText(String text){
		detailTxt.setText(text);
	}
}