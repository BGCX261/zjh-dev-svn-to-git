using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace CCBService.Core
{
    public class YahooCSV
    {
        public YahooCSV()
        {
        }

        public bool Initialize(string url)
        {
            try
            {
                // Download the CSV
                string pageContent = Utility.DownloadFromUrl(url);
                if (pageContent.Length == 0)
                    return false;
                // Fields
                string[] parts = pageContent.Split(',');
                if (parts.Length == 0)
                    return false;
                foreach (string s in parts)
                {
                    fields.Add(s.Replace('\"', ' ').Trim());
                }
            }
            catch (Exception)
            {
                return false;
            }

            return true;
        }

        public string CreateInsertQuery(string tableName, XmlNode xn)
        {
            // fieldIndex
            string[] fieldIndexParts = fieldIndex.Split(',');
            if (fieldIndexParts.Length == 0)
                return string.Empty;
            int[] fieldIndexTemp = new int[fieldIndexParts.Length];
            for (int i = 0; i < fieldIndexTemp.Length; i++)
                fieldIndexTemp[i] = int.Parse(fieldIndexParts[i]);
            // extraField
            string[] extraFieldsParts = extraField.Split(',');
            string[] extraFieldsTemp = new string[extraFieldsParts.Length];
            for (int i = 0; i < extraFieldsParts.Length; i++)
                extraFieldsTemp[i] = extraFieldsParts[i];

            //string queryInsertTemp = "INSERT INTO stock_summary (stype,field1,field2,field3,field4,field5,field6) VALUES(N'{0}',N'{1}',N'{2}',N'{3}',N'{4}',N'{5}',N'{6}')";
            string queryInsertTemp = string.Format("INSERT INTO {0} (stype", tableName);
            for (int i = 0; i < (fieldIndexTemp.Length + extraFieldsTemp.Length); i++)
                queryInsertTemp += string.Format(",field{0}", i + 1);
            queryInsertTemp += string.Format(") VALUES(N'{0}'", stype);
            // fieldIndex
            for (int i = 0; i < fieldIndexTemp.Length; i++)
                queryInsertTemp += string.Format(",N'{0}'", fields[fieldIndexTemp[i]]);
            // extraField
            for (int i = 0; i < extraFieldsTemp.Length; i++)
                queryInsertTemp += string.Format(",N'{0}'", xn.Attributes[extraFieldsTemp[i]].InnerText);
            queryInsertTemp += ")";

            return queryInsertTemp;
        }

        public string url = string.Empty;
        public string symbol = string.Empty;
        public string stype = string.Empty;
        public string name = string.Empty;
        public string fieldIndex = string.Empty;
        public string extraField = string.Empty;
        public List<string> fields = new List<string>();
    }
}
