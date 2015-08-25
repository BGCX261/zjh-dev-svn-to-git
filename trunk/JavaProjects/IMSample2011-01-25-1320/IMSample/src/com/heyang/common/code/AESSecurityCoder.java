package com.heyang.common.code;

import java.security.Key;
import java.security.NoSuchAlgorithmException;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.spec.SecretKeySpec;

import org.apache.commons.codec.binary.Hex;


/**
 * AES加密解密类
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-25 下午12:19:12
 * 修改时间：2010-12-25 下午12:19:12
 */
public class AESSecurityCoder{
	// 加密方法
	private static final String Algorithm="AES";
	
	// 进行加密解密的密钥
	private String aesKey="";
	
	/**
	 * 构造函数
	 * @throws NoSuchAlgorithmException 
	 */
	public AESSecurityCoder() throws NoSuchAlgorithmException{
		KeyGenerator kg=KeyGenerator.getInstance(Algorithm);
		kg.init(256);
		SecretKey sk=kg.generateKey();
		byte[] arr=sk.getEncoded();
		
		aesKey=new String(Hex.encodeHex(arr));
	}
	
	/**
	 * 取得解密后的字符串
	 * 
	 * 说明：
	 * @param encryptArr
	 * @return
	 * 创建时间：2010-12-1 下午03:33:31
	 */
	public String getDecryptString(byte[] encryptArr){
		try{
			Cipher cp=Cipher.getInstance(Algorithm);
			cp.init(Cipher.DECRYPT_MODE, getKey());
			
			// TODO:
			byte[] arr=cp.doFinal(encryptArr);
			
			return new String(arr);
		}
		catch(Exception ex){
			System.out.println("无法进行解密，原因是"+ex.getMessage());
			return null;
		}
	}
	
	/**
	 * 传入密钥，得到解密后的字符串
	 * 
	 * 说明：
	 * @param encryptArr
	 * @param aesKey
	 * @return
	 * 创建时间：2010-12-25 下午01:55:42
	 */
	public String getDecryptString(byte[] encryptArr,String aesKeyIn){
		try{
			Cipher cp=Cipher.getInstance(Algorithm);
			
			byte[] arr1=Hex.decodeHex(aesKeyIn.toCharArray());
			cp.init(Cipher.DECRYPT_MODE, new SecretKeySpec(arr1,Algorithm));
			
			// TODO:
			byte[] arr=cp.doFinal(encryptArr);
			
			return new String(arr);
		}
		catch(Exception ex){
			System.out.println("无法进行解密，原因是"+ex.getMessage());
			return null;
		}
	}
	
	/**
	 * 取得加密后的字节数组
	 * 
	 * 说明：
	 * @param originalString
	 * @return
	 * 创建时间：2010-12-1 下午03:33:49
	 */
	public byte[] getEncryptByteArray(String originalString){
		try{
			Cipher cp=Cipher.getInstance(Algorithm);
			cp.init(Cipher.ENCRYPT_MODE, getKey());
			return cp.doFinal(originalString.getBytes());
		}
		catch(Exception ex){
			System.out.println("无法进行加密，原因是"+ex.getMessage());
			return null;
		}
	}
	
	/**
	 * 取得密钥
	 * 
	 * 说明：
	 * @return
	 * @throws Exception
	 * 创建时间：2010-12-1 下午03:33:17
	 */
	private Key getKey() throws Exception{
		byte[] arr=Hex.decodeHex(aesKey.toCharArray());
		
		return new SecretKeySpec(arr,Algorithm);
	}

	/**
	 * 取得AES加密钥匙
	 * 
	 * 说明：
	 * @return
	 * 创建时间：2010-12-25 下午12:27:16
	 */
	public String getAesKey() {
		return aesKey;
	}
}