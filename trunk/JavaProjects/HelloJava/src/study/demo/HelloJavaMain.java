/// Main class

package study.demo;

import java.io.*;
import study.log.ILogger;
import study.math.*;
import study.log.*;
import study.test.*;

public class HelloJavaMain
{
	public static void main(String arg[]) throws InterruptedException
	{
		/*
		BasicMath bm = new MathNormal();
		float ra = bm.Add(2.0f, 4.0f);
		float rs = bm.Sub(2.0f, 4.0f);
		float rm = bm.Mul(2.0f, 4.0f);
		float rd = bm.Div(2.0f, 4.0f);

		System.out.println("Hello Java World !");
		System.out.format("Add = %f\n", ra);
		System.out.format("Sub = %f\n", rs);
		System.out.format("Mul = %f\n", rm);
		System.out.format("Div = %f\n", rd);
		*/
		
		//TestBase tst = new ThreadSleepTest();
		TestBase tst = new LogTest();
		tst.Start();
		tst.Run();
		tst.Destroy();
	}
}

