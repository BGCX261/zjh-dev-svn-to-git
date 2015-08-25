package com.heyang;

import com.heyang.biz.client.login.ProbeDialog;

/**
 * 启动客户端
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-23 下午03:14:32
 * 修改时间：2010-12-23 下午03:14:32
 */
public class RunClient{
	public static void main(String[] args){
		new ProbeDialog("服务器检测",300,200);
	}
}