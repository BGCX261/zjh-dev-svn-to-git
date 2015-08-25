using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.CompilerServices;

namespace GreenTeaEngine
{
    public class InternalCall
    {
        // Debug
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void InternalCall_DebugLogTrace(int level, string msg);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void InternalCall_DebugLogWarning(int level, string msg);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void InternalCall_DebugLogError(int level, string msg);
    }
}
