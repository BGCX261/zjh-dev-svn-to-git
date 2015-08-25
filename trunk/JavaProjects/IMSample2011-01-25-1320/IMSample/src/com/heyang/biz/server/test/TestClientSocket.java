package com.heyang.biz.server.test;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import org.apache.commons.codec.binary.Base64;

import com.heyang.common.cipher.IMMsgDecryptException;
import com.heyang.common.cipher.IMMsgDecrypter;
import com.heyang.common.cipher.IMMsgEncryptException;
import com.heyang.common.cipher.IMMsgEncrypter;
import com.heyang.common.code.AESSecurityCoder;
import com.heyang.common.code.RSASecurityCoder;


/**
 * 此类用来模拟客户端进行测试
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-24 下午06:16:20
 * 修改时间：2010-12-24 下午06:16:20
 */
public class TestClientSocket{
	public static void main(String[] args) throws Exception{
		RSASecurityCoder rsaCoder=new RSASecurityCoder();		
		byte[] serverPublicKey=getPublicKey();
		
		AESSecurityCoder aesCoder=new AESSecurityCoder();
		
		testRegister(rsaCoder,serverPublicKey,aesCoder);
		
		testLogin(rsaCoder,serverPublicKey,aesCoder);
		
		testGetUserList(rsaCoder,serverPublicKey,aesCoder);
		
		testDispatch(rsaCoder,serverPublicKey,aesCoder);
		
		testLogout(rsaCoder,serverPublicKey,aesCoder);
	}
	
	public static void testGetUserList(RSASecurityCoder rsaCoder,byte[] serverPublicKey,AESSecurityCoder aesCoder) throws Exception{
		Socket s=new Socket("127.0.0.1",8888);
		
		InputStream  inStram=s.getInputStream();
        OutputStream outStream=s.getOutputStream();
        
        // 输出
        PrintWriter out=new PrintWriter(outStream,true);
        
        // 待加密的明文
        StringBuilder sb1=new StringBuilder();
        sb1.append("<request>");
        sb1.append("<command>getUserList</command>");
        sb1.append("<username>张飞</username>");
        sb1.append("<password>123456</password>");
        sb1.append("</request>");
        String plainText=sb1.toString();
        
        String request="";
        try{
    		// 加密过程
    		IMMsgEncrypter encrypter=new IMMsgEncrypter(plainText,Base64.encodeBase64String(serverPublicKey),rsaCoder,aesCoder);
    		request=encrypter.getCipheredMsg();
    	}
    	catch(IMMsgEncryptException e){
    		System.out.println("无法对客户端请求进行加密");
    	}
      
        out.print(request);
        out.flush();
        s.shutdownOutput();// 输出结束
        
        // 输入
        Scanner in=new Scanner(inStram);
        StringBuilder sb=new StringBuilder();
        while(in.hasNextLine()){
        	String line=in.nextLine();
        	sb.append(line);
        }
        String response=sb.toString();
        s.close();
    	
    	try{
    		// 解密过程
    		IMMsgDecrypter decrypter=new IMMsgDecrypter(response,rsaCoder,aesCoder);
    		String plainResponse=decrypter.getPlainMsg();
    		System.out.println("plainResponse="+plainResponse);
    	}catch(IMMsgDecryptException e){
    		System.out.println("无法对服务器端响应进行解密");
    	}
	}
	
	public static void testDispatch(RSASecurityCoder rsaCoder,byte[] serverPublicKey,AESSecurityCoder aesCoder) throws Exception{
		Socket s=new Socket("127.0.0.1",8888);
		
		InputStream  inStram=s.getInputStream();
        OutputStream outStream=s.getOutputStream();
        
        // 输出
        PrintWriter out=new PrintWriter(outStream,true);
        
        // 待加密的明文
        StringBuilder sb1=new StringBuilder();
        sb1.append("<request>");
        sb1.append("<command>dispatch</command>");
        sb1.append("<username>张飞</username>");
        sb1.append("<password>123456</password>");
        sb1.append("<to>张飞</to>");
        sb1.append("<msg>你好！张飞！</msg>");
        sb1.append("</request>");
        String plainText=sb1.toString();
        
        String request="";
        try{
    		// 加密过程
    		IMMsgEncrypter encrypter=new IMMsgEncrypter(plainText,Base64.encodeBase64String(serverPublicKey),rsaCoder,aesCoder);
    		request=encrypter.getCipheredMsg();
    	}
    	catch(IMMsgEncryptException e){
    		System.out.println("无法对客户端请求进行加密");
    	}
      
        out.print(request);
        out.flush();
        s.shutdownOutput();// 输出结束
        
        // 输入
        Scanner in=new Scanner(inStram);
        StringBuilder sb=new StringBuilder();
        while(in.hasNextLine()){
        	String line=in.nextLine();
        	sb.append(line);
        }
        String response=sb.toString();
        s.close();
    	
    	try{
    		// 解密过程
    		IMMsgDecrypter decrypter=new IMMsgDecrypter(response,rsaCoder,aesCoder);
    		String plainResponse=decrypter.getPlainMsg();
    		System.out.println("plainResponse="+plainResponse);
    	}catch(IMMsgDecryptException e){
    		System.out.println("无法对服务器端响应进行解密");
    	}
	}
	
