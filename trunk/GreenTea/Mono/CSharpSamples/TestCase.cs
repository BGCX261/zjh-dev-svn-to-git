using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

public class TestCase
{
    public TestCase()
    {
        Console.WriteLine("TestCase::TestCase");
    }

    ~TestCase()
    {
        Console.WriteLine("TestCase::~TestCase");
    }

    //[MethodImplAttribute(MethodImplOptions.InternalCall)]
    [DllImport("UnManagedCode")]
    extern static int TestAdd(int a, int b);
    [DllImport("UnManagedCode")]
    extern static int TestSub(int a, int b);

    [MethodImplAttribute(MethodImplOptions.InternalCall)]
    extern static int TestPrintAdd(int a, int b);

    public void OnPreStart()
    {
        Console.WriteLine("TestCase::OnPreStart");
        Console.WriteLine("TestCase::OnStart.TestPrintAdd = {0}", TestCase.TestPrintAdd(10, 20));
    }

    public void OnStart()
    {
        Console.WriteLine("TestCase::OnStart.Before TestPrint1");
        Console.WriteLine("TestCase::OnStart.TestAdd = {0}", TestCase.TestAdd(10, 20));
        Console.WriteLine("TestCase::OnStart.TestSub = {0}", TestCase.TestSub(10, 20));
        Console.WriteLine("TestCase::OnStart.After TestPrint1");
        Console.WriteLine("TestCase::OnStart");
    }

    public void OnUpdate()
    {
        Console.WriteLine("TestCase::OnUpdate");

        Console.WriteLine("10 + 20 = {0}", TestCaseMath.Add(10, 20));
    }

    public void OnDestroy()
    {
        Console.WriteLine("TestCase::OnDestroy");
    }
}
