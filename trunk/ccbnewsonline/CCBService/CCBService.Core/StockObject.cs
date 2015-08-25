using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace CCBService.Core
{
    public class StockObject
    {
        // Regular expressions
        private static Regex m_regexSymbol = new Regex(@">[A-Z .-]+<");
        private static Regex m_regexName = new Regex(@">[/',\%\(\)A-Za-z0-9 \.&,;-]*<");
        private static Regex m_regexLastTrade = new Regex(@">([0-9]*,?)*[0-9]+\.[0-9]+<");
        private static Regex m_regexLastTradeTime = new Regex(@">([A-Za-z]* [0-9]*, )*\d{1,2}:\d{1,2}[AP]M \w+<");
        private static Regex m_regexChange = new Regex(@"\d+\.\d+");
        private static Regex m_regexVolume = new Regex(@">([0-9]*,?)*[0-9]+<");

        public StockObject()
        {            
        }

        public bool Parse(string trContent)
        {
            string[] parts = trContent.Split(new string[] { "/td>" }, StringSplitOptions.RemoveEmptyEntries);
            
            // Symbol
            if (m_regexSymbol.IsMatch(parts[0]))
                m_symbol = TrimBrackets(m_regexSymbol.Matches(parts[0])[0].Value);
            else
                return false;

            // Name
            if (m_regexName.IsMatch(parts[1]))
            {
                m_name = TrimBrackets(m_regexName.Matches(parts[1])[0].Value);
                if (m_name.IndexOf("'") >= 0)
                {
                    while (m_name.IndexOf("'") >= 0)
                    {
                        m_name = m_name.Replace("'", "{##}");
                    }                    
                }
                m_name = m_name.Replace("{##}", "''");
            }
            else
                return false;

            // Last trade
            if (m_regexLastTrade.IsMatch(parts[2]))
                m_lastTrade = TrimBrackets(m_regexLastTrade.Matches(parts[2])[0].Value);
            else
                return false;
            if (m_regexLastTradeTime.IsMatch(parts[2]))
                m_lastTradeTime = TrimBrackets(m_regexLastTradeTime.Matches(parts[2])[0].Value);
            else
                return false;

            // Change
            if (m_regexChange.IsMatch(parts[3]))
            {
                MatchCollection mc = m_regexChange.Matches(parts[3]);
                m_change = mc[0].Value;
                m_changePercent = mc[1].Value;
            }
            else
                return false;

            // Volume
            if (m_regexVolume.IsMatch(parts[4]))
                m_volume = TrimBrackets(m_regexVolume.Matches(parts[4])[0].Value);
            else
                return false;

            // YahooCSV
            string ycsvUrl = string.Format("http://download.finance.yahoo.com/d/quotes.csv?s={0}&f=sl1d1t1c1ohgv&e=.csv", m_symbol);
            YahooCSV ycsv = new YahooCSV();
            if (ycsv.Initialize(ycsvUrl))
            {
                m_lastTrade = ycsv.fields[1];
                m_change = ycsv.fields[4];
            }
            else
                Console.WriteLine("StockObject.Parse: Error: failed to load {0}", ycsvUrl);

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

        protected string m_symbol = string.Empty;
        protected string m_name = string.Empty;
        protected string m_lastTrade = string.Empty;
        protected string m_lastTradeTime = string.Empty;
        protected string m_change = string.Empty;
        protected string m_changePercent = string.Empty;
        protected string m_volume = string.Empty;

        public string symbol { get { return m_symbol; } }
        public string name { get { return m_name; } }
        public string lastTrade { get { return m_lastTrade; } }
        public string lastTreadTime { get { return m_lastTradeTime; } }
        public string change { get { return m_change; } }
        public string changePercent { get { return m_changePercent; } }
        public string volume { get { return m_volume; } }
    }
}
