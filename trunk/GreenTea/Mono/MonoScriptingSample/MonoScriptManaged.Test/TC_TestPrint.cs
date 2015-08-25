using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using GTEngineManaged;

public class Vector2C
{
    public Vector2C(float x, float y)
    {
        this.x = x;
        this.y = y;
    }

    public float x;
    public float y;
}

public class TC_TestPrint
{
    public TC_TestPrint()
    {
        Console.WriteLine("TC_TestPrint::TestCase");
    }

    ~TC_TestPrint()
    {
        Console.WriteLine("TC_TestPrint::~TestCase");
    }

    public void OnPreStart()
    {        
        Console.WriteLine("TC_TestPrint::OnPreStart");
        //Console.WriteLine("TestCase::OnStart.TestPrintAdd = {0}", TestCase.TestPrintAdd(10, 20));

        // Test GTGameObject
        //GTVector2 posNew = new GTVector2(123.6f, 456.9f);
        GTGameObject go = new GTGameObject("go001");

        // Test GTBehaviour
        //go.AddBehaviour("BehaviourTest");
        BehaviourTest behaviourTest = go.AddBehaviour<BehaviourTest>();
        if (behaviourTest != null)
        {
            Console.WriteLine("behaviourTest.p1 = {0}", behaviourTest.prop1);
            Console.WriteLine("behaviourTest.p2 = {0}", behaviourTest.prop2);
        }
        else
            Console.WriteLine("behaviourTest not found");

        // Test properties
        Console.WriteLine("go.name = {0}", go.name);
        go.position = new GTVector2(78.1f, 56.2f);
        Console.WriteLine("go.position = ({0},{1})", go.position.x, go.position.y);
        GTGameObject goFound = GTGameObject.FindGameObject("go001");
        if (goFound != null)
        {
            Console.WriteLine("goFound.name = {0}", goFound.name);
            Console.WriteLine("goFound.position = ({0},{1})", goFound.position.x, goFound.position.y);
        }
        else
            Console.WriteLine("goFound not found");

        // Destroy game object
        //GTGameObject.DestroyGameObject(go);
        
        goFound = null;
        go = null;

        Vector2C vc = TC_TestPrint.GetVector2C(67.3f, 89.2f);
        Console.WriteLine("vc = ({0},{1})", vc.x, vc.y);

        GTVector2C gtvc = GTInternalCall.GT_GetGTVector2C(167.3f, 189.2f);
        Console.WriteLine("gtvc = ({0},{1})", gtvc.x, gtvc.y);

        /*
        Console.WriteLine("Test name = {0}", GTGameObject.GT_GetGameObjectName("tc_test_print"));
        Console.WriteLine("Test value = {0}", GTGameObject.GT_GetGameObjectValue(45));
        GTVector2 v2 = GTGameObject.GT_GetGameObjectVector(8.0f);
        Console.WriteLine("v2 = ({0},{1})", v2.x, v2.y);
         * */

        /*
        GTVector2 pos = new GTVector2(100.2f, 200.7f);
        GTVector2 posRef = new GTVector2();
        GTVector2 posOut = new GTVector2();
        GTGameObject.GT_CreateGameObject(goName1);
        //GTGameObject.GT_SetPosition(goName1, 10.4f, 24.7f);
        GTGameObject.GT_SetPosition2(goName1, pos);
        //GTGameObject.GT_SetPosition3(goName1, ref pos);
        GTGameObject.GT_GetPositionRef(goName1, ref posRef);
        GTGameObject.GT_SetPosition(goName1, 10.4f, 24.7f);
        GTGameObject.GT_GetPositionOut(goName1, out posOut);
        GTGameObject.GT_DestroyGameObject(goName1);

        Console.WriteLine("posGet = ({0},{1})", posRef.x, posRef.y);
        Console.WriteLine("posOut = ({0},{1})", posOut.x, posOut.y);

        GTVector2 vthis = new GTVector2(100.0f, 200.0f);
        Console.WriteLine("vthis = ({0},{1})", vthis.x, vthis.y);
        vthis.SetOffset(3.0f, 5.0f);
        Console.WriteLine("vthis = ({0},{1})", vthis.x, vthis.y);
         * */
    }

    public void OnStart()
    {
        Console.WriteLine("TC_TestPrint::OnStart.Before TestPrint1");
        Console.WriteLine("TC_TestPrint::OnStart.After TestPrint1");
        Console.WriteLine("TC_TestPrint::OnStart");

        //GTVector2 vr2 = new GTVector2(10, 20) + new GTVector2(1, 2);
        //Console.WriteLine(string.Format("vr2 = {0}", vr2.ToString()));
    }

    public void OnUpdate()
    {
        Console.WriteLine("TC_TestPrint::OnUpdate");
    }

    public void OnDestroy()
    {
        Console.WriteLine("TC_TestPrint::OnDestroy");
    }

    [MethodImplAttribute(MethodImplOptions.InternalCall)]
    public static extern Vector2C GetVector2C(float x, float y);        
}
