package study.test;

public class ThreadSleepTest extends TestBase
{
	@Override public void Start()
	{
		super.Start();
	}
	
	@Override public void Run()
	{				
		try
		{
			Thread t = Thread.currentThread();
			System.out.format("Thread Name = %s\n", t.getName());
			Thread.sleep(1000);
			System.out.println("Thread...1");
			Thread.sleep(1000);
			System.out.println("Thread...2");
			Thread.sleep(1000);
			System.out.println("Thread...3");
			Thread.sleep(1000);
			System.out.println("Thread...4");
		} catch (InterruptedException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
	}
	
	@Override public void Destroy()
	{
		super.Destroy();
	}
}
