using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.CompilerServices;

namespace GTEngineManaged
{
    public class GTGameObject
    {
        public GTGameObject(string name)
        {
            GTInternalCall.GT_CreateGameObject(this, name);
        }

        ~GTGameObject()
        {
            //GT_CreateGameObject(this, name);
            Console.WriteLine("~GTGameObject called");
        }

        // Get name
        public string name
        {
            get
            {
                return GTInternalCall.GT_GetGameObjectName(this);
            }
        }

        // Get/Set position
        public GTVector2 position
        {
            get
            {
                GTVector2 pos;
                GTInternalCall.GT_GetGameObjectPosition(this, out pos);
                return pos;
            }
            set
            {
                GTInternalCall.GT_SetGameObjectPosition(this, value.x, value.y);
            }
        }        

        // Add behaviour
        public GTBehaviour AddBehaviour(string className)
        {
            return GTInternalCall.GT_AddBehaviourGameObject(this, className);
        }
        public T AddBehaviour<T>() where T : GTBehaviour
        {
            return this.AddBehaviour(typeof(T).Name) as T;
        }

        // Find a game object
        static public GTGameObject FindGameObject(string goName)
        {
            return GTInternalCall.GT_FindGameObjectByName(goName);
        }

        // Destroy a game object
        static public void DestroyGameObject(GTGameObject go)
        {
            GTInternalCall.GT_DestroyGameObject(go);
        }
    }
}
