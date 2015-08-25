package server;

import java.util.*;
import org.apache.mina.core.service.*;
import org.apache.mina.core.session.*;

public class MessageServerHandler extends IoHandlerAdapter
{
	@Override
	public void sessionCreated(IoSession session)
	{		
		System.out.println("Remote IP: " + session.getRemoteAddress().toString()); 
	}
	
	@SuppressWarnings("deprecation")
	@Override 
	public void messageReceived(IoSession session, Object message) throws Exception 
	{
		String str = message.toString();
		System.out.println("Message received: " + str);
		if(str.trim().equalsIgnoreCase("quit"))
		{
			// Close this session
			session.close(); 
			System.out.println("A session is closed");
			return;
		}
		Date date = new Date();
		session.write(date.toString());
		//System.out.println("Message written..."); 
	} 
}
