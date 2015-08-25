package com.heyang.biz.client.userlist.model;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Map;
import java.util.Scanner;

import javax.swing.JFrame;

import com.heyang.biz.client.ClientUtil;
import com.heyang.biz.client.chat.ctrl.ChatCtrl;
import com.heyang.common.cipher.IMMsgDecryptException;
import com.heyang.common.cipher.IMMsgDecrypter;
import com.heyang.util.DlgUtil;

/**
 * 用于与客户端交流的线程
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-12-24 下午04:10:26
 * 修改时间：2010-12-24 下午04:10:26
 */
public class Receiver implements Runnable{
	private Socket incoming;
	//private UserlistView view;
	private UserlistModel model;
    
	/**
	 * 构造函数
	 * @param incoming
	 * @param view
	 */
    public Receiver(Socket incoming,UserlistModel model){
        this.incoming=incoming;
        //this.view=view;
        this.model=model;
    }
    
    public void run(){
    	try{
    		// 取得进入Socket的源头的IP地址
    		String clientIpAddr=incoming.getInetAddress().getHostAddress();
    		if(clientIpAddr.equals(ClientUtil.getServerIP())==false){
    			// 忽略不是来自服务器的信息
    			return;
    		}
    		
            InputStream  inStram=incoming.getInputStream();
            OutputStream outStream=incoming.getOutputStream();
            
            Scanner in=new Scanner(inStram);
            PrintWriter out=new PrintWriter(outStream,true);
            
            // 得到客户端的请求
            StringBuilder sb=new StringBuilder();
            while(in.hasNextLine()){
                String line=in.nextLine();
                sb.append(line);
            }
            
            String dispatchedMsg=sb.toString();// 得到的文本处于加密状态
            
            String plainDispatchedMsg="";// 存储明文用
        	try{
        		// 解密过程
        		IMMsgDecrypter decrypter=new IMMsgDecrypter(dispatchedMsg,ClientUtil.getRsaCoder(),ClientUtil.getAesCoder());
        		plainDispatchedMsg=decrypter.getPlainMsg();
        		
        		
        	}catch(IMMsgDecryptException e){
        		//view.getMsgArea().insertRedMsg("无法解密服务器转发的文本'"+dispatchedMsg+"'",clientIpAddr);
        		DlgUtil.popupErrorDialog("无法解密服务器转发的文本'"+dispatchedMsg+"'.其来自"+clientIpAddr);
        	}
            
        	try{
        		Map<String,String> map=ClientUtil.parseResponse(plainDispatchedMsg);
        		String from=map.get("from");
        		
        		ChatCtrl ctrl=model.addOrActiveChatWindow(from);
        		ctrl.getView().getMsgArea().insertReceivedMsg(map.get("msg"),map.get("from"));
        		ctrl.getView().setExtendedState(JFrame.NORMAL);
        		ctrl.getView().toFront();
        		
        		//view.getMsgArea().insertReceivedMsg(map.get("msg"),map.get("from"));
        	}catch(Exception e){
        		//view.getMsgArea().insertRedMsg("服务器转发过来的文本'"+dispatchedMsg+"'不符合预定的格式",clientIpAddr);
        		DlgUtil.popupErrorDialog("服务器转发过来的文本'"+dispatchedMsg+"'不符合预定的格式"+clientIpAddr);
        	}
            
            out.close();
        }
        catch(Exception ex){
            ex.printStackTrace();
        }
        finally{
            try {
                incoming.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}