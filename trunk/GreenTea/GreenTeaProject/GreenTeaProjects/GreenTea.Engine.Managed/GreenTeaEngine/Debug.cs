using System;

namespace GreenTeaEngine
{
    public class Debug
    {
        public Debug()
        {
        }

        public static void LogTrace(int level, string message)
        {
            InternalCall.InternalCall_DebugLogTrace(level, message);
        }
        public static void LogWarning(int level, string message)
        {
            InternalCall.InternalCall_DebugLogWarning(level, message);
        }
        public static void LogError(int level, string message)
        {
            InternalCall.InternalCall_DebugLogError(level, message);
        }

        //[MethodImpl(MethodImplOptions.InternalCall), WrapperlessIcall]
        //[MethodImpl(MethodImplOptions.InternalCall), WrapperlessIcall]
        //public static extern void ClearDeveloperConsole();
        //[MethodImpl(MethodImplOptions.InternalCall), WrapperlessIcall]

        //[MethodImpl(MethodImplOptions.InternalCall), WrapperlessIcall]
        //private static extern void Internal_Log(int level, string msg, [Writable] Object obj);
        //[MethodImpl(MethodImplOptions.InternalCall), WrapperlessIcall]
        //private static extern void Internal_LogException(Exception exception, [Writable] Object obj);
                
        /*
        public static void Log(object message, Object context);
        public static void LogError(object message);
        public static void LogError(object message, Object context);
        public static void LogException(Exception exception);
        public static void LogException(Exception exception, Object context);
        public static void LogWarning(object message);
        public static void LogWarning(object message, Object context);
         * */

        // Properties
        //public static bool developerConsoleVisible { [MethodImpl(MethodImplOptions.InternalCall), WrapperlessIcall] get; [MethodImpl(MethodImplOptions.InternalCall), WrapperlessIcall] set; }
        //public static bool isDebugBuild { [MethodImpl(MethodImplOptions.InternalCall), WrapperlessIcall] get; }
    }
}
