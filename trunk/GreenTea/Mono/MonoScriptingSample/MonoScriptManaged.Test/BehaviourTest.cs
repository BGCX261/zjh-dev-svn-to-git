using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.CompilerServices;
using GTEngineManaged;

public class BehaviourTest : GTBehaviour
{
    public int prop1 = 789;
    public string prop2 = "default-prop2";

    public BehaviourTest()
    {
    }

    ~BehaviourTest()
    {
    }

    public override void OnPreStart()
    {
        Console.WriteLine("BehaviourTest::OnPreStart");
    }

    public override void OnStart()
    {
        Console.WriteLine("BehaviourTest::OnStart");
    }

    public override void OnUpdate()
    {
        Console.WriteLine("BehaviourTest::OnUpdate");
    }

    public override void OnDestroy()
    {
        Console.WriteLine("BehaviourTest::OnDestroy");
    }
}
