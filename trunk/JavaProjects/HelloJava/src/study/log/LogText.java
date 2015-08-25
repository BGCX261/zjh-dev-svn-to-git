package study.log;

import java.io.*;

public class LogText implements ILogger
{
	private String mFileName = new String("LogText.txt");
	
	@Override public Boolean Initialize()
	{
		return true;
	}	

	@Override public void Log(String str)
	{
		try
		{
			/*
			FileOutputStream fos = new FileOutputStream(mFileName);
			for(int i=0; i<str.length(); i++)
			{
				//fos.w write(str[i]);
			}
			*/
			RandomAccessFile raf = new RandomAccessFile(mFileName, "rw");
			raf.writeBytes(str);
			raf.writeBytes("\n");
			raf.close();
		}
		catch(IOException e)
		{
		}
		finally
		{
		}
	}
	
	@Override public Boolean Destroy()
	{
		System.out.println("LogConsole.Destroy");
		return true;
	}
}
