package com.heyang.common.cipher;

/**
 * 无法解密消息时时抛出的异常
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-27 下午06:41:42
 * 修改时间：2010-12-27 下午06:41:42
 */
public class IMMsgDecryptException extends Exception{
	private static final long serialVersionUID = -6756080828925476383L;
	
	public IMMsgDecryptException(String errorMessage){
		super(errorMessage);
	}
}