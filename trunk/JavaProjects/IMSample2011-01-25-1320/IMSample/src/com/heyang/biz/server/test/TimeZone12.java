package com.heyang.biz.server.test;

import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.TimeZone;


public class TimeZone12{
	public static void main(String[] args){
		Calendar cal = new GregorianCalendar(TimeZone.getTimeZone("London"));
	    
	    int hour12 = cal.get(Calendar.HOUR);         // 0..11
	    int minutes = cal.get(Calendar.MINUTE);      // 0..59
	    int seconds = cal.get(Calendar.SECOND);      // 0..59

	    System.out.println(hour12+":"+minutes+":"+seconds);
	}
}