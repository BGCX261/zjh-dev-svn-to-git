package com.heyang.common.cipher;

import org.apache.commons.codec.binary.Base64;

import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.Base64SecurityUtil;
import com.heyang.common.code.RSASecurityCoder;
import com.heyang.common.code.UTF8Coder;

/**
 * 对消息进行加密的加密器
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-27 下午07:00:29
 * 修改时间：2010-12-27 下午07:00:29
 */
public class IMMsgEncrypter{
	// 经加密的消息
	private String cipheredMsg;
	
	/**
	 * 构造函数
	 * @param plainMsg 未加密的消息
	 * @param otherSideRSAPublicKey 对方RSA公钥
	 * @param rsaCoder 己方RSA编码器
	 * @param aesCoder 己方AES编码器
	 * @throws IMMsgEncryptException
	 */
	public IMMsgEncrypter(String plainMsg,String otherSideRSAPublicKey,RSASecurityCoder rsaCoder,AESSecurityCoder aesCoder) throws IMMsgEncryptException{
		try{
			// 防止乱码
			plainMsg=UTF8Coder.encode(plainMsg);
			
			// 对明文进行AES加密
	        byte[] aesArr=aesCoder.getEncryptByteArray(plainMsg); // 对明文进行AES加密
	        String cipherText=Base64.encodeBase64String(aesArr);// 得到AES加密后的密文
	    	
	        // 使用RSA对AES密钥进行加密
	        String key=aesCoder.getAesKey();// 取得AES的密钥
	        String aesKey="";
	        try{
	        	byte[] clientRsaKeyArr=null;
	        	clientRsaKeyArr=Base64.decodeBase64(otherSideRSAPublicKey);
	        	byte[] rsaArr=rsaCoder.getEncryptArray(key, clientRsaKeyArr);
	        	aesKey=Base64.encodeBase64String(rsaArr);
	        }
	        catch(Exception ex){
	        	throw new IMMsgEncryptException("使用对方RSA公钥加密己方AES钥匙时发生异常.");
	        }
	        
	        // 在发出的密文前附带经服务器RSA公钥加密的AES密钥
	        StringBuilder sb=new StringBuilder();
	        sb.append("<aeskey>"+aesKey+"</aeskey>");
	        sb.append("<rsakey>"+rsaCoder.getPublicKeyString()+"</rsakey>");
	        sb.append("<text>"+cipherText+"</text>");
	        
	        // 最后对整体进行Base64加密
	        cipheredMsg=Base64SecurityUtil.getEncryptString(sb.toString());
		}
		catch(Exception ex){
			throw new IMMsgEncryptException("加密消息时发生异常,异常信息为"+ex.getMessage()+".");
		}
	}

	public String getCipheredMsg() {
		return cipheredMsg;
	}
}