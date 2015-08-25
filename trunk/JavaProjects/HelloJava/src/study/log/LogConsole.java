package study.log;

public class LogConsole implements ILogger
{
	@Override public Boolean Initialize()
	{
		System.out.println("LogConsole.Initialize");
		return true;
	}	

	@Override public void Log(String str)
	{
		System.out.println("LogConsole.Log = " + str);
	}
	
	@Override public Boolean Destroy()
	{
		System.out.println("LogConsole.Destroy");
		return true;
	}
}
