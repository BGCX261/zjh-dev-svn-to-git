package com.heyang.common.network;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.log4j.Logger;

import com.heyang.util.DlgUtil;



/**
 * 这个类仅本类使用
 * @author 何杨
 * @date 2009-11-5
 * @time 下午03:15:20
 */
class IpPort{
    String ip;
    int    port;
}

/**
 * 远程端口探测器,判断远程端口是否打开
 * 
 * @author 何杨
 * @date 2009-11-5
 * @time 下午02:48:56
 */
public class RemotePortTestor{    
    public static Logger logger = Logger.getLogger(RemotePortTestor.class);
    
    // 测试项目集合
    private List<IpPort> testItems;
    
    
    /**
     * 构造函数
     * 
     * @param fileName
     * @param keys
     */
    public RemotePortTestor(String fileName,List<String> keys){
        Properties prop=new Properties();
        try {
            prop.load(new FileInputStream(fileName));
            
            testItems=new ArrayList<IpPort>();
            for(String key:keys){
                String value=prop.getProperty(key);
                testItems.add(getIpPortAddr(value));
            }            
        } catch (FileNotFoundException e) {
            logger.error(e);
            e.printStackTrace();
        } catch (IOException e) {
            logger.error(e);
            e.printStackTrace();
        }
    }
    
    /**
     * 检测远端端口,全部通过返回真
     * 
     * @return
     * 创建人:何杨
     * 创建日期:2009-11-5
     * 创建时间:下午03:32:34
     */
    public boolean testRemotePorts(){
        for(IpPort ipPort:testItems){
            if(testRemotePort(ipPort.ip,ipPort.port)==false){
                return false;
            }            
        }
        
        return true;
    }
    
    /**
     * 从URL中得到IP地址和端口
     * 
     * @param url
     * @return
     * 创建人:何杨
     * 创建日期:2009-11-5
     * 创建时间:下午03:32:55
     */
    private IpPort getIpPortAddr(String url){
        IpPort ipPort=new IpPort();
        
        String ip=getMatchedString("(//)(.*)(:)",url);
        ipPort.ip=ip;
        
        String port=getMatchedString("(:)(\\d+)",url);
        ipPort.port=Integer.parseInt(port);
        
        return ipPort;
    }
    
    /**
     * 检测端口是否能连接上
     * 
     * @param ip
     * @param port
     * @return
     * 创建人:何杨
     * 创建日期:2009-11-5
     * 创建时间:下午03:33:20
     */
    public static boolean testRemotePort(String ip,int port){        
        try {
            Socket s=new Socket(ip,port);
            System.out.println(s.getLocalAddress()+"可以访问"+ip+"上的端口"+port+"的服务.");
            s=null;
            return true;
        } catch (Exception e) {
            System.out.println("无法取得"+ip+"上的端口"+port+"的服务.");
            DlgUtil.popupErrorDialog("无法取得"+ip+"上的端口"+port+"的服务!\r\n,请确认服务可用后再执行本程序!");
                        
            e.printStackTrace();
            logger.error(e);
            return false;
        }    
    }
    
    /**
     * 从target找到regex能代表的文字
     * 
     * @param regex
     * @param target
     * @return
     * 创建人:何杨
     * 创建日期:2009-11-5
     * 创建时间:下午03:33:41
     */
    public static String getMatchedString(String regex,String target){
        Pattern pattern=Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        
        Matcher matcher=pattern.matcher(target);
        
        while(matcher.find()){
            return matcher.group(2);
        }
        
        return null;
    }
    
    /**
     * 测试入口
     * 
     * @param args
     * 创建人:何杨
     * 创建日期:2009-11-5
     * 创建时间:下午03:34:06
     */    
    public static void main(String[] args){
        List<String> ls=new ArrayList<String>();
        ls.add("webservice.url");
        ls.add("jmsbroker.url");
        
        String properitesFile=RemotePortTestor.class.getResource("/remoteservice.properites").getFile().toString();
        RemotePortTestor rt=new RemotePortTestor(properitesFile,ls);
        System.out.println(rt.testRemotePorts());
    }
}