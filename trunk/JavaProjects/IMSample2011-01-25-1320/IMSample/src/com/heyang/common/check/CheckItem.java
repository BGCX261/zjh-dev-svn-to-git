package com.heyang.common.check;

import java.util.regex.Pattern;

import javax.swing.text.JTextComponent;

import com.heyang.util.DlgUtil;

/**
 * 正则表达式检查项
 * 
 * 说明：要修改请与何杨商议，切忌自行修改！
 * 创建人：何杨
 * 创建时间：2010-2-15 上午11:49:31
 * 
 * 修改人：何杨
 * 修改时间：2010-2-15 上午11:49:31
 */
public class CheckItem{
	// 要检查的文本组件
	private JTextComponent component;
	
	// 设定了合法字符的正则表达式字符串
	private String checkRegex;
	
	// 当文本组件的内容不符合设定的正则表达式时弹出对话框显示的文字
	private String errorMsg;
	
	// 是否必填项
	private boolean isNessessay;
	
	/**
	 * 构造函数
	 * @param component 要检查的文本组件
	 * @param checkRegex 合法字符的正则表达式字符串
	 * @param errorMsg 当文本组件的内容不符合设定的正则表达式时弹出对话框显示的文字
	 * @param isNessessay 是否必填项
	 */
	public CheckItem(JTextComponent component,String checkRegex,String errorMsg,boolean isNessessay){
		this.component=component;
		this.checkRegex=checkRegex;
		this.errorMsg=errorMsg;
		this.isNessessay=isNessessay;
	}
	
	/**
	 * 取得验证的结果
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @return
	 * 创建人：何杨 2010-2-15 下午12:22:53
	 * 修改人：何杨 2010-2-15 下午12:22:53
	 */
	public boolean getCheckResult(){
		if(isNessessay==false && component.getText().length()<1){
			return true;
		}
		
		boolean retval=Pattern.matches(checkRegex,component.getText());
		
		if(retval==false){
			DlgUtil.popupWarningDialog(errorMsg);
			component.requestFocus();
		}
		
		return retval;
	}
}