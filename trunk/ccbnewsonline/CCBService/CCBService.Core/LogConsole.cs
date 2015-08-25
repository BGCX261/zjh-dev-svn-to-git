using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CCBService.Core
{
    public class LogConsole : LogObject
    {
        public LogConsole()
        {
        }

        // Initialize Log object
        public void Initialize()
        {
        }

        // Destroy Log object
        public void Destroy()
        {
        }

        // Log output
        public void LogTrace(string szMes)
        {
            LogOutout(szMes, "TRACE");
        }

        public void LogWarning(string szMes)
        {
            LogOutout(szMes, "WARNING");
        }

        public void LogError(string szMes)
        {
            LogOutout(szMes, "ERROR");
        }

        public void LogComment(string szMes)
        {
            LogOutout(szMes, "COMMENT");
        }

        private void OutTimestamp()
        {
            Console.Write(System.DateTime.Now.ToString("[yyyy/MM/dd HH:mm:ss]"));
        }

        private void LogOutout(string szMes, string szType)
        {
            if (szMes.Length != 0 && szType.Length != 0)
            {
                OutTimestamp();
                Console.WriteLine("[{0}]: {1}", szType, szMes);
            }
        }
    }
}
