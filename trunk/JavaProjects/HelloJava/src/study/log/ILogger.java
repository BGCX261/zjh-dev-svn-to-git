package study.log;

public interface ILogger
{
	Boolean Initialize();
	void Log(String str);
	Boolean Destroy();
}
