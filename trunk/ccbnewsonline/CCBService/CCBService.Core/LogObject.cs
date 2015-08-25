using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CCBService.Core
{
    public interface LogObject
    {
        // Initialize Log object
        void Initialize();
        // Destroy Log object
        void Destroy();
        // Log output
        void LogTrace(string szMes);
        void LogWarning(string szMes);
        void LogError(string szMes);
        void LogComment(string szMes);
    }
}
