using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;

namespace CCBService.Core
{
    public class Utility
    {
        /// <summary>
        /// Extract all stock objects
        /// </summary>
        /// <param name="sourceContent"></param>
        /// <returns></returns>
        public static List<StockObject> ProcessStockObjectList(string sourceContent)
        {
            List<StockObject> listStockObjects = new List<StockObject>();

            string[] parts = sourceContent.Split(new string[] { "/tr>" }, StringSplitOptions.RemoveEmptyEntries);
            //Console.WriteLine("parts.Length = {0}", parts.Length);
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

                    StockObject so = new StockObject();
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


        /// <summary>
        /// Download a html from a specified URL
        /// </summary>
        /// <param name="url"></param>
        /// <returns></returns>
        static public string DownloadFromUrl(string url)
        {
            try
            {
                WebClient wc = new WebClient();
                Byte[] pageData = wc.DownloadData(url);
                return System.Text.Encoding.Default.GetString(pageData);
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }


        /// <summary>
        /// Extract the content between <tbody>...</tbody>
        /// </summary>
        /// <param name="pageContent"></param>
        /// <returns></returns>
        static public string ExtractContentBody(string pageContent)
        {
            int tbodyIndexStart = pageContent.IndexOf("<tbody>");
            int tbodyIndexEnd = pageContent.IndexOf("</tbody>", tbodyIndexStart);
            if (tbodyIndexStart < 0 || tbodyIndexEnd < 0)
                return string.Empty;
            // Extract the content between <tbody></tbody>
            return pageContent.Substring(
                tbodyIndexStart + "<tbody>".Length,
                tbodyIndexEnd - (tbodyIndexStart + "<tbody>".Length)
                );
        }
    }
}
