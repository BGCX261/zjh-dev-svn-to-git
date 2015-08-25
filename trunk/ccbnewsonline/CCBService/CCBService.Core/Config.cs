using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace CCBService.Core
{
    public class Stock
    {
        public Stock()
        {
        }

        public string url = string.Empty;
        public string table = string.Empty;
        public string source = string.Empty;
        public string market = string.Empty;
        public string type = string.Empty;
        public string desc = string.Empty;
    }

    public class Config
    {
        public Config(string name)
        {
            try
            {
                XmlDocument xd = new XmlDocument();
                xd.Load(name);

                connectionString = xd.SelectSingleNode("/Config/DB/ConnectionString").InnerText;
                
                XmlNodeList nodeList = xd.SelectNodes("/Config/Stocks/Stock");
                for (int i = 0; i < nodeList.Count; i++)
                {
                    Stock stock = new Stock();
                    stock.url = nodeList[i].Attributes[0].InnerText;
                    stock.table = nodeList[i].Attributes[1].InnerText;
                    stock.source = nodeList[i].Attributes[2].InnerText;
                    stock.market = nodeList[i].Attributes[3].InnerText;
                    stock.type = nodeList[i].Attributes[4].InnerText;
                    stock.desc = nodeList[i].Attributes[5].InnerText;

                    stocks.Add(stock);
                }

                xd = null;
            }
            catch (Exception)
            {
            }
        }

        public string connectionString = string.Empty;
        public List<Stock> stocks = new List<Stock>();
    }
}
