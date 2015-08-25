using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using GreenTeaEngine;

public class StartPointClass
{
    public StartPointClass()
    {
        Console.WriteLine("StartPointClass::StartPointClass");
    }

    ~StartPointClass()
    {
        Console.WriteLine("StartPointClass::~StartPointClass");
    }

    public void OnPreStart()
    {
        GTDebug.LogTrace(1, "StartPointClass.OnPreStart: This log is testing GTDebug.LogTrace");
        GTDebug.LogWarning(1, "StartPointClass.OnPreStart: This log is testing GTDebug.LogWarning");
        GTDebug.LogError(1, "StartPointClass.OnPreStart: This log is testing GTDebug.LogError");
        Console.WriteLine("StartPointClass::OnPreStart");
        //Console.WriteLine("TestCase::OnStart.TestPrintAdd = {0}", TestCase.TestPrintAdd(10, 20));
    }

    public void OnStart()
    {
        Console.WriteLine("StartPointClass::OnStart.Before TestPrint1");
        //Console.WriteLine("TestCase::OnStart.TestAdd = {0}", TestCase.TestAdd(10, 20));
        //Console.WriteLine("TestCase::OnStart.TestSub = {0}", TestCase.TestSub(10, 20));
        Console.WriteLine("StartPointClass::OnStart.After TestPrint1");
        Console.WriteLine("StartPointClass::OnStart");
    }

    public void OnUpdate()
    {
        Console.WriteLine("StartPointClass::OnUpdate");
    }

    public void OnDestroy()
    {
        Console.WriteLine("StartPointClass::OnDestroy");
    }
}