	public static void testLogout(RSASecurityCoder rsaCoder,byte[] serverPublicKey,AESSecurityCoder aesCoder) throws Exception{
		Socket s=new Socket("127.0.0.1",8888);
		
		InputStream  inStram=s.getInputStream();
        OutputStream outStream=s.getOutputStream();
        
        // 输出
        PrintWriter out=new PrintWriter(outStream,true);
        
        // 待加密的明文
        StringBuilder sb1=new StringBuilder();
        sb1.append("<request>");
        sb1.append("<command>logout</command>");
        sb1.append("<username>张飞</username>");
        sb1.append("<password>123456</password>");
        sb1.append("</request>");
        String plainText=sb1.toString();
        
        String request="";
        try{
    		// 加密过程
    		IMMsgEncrypter encrypter=new IMMsgEncrypter(plainText,Base64.encodeBase64String(serverPublicKey),rsaCoder,aesCoder);
    		request=encrypter.getCipheredMsg();
    	}
    	catch(IMMsgEncryptException e){
    		System.out.println("无法对客户端请求进行加密");
    	}
      
        out.print(request);
        out.flush();
        s.shutdownOutput();// 输出结束
        
        // 输入
        Scanner in=new Scanner(inStram);
        StringBuilder sb=new StringBuilder();
        while(in.hasNextLine()){
        	String line=in.nextLine();
        	sb.append(line);
        }
        String response=sb.toString();
        s.close();
    	
    	try{
    		// 解密过程
    		IMMsgDecrypter decrypter=new IMMsgDecrypter(response,rsaCoder,aesCoder);
    		String plainResponse=decrypter.getPlainMsg();
    		System.out.println("plainResponse="+plainResponse);
    	}catch(IMMsgDecryptException e){
    		System.out.println("无法对服务器端响应进行解密");
    	}
	}
	
	public static void testLogin(RSASecurityCoder rsaCoder,byte[] serverPublicKey,AESSecurityCoder aesCoder) throws Exception{
		Socket s=new Socket("127.0.0.1",8888);
		
		InputStream  inStram=s.getInputStream();
        OutputStream outStream=s.getOutputStream();
        
        // 输出
        PrintWriter out=new PrintWriter(outStream,true);
        
        // 待加密的明文
        StringBuilder sb1=new StringBuilder();
        sb1.append("<request>");
        sb1.append("<command>login</command>");
        sb1.append("<username>张飞</username>");
        sb1.append("<password>123456</password>");
        sb1.append("<port>8889</port>");
        sb1.append("</request>");
        String plainText=sb1.toString();
        
        String request="";
        try{
    		// 加密过程
    		IMMsgEncrypter encrypter=new IMMsgEncrypter(plainText,Base64.encodeBase64String(serverPublicKey),rsaCoder,aesCoder);
    		request=encrypter.getCipheredMsg();
    	}
    	catch(IMMsgEncryptException e){
    		System.out.println("无法对客户端请求进行加密");
    	}
      
        out.print(request);
        out.flush();
        s.shutdownOutput();// 输出结束
        
        // 输入
        Scanner in=new Scanner(inStram);
        StringBuilder sb=new StringBuilder();
        while(in.hasNextLine()){
        	String line=in.nextLine();
        	sb.append(line);
        }
        String response=sb.toString();
        s.close();
    	
    	try{
    		// 解密过程
    		IMMsgDecrypter decrypter=new IMMsgDecrypter(response,rsaCoder,aesCoder);
    		String plainResponse=decrypter.getPlainMsg();
    		System.out.println("plainResponse="+plainResponse);
    	}catch(IMMsgDecryptException e){
    		System.out.println("无法对服务器端响应进行解密");
    	}
	}
	
	public static void testRegister(RSASecurityCoder rsaCoder,byte[] serverPublicKey,AESSecurityCoder aesCoder) throws Exception{
		Socket s=new Socket("127.0.0.1",8888);
		
		InputStream  inStram=s.getInputStream();
        OutputStream outStream=s.getOutputStream();
        
        // 输出
        PrintWriter out=new PrintWriter(outStream,true);
        
        // 待加密的明文
        StringBuilder sb1=new StringBuilder();
        sb1.append("<request>");
        sb1.append("<command>register</command>");
        sb1.append("<username>诸葛亮</username>");
        sb1.append("<password>123456</password>");
        sb1.append("</request>");
        String plainText=sb1.toString();
        
        String request="";
        try{
    		// 加密过程
    		IMMsgEncrypter encrypter=new IMMsgEncrypter(plainText,Base64.encodeBase64String(serverPublicKey),rsaCoder,aesCoder);
    		request=encrypter.getCipheredMsg();
    	}
    	catch(IMMsgEncryptException e){
    		System.out.println("无法对客户端请求进行加密");
    	}
      
        out.print(request);
        out.flush();
        s.shutdownOutput();// 输出结束
        
        // 输入
        Scanner in=new Scanner(inStram);
        StringBuilder sb=new StringBuilder();
        while(in.hasNextLine()){
        	String line=in.nextLine();
        	sb.append(line);
        }
        String response=sb.toString();
        s.close();
    	
    	try{
    		// 解密过程
    		IMMsgDecrypter decrypter=new IMMsgDecrypter(response,rsaCoder,aesCoder);
    		String plainResponse=decrypter.getPlainMsg();
    		System.out.println("plainResponse="+plainResponse);
    	}catch(IMMsgDecryptException e){
    		System.out.println("无法对服务器端响应进行解密");
    	}
	}
	
	public static byte[] getPublicKey() throws Exception{
		Socket s=new Socket("127.0.0.1",8888);
		
		InputStream  inStram=s.getInputStream();
        OutputStream outStream=s.getOutputStream();
        
        // 输出
        PrintWriter out=new PrintWriter(outStream,true);
        
        out.print("getPublicKey");
        out.flush();

        s.shutdownOutput();// 输出结束
        
        // 输入
        Scanner in=new Scanner(inStram);
        StringBuilder sb=new StringBuilder();
        while(in.hasNextLine()){
        	String line=in.nextLine();
        	sb.append(line);
        }
        String response=sb.toString();
        
        byte[] arr=Base64.decodeBase64(response);
        
        s.close();
        return arr;
	}
}