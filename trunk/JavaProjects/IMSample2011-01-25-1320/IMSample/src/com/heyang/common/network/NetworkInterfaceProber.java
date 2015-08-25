package com.heyang.common.network;

import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.util.Enumeration;

/**
 * 此类用于取出本机的网络接口及其地址
 * 说明：
 * 作者：何杨(heyang78@gmail.com)
 * 创建时间：2010-11-5 上午10:13:32
 * 修改时间：2010-11-5 上午10:13:32
 */
public class NetworkInterfaceProber{
    public static void printNetworkInterface(){
        
        try{
        	// 此方法返回一个列表，其中包含了本机每一个接口对应的NetworkInterface实例，这些列表是无序的
        	// 这个列表包括了主机的所有接口，包括不能够向网络中的其它主机发送或接收消息的虚拟回环接口(lo0--127.0.0.1),还可能包括外部不可达的本地链接地址
            Enumeration<NetworkInterface> interfaces=NetworkInterface.getNetworkInterfaces();
            
            if(interfaces==null){
            	System.out.println("本机没有网络子系统");
            }
            else{
            	System.out.println("本机的网络接口名有：");
	            while(interfaces.hasMoreElements()){
	                NetworkInterface ni=interfaces.nextElement();
	                
	                // ni.getName()返回一个接口的名称
	                System.out.print(ni.getName()+",");
	            }
	            
	            interfaces=NetworkInterface.getNetworkInterfaces();
            	System.out.println("\n");
	            while(interfaces.hasMoreElements()){
	                NetworkInterface ni=interfaces.nextElement();
	                
	                // 取得接口的所有地址
	                Enumeration<InetAddress> inetAddresses=ni.getInetAddresses();
	                
	                if(inetAddresses.hasMoreElements()==false){
	                	System.out.println("接口'"+ni.getName()+"'没有对应的网络地址.");
	                }
	                else{
	                	System.out.println("接口'"+ni.getName()+"'对应的地址有：");
		                StringBuilder sb=new StringBuilder();
		                while(inetAddresses.hasMoreElements()){
		                    InetAddress address=inetAddresses.nextElement();
		                    
		                    if(address instanceof Inet4Address){
		                        sb.append("\t(v4)");
		                    }
		                    else{
		                        sb.append("\t(v6)");
		                    }
		                    
		                    sb.append("--"+address.getHostAddress()+"\n");
		                }
		                System.out.println(sb.toString());
	                }
	            }
            }
            
            /*while(interfaces.hasMoreElements()){
                NetworkInterface ni=interfaces.nextElement();
                
                sb.append("Interface "+ni.getName()+":\r\n");
                
                
                Enumeration<InetAddress> inetAddresses=ni.getInetAddresses();
                
                while(inetAddresses.hasMoreElements()){
                    InetAddress address=inetAddresses.nextElement();
                    
                    sb.append("Address");
                    
                    if(address instanceof Inet4Address){
                        sb.append("(v4)");
                    }
                    else{
                        sb.append("(v6)");
                    }
                    
                    sb.append(":address="+address.getHostAddress()+" name="+address.getHostName()+"\r\n");
                }
            }*/
        }catch(Exception ex){
            ex.printStackTrace();
        }
                
    }
    
    public static void main(String[] args){
    	printNetworkInterface();
    }
}