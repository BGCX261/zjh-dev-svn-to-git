package com.heyang.biz.server.model;


/**
 * 本类用于记录已登录用户的相关信息
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-28 下午04:50:56
 * 修改时间：2010-12-28 下午04:50:56
 */
public class LoginUser{
	// 用户名
	private String name;
	
	// 用户的RSA公钥，用以发消息给他时加密用
	private String rsaPublicKey;
	
	// IP地址
	private String ip;
	
	// 客户端用来监听的端口，将消息转发给第三方时将会用到
	private int port;
	
	public LoginUser(){
		
	}
	
	public LoginUser(String name,String rsaPublicKey,String ip,int port){
		this.name=name;
		this.rsaPublicKey=rsaPublicKey;
		this.ip=ip;
		this.port=port;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getRsaPublicKey() {
		return rsaPublicKey;
	}
	public void setRsaPublicKey(String rsaPublicKey) {
		this.rsaPublicKey = rsaPublicKey;
	}
	public int getPort() {
		return port;
	}
	public void setPort(int port) {
		this.port = port;
	}

	public String getIp() {
		return ip;
	}

	public void setIp(String ip) {
		this.ip = ip;
	}
	
}