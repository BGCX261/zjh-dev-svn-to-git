using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace CCBService.Core
{
    public class YahooSpecificStock
    {
        public class YahooSpecificStockObject
        {
            private static Regex m_regexName = new Regex(@">[/',\%\(\)A-Za-z0-9 \.&,;-]+<");
            private static Regex m_regexChanges = new Regex(@"\d+\.\d+");

            public string symbol = string.Empty;
            public string name = string.Empty;
            public string current = string.Empty;
            public string change = string.Empty;
            public string changePercent = string.Empty;
            public string chsname = string.Empty;

            public bool Parse(string source)
            {
                int indexStart = source.IndexOf("<div class=\"title\">");
                int indexEnd = source.IndexOf("<span class=\"fb-like-button\">", indexStart);
                if (indexStart >= 0 && indexEnd >= 0)
                {
                    string content = source.Substring(indexStart, indexEnd - indexStart);

                    // Name
                    if (m_regexName.IsMatch(content))
                        name = TrimBrackets(m_regexName.Matches(content)[0].Value);
                    else
                        return false;

                    // Changes
                    if (m_regexChanges.IsMatch(content))
                    {
                        MatchCollection mc = m_regexChanges.Matches(content);
                        current = mc[0].Value;
                        change = mc[1].Value;
                        changePercent = mc[2].Value;
                    }
                    else
                        return false;

                    return true;
                }
                return false;
            }

            private string TrimBrackets(string source)
            {
                int start = source.IndexOf('>');
                int end = source.IndexOf('<');
                if (start < 0 || end < 0)
                    return string.Empty;
                return source.Substring(start + 1, end - start - 1);
            }
        }
    }
}
