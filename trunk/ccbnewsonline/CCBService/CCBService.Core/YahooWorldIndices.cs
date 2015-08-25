using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace CCBService.Core
{
    public class YahooWorldIndices
    {
        public class YahooWorldIndexObject
        {
            // Regular expressions
            private static Regex m_regexSymbol = new Regex(@">[A-Z^.-]+<");
            private static Regex m_regexName = new Regex(@">[/',\%\(\)A-Za-z0-9 \.&,;-]+<");
            private static Regex m_regexLastTrade = new Regex(@">([0-9]*,?)*[0-9]+\.[0-9]+<");
            private static Regex m_regexChange = new Regex(@"\d+\.\d+");

            public string symbol = string.Empty;
            public string name = string.Empty;
            public string lastTrade = string.Empty;
            public string lastTradeTime = string.Empty;
            public string change = string.Empty;
            public string changePercent = string.Empty;

            public bool Parse(string trContent)
            {
                string[] parts = trContent.Split(new string[] { "/td>" }, StringSplitOptions.RemoveEmptyEntries);

                // Symbol
                if (m_regexSymbol.IsMatch(parts[0]))
                    symbol = TrimBrackets(m_regexSymbol.Matches(parts[0])[0].Value);
                else
                    return false;

                // Name
                if (m_regexName.IsMatch(parts[1]))
                    name = TrimBrackets(m_regexName.Matches(parts[1])[0].Value);
                else
                    return false;

                // Last trade
                if (m_regexLastTrade.IsMatch(parts[2]))
                    lastTrade = TrimBrackets(m_regexLastTrade.Matches(parts[2])[0].Value);
                else
                    return false;

                // Change
                if (m_regexChange.IsMatch(parts[3]))
                {
                    MatchCollection mc = m_regexChange.Matches(parts[3]);
                    change = mc[0].Value;
                    changePercent = mc[1].Value;
                }
                else
                    return false;

                return true;
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

        public static List<YahooWorldIndexObject> Parse(string sourceContent)
        {
            List<YahooWorldIndexObject> listStockObjects = new List<YahooWorldIndexObject>();

            string[] parts = sourceContent.Split(new string[] { "/tr>" }, StringSplitOptions.RemoveEmptyEntries);
            for (int i = 0; i < parts.Length; i++)
            {
                try
                {
                    int length = 0;
                    string content = parts[i];
                    int trStart = content.IndexOf("<tr>");
                    int trEnd = content.IndexOf("</tr>");
                    if (trStart < 0 && trEnd < 0)
                    {
                        continue;
                    }
                    if (trEnd < 0)
                    {
                        trEnd = content.Length - 1;
                        length = trEnd - trStart;
                    }
                    else
                    {
                        length = trEnd + "</tr>".Length - trStart;
                    }
                    string trContent = content.Substring(trStart, length);

                    YahooWorldIndexObject so = new YahooWorldIndexObject();
                    if (so.Parse(trContent))
                        listStockObjects.Add(so);

                    //Console.WriteLine("[{0}]:{1},{2},{3},{4},{5},{6},{7}", i, so.symbol, so.name, so.lastTrade, so.lastTreadTime, so.change, so.changePercent, so.volume);
                }
                catch (Exception ex)
                {
                    Console.WriteLine("index={0},{1}", i, ex.Message);
                    //throw ex;
                }
            }

            return listStockObjects;
        }

        public static string Load(string fileName)
        {
            using (System.IO.StreamReader sr = new System.IO.StreamReader(fileName))
            {
                string source = sr.ReadToEnd();
                int tbodyStartIndex = source.IndexOf("<tbody><tr><td class=\"first\">");
                int tbodyEndIndex = -1;
                if (tbodyStartIndex >= 0)
                    tbodyEndIndex = source.IndexOf("</tbody>", tbodyStartIndex);
                if (tbodyStartIndex >= 0 && tbodyEndIndex >= 0)
                {
                    source = source.Substring(tbodyStartIndex + "<tbody>".Length, tbodyEndIndex - tbodyStartIndex - "</tbody>".Length - "</td>".Length + 1);
                }
                return source;
            }
        }

        public static string ParseTBody(string source)
        {
            int tbodyStartIndex = source.IndexOf("<tbody><tr><td class=\"first\">");
            int tbodyEndIndex = -1;
            if (tbodyStartIndex >= 0)
                tbodyEndIndex = source.IndexOf("</tbody>", tbodyStartIndex);
            if (tbodyStartIndex >= 0 && tbodyEndIndex >= 0)
            {
                source = source.Substring(tbodyStartIndex + "<tbody>".Length, tbodyEndIndex - tbodyStartIndex - "</tbody>".Length - "</td>".Length + 1);
            }
            return source;
        }
    }
}
