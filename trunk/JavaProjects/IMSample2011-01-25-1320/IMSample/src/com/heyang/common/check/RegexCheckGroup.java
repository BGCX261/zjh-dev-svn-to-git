package com.heyang.common.check;

import java.util.LinkedHashSet;
import java.util.Set;

import javax.swing.text.JTextComponent;

/**
 * 正则表达式检查组
 * 
 * 说明：要修改请与何杨商议，切忌自行修改！
 * 创建人：何杨
 * 创建时间：2010-2-15 下午12:23:29
 * 
 * 修改人：何杨
 * 修改时间：2010-2-15 下午12:23:29
 */
public class RegexCheckGroup{
	// 检查项集合
	private Set<CheckItem> checkSets;
	
	/**
	 * 构造函数
	 */
	public RegexCheckGroup(){
		checkSets=new LinkedHashSet<CheckItem>();
	}
	
	/**
	 * 添加一个检查项
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param component
	 * @param checkRegex
	 * @param errorMsg
	 * @param isNessessay
	 * 创建人：何杨 2010-2-15 下午12:24:07
	 * 修改人：何杨 2010-2-15 下午12:24:07
	 */
	public void addCheckItem(JTextComponent component,String checkRegex,String errorMsg,boolean isNessessay){
		checkSets.add(new CheckItem(component,checkRegex,errorMsg,isNessessay));
	}
	
	/**
	 * 取得所有检查项的检查结果
	 * 
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @return
	 * 创建人：何杨 2010-2-15 下午12:24:17
	 * 修改人：何杨 2010-2-15 下午12:24:17
	 */
	public boolean getCheckResult(){
		for(CheckItem item:checkSets){
			if(item.getCheckResult()==false){
				return false;
			}
		}
		
		return true;
	}
}