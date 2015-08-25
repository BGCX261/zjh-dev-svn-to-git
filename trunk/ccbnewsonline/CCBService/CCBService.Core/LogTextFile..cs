using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CCBService.Core
{
    public class LogTextFile : LogObject
    {
        protected string m_logFileName = "LogTextFile.txt";
        public string logFileName { get { return m_logFileName; } }

        public LogTextFile()
        {
        }

        public LogTextFile(string logFileName)
        {
            m_logFileName = logFileName;
        }

        // Initialize Log object
        public void Initialize()
        {
            using (StreamWriter sw = new StreamWriter(m_logFileName, false, Encoding.UTF8))
            {
                OutTimestamp(sw);
                sw.WriteLine();
                sw.WriteLine("-----------------------------");
                sw.Dispose();
            }
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

        private void OutTimestamp(StreamWriter sw)
        {
            if (sw != null)
            {
                sw.Write(System.DateTime.Now.ToString("[yyyy/MM/dd HH:mm:ss]"));
            }
        }

        private void LogOutout(string szMes, string szType)
        {
            if (szMes.Length != 0 && szType.Length != 0)
            {
                using (StreamWriter sw = new StreamWriter(logFileName, true, Encoding.UTF8))
                {
                    OutTimestamp(sw);
                    sw.WriteLine("[{0}]: {1}", szType, szMes);
                    sw.Close();
                    sw.Dispose();
                }
            }
        }
    }
}
