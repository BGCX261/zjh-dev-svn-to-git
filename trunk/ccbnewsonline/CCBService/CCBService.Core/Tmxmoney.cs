using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CCBService.Core
{
    public class TmxmoneySummary
    {
        public string index;
        public string updateTime;
        public string change;
        public string volume;
        public string dayLow;
        public string dayHight;
    }

    public class Tmxmoney
    {
        static public TmxmoneySummary Parse(string source)
        {
            TmxmoneySummary ts = new TmxmoneySummary();

            int index, index2, index3;
            string content = string.Empty;

            // Index
            index = source.IndexOf("<div class=\"qm-last-date\">");
            index2 = source.IndexOf("<span>", index);
            index3 = source.IndexOf("</span>", index);
            content = source.Substring(index2 + "<span>".Length, index3 - index2 - "<span>".Length);
            ts.index = content;

            // Update date
            index = source.IndexOf("<div class=\"date\">");
            index2 = source.IndexOf(">", index);
            index3 = source.IndexOf("</div>", index);
            content = source.Substring(index2 + 1, index3 - index2 - 1).Trim();
            ts.updateTime = content;

            // Get change
            index = source.IndexOf("Change: <span>");
            index2 = source.IndexOf(">", index);
            index3 = source.IndexOf(")", index);
            content = source.Substring(index2 + 1, index3 - index2).Trim();
            ts.change = content;

            // Get volume
            index = source.IndexOf("Volume:");
            index2 = source.IndexOf(">", index);
            index3 = source.IndexOf("</span>", index);
            content = source.Substring(index2 + 1, index3 - index2 - 1).Trim();
            ts.volume = content;

            // Get day low
            index = source.IndexOf("Day Low<br>");
            index2 = source.IndexOf("<strong>", index);
            index3 = source.IndexOf("</strong>", index);
            content = source.Substring(index2 + "<strong>".Length, index3 - index2 - "</strong>".Length + 1).Trim();
            ts.dayLow = content;

            // Get day high
            index = source.IndexOf("Day High<br>");
            index2 = source.IndexOf("<strong>", index);
            index3 = source.IndexOf("</strong>", index);
            content = source.Substring(index2 + "<strong>".Length, index3 - index2 - "</strong>".Length + 1).Trim();
            ts.dayHight = content;

            return ts;
        }
    }
}
