package com.heyang.base.mvc;

import com.heyang.base.panel.BasePanel;


/**
 * biz包中诸控制类的接口
 * 
 * 说明：要修改请与何杨商议，切忌自行修改！
 * 创建人：何杨
 * 创建时间：2010-2-13 下午01:16:20
 * 
 * 修改人：何杨
 * 修改时间：2010-2-13 下午01:16:20
 */
public abstract class BaseCtrl{
	/**
	 * 构造函数
	 */
	public BaseCtrl(){
		initialModelAndView();
		addListeners();
	}
	
	/**
	 * 初始化数据中心和视图
	 * 
	 * 说明：
	 * 创建时间：2010-2-24 上午11:07:45
	 * 修改时间：2010-2-24 上午11:07:45
	 */
	protected abstract void initialModelAndView();
	
	/**
	 * 为界面添加事件监听器
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * 创建人：何杨 2010-2-13 下午01:17:32
	 * 修改人：何杨 2010-2-13 下午01:17:32
	 */
	protected abstract void addListeners();
	
	/**
	 * 得到View对应的面板，对于要放在content中的面板需要进行覆写
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-2-24 上午11:09:57
	 * 修改时间：2010-2-24 上午11:09:57
	 */
	public BasePanel getPanel(){
		return null;
	}
}