package study.test;

public class TestManager
{
	private static TestManager mInstance = new TestManager();
	
	public static TestManager GetInstance()
	{
		return mInstance;
	}
	
	public void Initialize()
	{
		System.out.println("TestManager.Initialize called");
	}
	
	public void Destroy()
	{
		System.out.println("TestManager.Destroy called");
	}
}
