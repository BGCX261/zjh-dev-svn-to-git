using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.CompilerServices;

namespace GTEngineManaged
{
    public class GTInternalCall
    {
        // GTGameObject
        //
        // name
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern string GT_GetGameObjectName(GTGameObject go);
        // position
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void GT_SetGameObjectPosition(GTGameObject pgo, float x, float y);
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void GT_GetGameObjectPosition(GTGameObject pgo, out GTVector2 pos);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void GT_CreateGameObject(GTGameObject go, string name);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void GT_DestroyGameObject(GTGameObject go);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern GTBehaviour GT_AddBehaviourGameObject(GTGameObject go, string className);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern GTGameObject GT_FindGameObjectByName(string className);

        //[MethodImplAttribute(MethodImplOptions.InternalCall)]
        //public static extern string GT_GetGameObjectName(string s);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern int GT_GetGameObjectValue(int v);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern GTVector2 GT_GetGameObjectVector(float v);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern GTVector2C GT_GetGTVector2C(float x, float y);        
    }
}
