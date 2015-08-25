package com.heyang.common.cipher;

import org.apache.commons.codec.binary.Base64;

import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.Base64SecurityUtil;
import com.heyang.common.code.RSASecurityCoder;
import com.heyang.common.code.UTF8Coder;


/**
 * 消息解密器
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-27 下午07:41:44
 * 修改时间：2010-12-27 下午07:41:44
 */
public class IMMsgDecrypter{
	// 固定的三个节点名
	private static final String TEXT = "text";

	private static final String RSAKEY = "rsakey";

	private static final String AESKEY = "aeskey";

	// 对方的RSA公钥
	private String otherSideRSAPublicKey;
	
	// 解密后的明文
	private String plainMsg;
	
	/**
	 * 构造函数
	 * @param cipherMsg 要解密的消息
	 * @param rsaCoder 己方RSA编码器
	 * @param aesCoder 己方AES编码器
	 * @throws IMMsgDecryptException
	 */
	public IMMsgDecrypter(String cipherMsg,RSASecurityCoder rsaCoder,AESSecurityCoder aesCoder) throws IMMsgDecryptException{
		try{
			// 先用Base64解密密文
	    	cipherMsg=Base64SecurityUtil.getDecryptString(cipherMsg);
	    	
	    	// 得到密钥文，客户端的RSA公钥和密文
	    	String cipheredAesKey=getNodeText(cipherMsg,AESKEY);
	    	otherSideRSAPublicKey=getNodeText(cipherMsg,RSAKEY);
	    	String cipherText=getNodeText(cipherMsg,TEXT);

	    	// 得到经过服务器RSA私钥解密后的AES密钥
	    	String plainAesKey="";
	    	try {
	    		byte[] cipheredAesKeyArr=Base64.decodeBase64(cipheredAesKey);
				plainAesKey=rsaCoder.getDecryptString(cipheredAesKeyArr);
			} catch (Exception e) {
				throw new IMMsgDecryptException("无法解密对方AES密钥,异常信息为"+e.getMessage()+",客户端请求为:"+cipherMsg);
			}
	    	
			// 使用AES密钥解密出明文
	    	byte[] cipherTextArr=Base64.decodeBase64(cipherText);
	    	plainMsg=aesCoder.getDecryptString(cipherTextArr, plainAesKey);
	    	
	    	// 　UTF08还原
	    	plainMsg=UTF8Coder.decode(plainMsg);
		}
		catch(Exception ex){
			throw new IMMsgDecryptException("解密消息发生异常,异常信息为"+ex.getMessage()+".");
		}
	}
	
	/**
	 * 得到加密消息中节点的文字
	 * @param cipherMsg
	 * @param nodeName
	 * @return
	 */
	private String getNodeText(String cipherMsg,String nodeName){
		String beginTag="<"+nodeName+">";
		String endTag="</"+nodeName+">";
		
		int beginIndex=cipherMsg.indexOf(beginTag);
		int endIndex=cipherMsg.indexOf(endTag);
		
		String retval=cipherMsg.substring(beginIndex+beginTag.length(), endIndex);
		
		return retval;
	}

	public String getOtherSideRSAPublicKey() {
		return otherSideRSAPublicKey;
	}

	public String getPlainMsg() {
		return plainMsg;
	}
}