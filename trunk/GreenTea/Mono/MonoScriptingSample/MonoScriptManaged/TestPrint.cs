using System;
using System.Runtime.CompilerServices;
using System.Text;

// Remove this namespace MonoScriptManaged because mono_add_internal_call doesn't support namespace specified
namespace GTEngineManaged
{
    public class TestPrint
    {
        public TestPrint()
        {
        }
                
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern int MathIntAdd(int a, int b);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern int MathIntSub(int a, int b);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern int MathIntMul(int a, int b);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern int MathIntDiv(int a, int b);
    }
}
