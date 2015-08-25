package main;

import java.io.*;
import java.net.InetSocketAddress;
import java.nio.charset.Charset;
import org.apache.mina.core.service.*;
import org.apache.mina.transport.socket.nio.*;
import org.apache.mina.filter.logging.*;
import org.apache.mina.filter.codec.*;
import org.apache.mina.filter.codec.textline.*;
import server.*;

public class MessageServer
{
	private static final int nDefaultPort = 9123; 
	public static void main(String[] args) throws IOException 
	{
		IoAcceptor acceptor = new NioSocketAcceptor();
		acceptor.getFilterChain().addLast("logger", new LoggingFilter());
		acceptor.getFilterChain().addLast("codec", new ProtocolCodecFilter(new TextLineCodecFactory(Charset.forName( "UTF-8" ))));
		acceptor.setHandler(new MessageServerHandler());
		acceptor.setDefaultLocalAddress(new InetSocketAddress(nDefaultPort));
		// Start listening
		acceptor.bind(); 
	}
}
