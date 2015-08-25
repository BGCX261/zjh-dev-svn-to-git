package com.heyang.common.check;

import java.util.regex.Pattern;


/**
 * 保存常用检查项的工具类
 * 
 * 说明：要修改请与何杨商议，切忌自行修改！
 * 创建人：何杨
 * 创建时间：2010-2-15 下午12:25:03
 * 
 * 修改人：何杨
 * 修改时间：2010-2-15 下午12:25:03
 */
public final class RegexConstants{
	// 整数
	public static final String Integer="\\d+";
	
	// 货币,小数
	public static final String Float="(\\d+)|(\\d+[.]{0,1}\\d*)";
	
	// 日期
	public static final String Date="\\d{4}[-]\\d{1,2}[-]\\d{1,2}";
	
	// 空白字符
	public static final String NotWhiteSpace="\\S+";
	
	// 汉字
	public static final String Character="[\\u4E00-\\u9FA5]+";
	
	// 汉字名称
	public static final String ChineseName="[\\u4E00-\\u9FA5]{2,4}";
	
	// 电子邮件
	public static final String Email="\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*[.]\\w+([-.]\\w+)*";
	
	// 移动电话号码
	public static final String Mobile="[1]{1}\\d{10}";
	
	// 固定电话号码
	public static final String Phone="\\d{3,4}[-]\\d{7,8}";
    
    // 无区号的固话号码
    public static final String Phone_Without_AreaCode = "\\d{7,8}";
	
	// 邮政编码
	public static final String PostCode="\\d{6}";
	
	/**
	 * 返回限定最大程度的字符串
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param maxLength 
	 * @return
	 * 创建人：何杨 2010-2-15 下午12:26:57
	 * 修改人：何杨 2010-2-15 下午12:26:57
	 */
	public static String getLimitedString(int maxLength){
		return "(.|\\s){0,"+maxLength+"}";
	}
    
	/**
	 * 返回限制最大和最小长度的字符串
	 * 
	 * 说明：要修改此方法请与何杨商议，请勿自行修改！
	 * @param minLength
	 * @param maxLength
	 * @return
	 * 创建人：何杨 2010-2-15 下午12:27:17
	 * 修改人：何杨 2010-2-15 下午12:27:17
	 */
    public static String getLimitedString(int minLength, int maxLength) {
        return "(.|\\s){" + minLength + "," + maxLength + "}";
    }
	
    /**
     * 测试
     * 
     * 说明：要修改此方法请与何杨商议，请勿自行修改！
     * @param args
     * 创建人：何杨 2010-2-15 下午12:27:54
     * 修改人：何杨 2010-2-15 下午12:27:54
     */
	public static void main(String[] args){
		String[] arr1={"1","1.1","0.1","0.111","111.11111",".11","11.","110.00.1","0.00.1","0.314"};
		
		for(String str:arr1){
			if(Pattern.matches(Float,str)){
				System.out.println(str+"�Ǹ�������");
			}
			else{
				System.out.println(str+"�Ǹ�������");
			}
		}
		
		String[] arr2={"1@2.3","a@b.c.d","a@sina.com.cn","df@163.com","ceocfoufo@sohu.com","asdd@dd.org","1","1.2@@3.4","1.2.345"};
		
		for(String str:arr2){
			if(Pattern.matches(Email,str)){
				System.out.println(str+"���ʼ�");
			}
			else{
				System.out.println(str+"���ʼ�");
			}
		}
		
		String[] arr3={"15998607451","1234567890","2","21","321312","3232","25998607451","13898417953","13378906773","16888888888","21","ad2",};
		
		for(String str:arr3){
			if(Pattern.matches(Mobile,str)){
				System.out.println(str+"���ֻ�");
			}
			else{
				System.out.println(str+"���ֻ�");
			}
		}
	}
}