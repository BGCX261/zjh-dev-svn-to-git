package com.heyang.common.network;

import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.util.Enumeration;

/**
 * 此类用于取出本机的IP地址
 * 
 * @date 2009-11-5
 * @time 上午10:41:13
 */
public class LocalIPFetcher{
    public String getIPInfo(){

        StringBuilder sb=new StringBuilder();
        
        try{
            Enumeration<NetworkInterface> interfaces=NetworkInterface.getNetworkInterfaces();
            
            while(interfaces.hasMoreElements()){
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
            }
        }catch(Exception ex){
            ex.printStackTrace();
        }
                
        return sb.toString();
    }
    
    public static void main(String[] args){
    	LocalIPFetcher iPAddrFetcher=new LocalIPFetcher();
        System.out.println(iPAddrFetcher.getIPInfo());
    }
}