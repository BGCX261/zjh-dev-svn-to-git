package com.heyang.common.network;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * 此類用於測試能否ping通另一臺機器
 * 说明：使用方法请参照最后的Main函数
 * @author 何杨（heyang78@gmail.com）
 * 创建时间：2010-4-28 上午11:08:16
 * 修改时间：2010-4-28 上午11:08:16
 */
public class Pinger {
    // 想要ping的遠程機器IP地址
    private String remoteIpAddress;

    // ping遠程機器的次數
    private final int pingTimes = 10;

    // 超時時間
    private int timeOut = 4;

    /**
     * 構造函數
     * @param remoteIpAddress
     * @param timeOut
     */
    public Pinger(String remoteIpAddress, int timeOut) {
        this.remoteIpAddress = remoteIpAddress;
        this.timeOut = timeOut;
    }

    /**
     * 測試是否能ping通
     * @param server
     * @param timeout
     * @return
     */
    public boolean isReachable() {
        BufferedReader in = null;
        Runtime r = Runtime.getRuntime();

        // 將要執行的ping命令,此命令是windows格式的命令
        String pingCommand = "ping " + remoteIpAddress + " -n "+pingTimes+" -w " + timeOut;
        
        try {
            // 執行命令并獲取輸出
            Process p = r.exec(pingCommand);
            if (p == null) {
                return false;
            }
            in = new BufferedReader(new InputStreamReader(p.getInputStream()));
            
            // 逐行檢查輸出,計算類似=23ms TTL=62這樣的字樣出現的次數
            int connectedCount=0;
            String line = null;
            while ((line = in.readLine()) != null) {
                connectedCount+=getCheckResult(line);
            }
            
            // 如果出現類似=23ms TTL=62這樣的字樣出現的次數等於測試次數則返回真
            return connectedCount==pingTimes;
        } catch (Exception ex) {
            ex.printStackTrace();
            
            // 出現異常則返回假
            return false;
        } finally {
            try {
                in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    
    /**
     * 若line含有=18ms TTL=16字樣,說明已經ping通,返回一,否則返回零.
     * @param line
     * @return
     */
    private static int getCheckResult(String line){
        Pattern pattern=Pattern.compile("((<|=)\\d+ms)(\\s+)(TTL=\\d+)", Pattern.CASE_INSENSITIVE);    
        Matcher matcher=pattern.matcher(line);        
        while(matcher.find()){
            return 1;
        }
        
        return 0;
    }

    public static void main(String[] args) {
        Pinger p=new Pinger("129.125.162.12",10);
        
        System.out.println(p.isReachable());
    }
}