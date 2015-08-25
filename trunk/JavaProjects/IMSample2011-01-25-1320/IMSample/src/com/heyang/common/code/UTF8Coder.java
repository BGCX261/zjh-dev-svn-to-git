package com.heyang.common.code;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.net.URLEncoder;


/**
 * UTF8转码器
 * @author heyang
 *
 */
public class UTF8Coder{
	private static final String UTF_8 = "utf-8";// 编码形式

	/**
	 * 对文字进行UTF8转码
	 * @param str
	 * @return
	 */
	public static String encode(String str){
		try {
			return URLEncoder.encode(str, UTF_8);
		} catch (UnsupportedEncodingException e) {
			return null;
		}
	}
	
	/**
	 * 将转码后的文字还原
	 * @param str
	 * @return
	 */
	public static String decode(String str){
		try {
			return URLDecoder.decode(str, UTF_8);
		} catch (UnsupportedEncodingException e) {
			return null;
		}
	}
}