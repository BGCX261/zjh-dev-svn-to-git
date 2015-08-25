package study.test;

import java.io.*;
import study.log.*;

public class LogTest extends TestBase
{
	@Override public void Start()
	{
		super.Start();
	}
	
	@Override public void Run()
	{
		ILogger log = new LogText();
		log.Initialize();
		log.Log("This is called from HelloJavaMain.");
		log.Destroy();		
	}
	
	@Override public void Destroy()
	{
		super.Destroy();
	}
}
