using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net;
using System.Text.RegularExpressions;
using System.Xml;
using CCBService.Core;

namespace CCBServiceConsole
{
    class Program
    {
        static LogObject logObject = new LogTextFile("CCBServiceConsole.log");

        static void Process_stock_summary(ref Config config)
        {
            /*
                using (StreamReader sr = new StreamReader("tmxmoney.html"))
                {
                    string content = sr.ReadToEnd();
                    TmxmoneySummary ts = Tmxmoney.Parse(content);
                }
                 * */

            string tmxmoneyUrl = "http://web.tmxmoney.com/quote.php?qm_symbol=^TSX&locale=EN";
            Console.WriteLine("Downloading...{0}", tmxmoneyUrl);
            string pageContent = Utility.DownloadFromUrl(tmxmoneyUrl);
            TmxmoneySummary ts = Tmxmoney.Parse(pageContent);
            
            DBConnection dbConnection = null;
            try
            {
                Console.WriteLine("Connection string = {0}", config.connectionString);
                dbConnection = new DBConnection(config.connectionString);
                if (dbConnection.Connect())
                {
                    // Delete all records
                    int rowsDelete = dbConnection.ExecuteQuery("DELETE FROM stock_summary WHERE stype='tmxmoney'");
                    // Insert records
                    string queryInsertTemp = "INSERT INTO stock_summary (stype,field1,field2,field3,field4,field5,field6) VALUES(N'{0}',N'{1}',N'{2}',N'{3}',N'{4}',N'{5}',N'{6}')";
                    string queryInsert = string.Format(queryInsertTemp, "tmxmoney", ts.index, ts.updateTime, ts.change, ts.volume, ts.dayLow, ts.dayHight);
                    int rowsInserted = dbConnection.ExecuteQuery(queryInsert);
                    Console.WriteLine("rowsInserted = {0}", rowsInserted);
                    dbConnection.Close();
                }
            }
            catch (Exception ex)
            {
                dbConnection.Close();
                Console.WriteLine("Exception: {0}", ex.Message);
            }
        }

        static void Main(string[] args)
        {
            try
            {
                /*                
                //LogObject logObject = new LogConsole();
                logObject.Initialize();
                logObject.LogComment("This is a comment.");
                logObject.LogTrace("This is a trace.");
                logObject.LogWarning("This is a warning.");
                logObject.LogError("This is an error !");
                
                return;
                 * */

                // If a config.xml is specified, use it. Otherwise, use default.
                string configName = (args.Length == 0) ? "config.xml" : args[0];
                if (!File.Exists(configName))
                {
                    // Config.xml doesn't exist
                    Console.WriteLine("ERROR: Config file = {0} doesn't exist.", configName);
                    return;
                }
                Console.WriteLine("Config file = {0}", configName);

                // Load config file
                Config config = new Config(configName);
                Console.WriteLine("Config file.connectionString = {0}", config.connectionString);
                Console.WriteLine("-----------------------------------------");

                //------------------------------------------
                // Process items in ConfigYahooCSV.xml
                //------------------------------------------
                ProcessYahooCSV(ref config);
                
                //------------------------------------------
                // Process
                //------------------------------------------
                ProcessYahooCompositeStock(ref config);

                //------------------------------------------
                // Yahoo world indices
                //------------------------------------------
                //ProcessYahooWorldIndices(ref config);
                                
                //------------------------------------------
                // stock_summary
                //------------------------------------------
                Process_stock_summary(ref config);
                
                //------------------------------------------
                // Gainers/Losers
                //------------------------------------------
                for (int indexStock = 0; indexStock < config.stocks.Count; indexStock++)
                {
                    Console.WriteLine("Downloading...{0}", config.stocks[indexStock].url);
                    Console.WriteLine("smarket = {0}, stype = {1}", config.stocks[indexStock].market, config.stocks[indexStock].type);

                    // Download the content based on the url
                    string pageContent = Utility.DownloadFromUrl(config.stocks[indexStock].url);
                    // Extract the content between <tbody></tbody>
                    string tbodyContent = Utility.ExtractContentBody(pageContent);
                    // Parse all stock objects
                    List<StockObject> soList = Utility.ProcessStockObjectList(tbodyContent);
                    // Save the stock objects into the db
                    if (soList.Count > 0)
                    {
                        Console.WriteLine("Saving DB, Count = {0}...", soList.Count);

                        DBConnection dbConnection = null;
                        try
                        {
                            Console.WriteLine("Connection string = {0}", config.connectionString);
                            dbConnection = new DBConnection(config.connectionString);
                            if (dbConnection.Connect())
                            {
                                // Delete all records
                                string queryDelete = DBQueryString.DeleteAllStockObjects(config.stocks[indexStock]);
                                int rowsDelete = dbConnection.ExecuteQuery(queryDelete);
                                // Insert all stock objects
                                for (int indexStockObject = 0; indexStockObject < soList.Count; indexStockObject++)
                                {
                                    StockObject so = soList[indexStockObject];                                    
                                    // Insert stock object
                                    string queryInsert = DBQueryString.InsertStockObject(config.stocks[indexStock], so);
                                    //Console.WriteLine("[{0}]:{1},{2},{3},{4},{5},{6},{7}", i + 1, so.symbol, so.name, so.lastTrade, so.lastTreadTime, so.change, so.changePercent, so.volume);
                                    int rowsInserted = dbConnection.ExecuteQuery(queryInsert);
                                }

                                dbConnection.Close();
                            }
                        }
                        catch (Exception ex)
                        {
                            dbConnection.Close();
                            Console.WriteLine("Exception: {0}", ex.Message);
                        }
                    }

                    Console.WriteLine("Processed successfully {0}...", config.stocks[indexStock].table);
                    Console.WriteLine("-----------------------------");
                }
            }
            catch (Exception)
            {
            }
        }

        private static void ProcessYahooWorldIndices(ref Config config)
        {
            try
            {
                Console.WriteLine("ProcessYahooWorldIndices");
                // URL for Europe
                string urlEurope = "http://ca.finance.yahoo.com/intlindices?e=europe";
                Console.WriteLine(string.Format("ProcessYahooWorldIndices: downloading from {0}", urlEurope));
                string pageContent = Utility.DownloadFromUrl(urlEurope);
                Console.WriteLine(string.Format("ProcessYahooWorldIndices: Parsing from {0}", urlEurope));
                List<YahooWorldIndices.YahooWorldIndexObject> listEurope = YahooWorldIndices.Parse(YahooWorldIndices.ParseTBody(pageContent));
                Console.WriteLine(string.Format("ProcessYahooWorldIndices: Number of Europe indices: {0}", listEurope.Count));
                
                // URL for Asia/Pacific
                string urlAsia = "http://ca.finance.yahoo.com/intlindices?e=asia";
                Console.WriteLine(string.Format("ProcessYahooWorldIndices: downloading from {0}", urlAsia));
                pageContent = Utility.DownloadFromUrl(urlAsia);
                Console.WriteLine(string.Format("ProcessYahooWorldIndices: Parsing from {0}", urlAsia));
                List<YahooWorldIndices.YahooWorldIndexObject> listAsiaPacific = YahooWorldIndices.Parse(YahooWorldIndices.ParseTBody(pageContent));
                Console.WriteLine(string.Format("ProcessYahooWorldIndices: Number of Asia/Pacific indices: {0}", listAsiaPacific.Count));

                // Write data to DB
                Console.WriteLine("ProcessYahooWorldIndices: writing the data into database...");
                                
                DBConnection dbConnection = null;
                try
                {
                    dbConnection = new DBConnection(config.connectionString);
                    if (dbConnection.Connect())
                    {
                        //---------------------------
                        // wi-euro
                        //---------------------------
                        // Delete the records
                        string queryDelete = "DELETE FROM stock_summary WHERE stype='wi-euro'";
                        int rowsDelete = dbConnection.ExecuteQuery(queryDelete);
                        // Insert all objects
                        foreach(YahooWorldIndices.YahooWorldIndexObject io in listEurope)
                        {
                            // Insert stock object
                            string queryInsertTemp = "INSERT INTO stock_summary (stype,field1,field2,field3,field4,field5) VALUES(N'{0}',N'{1}',N'{2}',N'{3}',N'{4}',N'{5}')";
                            string queryInsert = string.Format(queryInsertTemp, "wi-euro", io.symbol, io.name, io.change, io.changePercent, io.lastTrade);
                            int rowsInserted = dbConnection.ExecuteQuery(queryInsert);
                        }

                        //---------------------------
                        // wi-asia
                        //---------------------------
                        // Delete the records
                        queryDelete = "DELETE FROM stock_summary WHERE stype='wi-asia'";
                        rowsDelete = dbConnection.ExecuteQuery(queryDelete);
                        // Insert all objects
                        foreach (YahooWorldIndices.YahooWorldIndexObject io in listAsiaPacific)
                        {
                            // Insert stock object
                            string queryInsertTemp = "INSERT INTO stock_summary (stype,field1,field2,field3,field4,field5) VALUES(N'{0}',N'{1}',N'{2}',N'{3}',N'{4}',N'{5}')";
                            string queryInsert = string.Format(queryInsertTemp, "wi-asia", io.symbol, io.name, io.change, io.changePercent, io.lastTrade);
                            int rowsInserted = dbConnection.ExecuteQuery(queryInsert);
                        }

                        // Close DB connection
                        dbConnection.Close();
                    }
                }
                catch (Exception ex)
                {
                    dbConnection.Close();
                    Console.WriteLine("Exception: {0}", ex.Message);
                }

                Console.WriteLine("----------------------------------");
            }
            catch (Exception ex)
            {
            }
        }

        private static void ProcessYahooCompositeStock(ref Config config)
        {
            try
            {
                XmlDocument xmlDoc = new XmlDocument();
                xmlDoc.Load("ConfigCompositeStocks.xml");
                XmlNodeList nodes = xmlDoc.SelectNodes("/Config/Stocks/Stock");
                xmlDoc = null;

                //string[] symbols = { "ABG.V", "CNA.V" };
                Console.WriteLine("ProcessYahooCompositeStock");
                List<YahooSpecificStock.YahooSpecificStockObject> listObjects = new List<YahooSpecificStock.YahooSpecificStockObject>();

                for (int i = 0; i < nodes.Count; i++)
                {
                    string url = nodes[i].Attributes["url"].InnerText;
                    string symbol = nodes[i].Attributes["symbol"].InnerText;
                    string chsname = nodes[i].Attributes["chsname"].InnerText;

                    Console.WriteLine(string.Format("ProcessYahooCompositeStock: downloading from {0}", url));
                    string source = Utility.DownloadFromUrl(url);

                    YahooSpecificStock.YahooSpecificStockObject soo = new YahooSpecificStock.YahooSpecificStockObject();
                    soo.symbol = symbol;
                    soo.chsname = chsname;
                    soo.Parse(source);
                    listObjects.Add(soo);
                }

                // Write data to DB
                Console.WriteLine("ProcessYahooCompositeStock: writing the data into database...");
                DBConnection dbConnection = null;
                try
                {
                    dbConnection = new DBConnection(config.connectionString);
                    if (dbConnection.Connect())
                    {
                        // Delete the records
                        string queryDelete = "DELETE FROM stock_summary WHERE stype='cmpsite-cn-tsx'";
                        int rowsDelete = dbConnection.ExecuteQuery(queryDelete);
                        // Insert all objects
                        foreach (YahooSpecificStock.YahooSpecificStockObject so in listObjects)
                        {
                            // Insert stock object
                            string queryInsertTemp = "INSERT INTO stock_summary (stype,field1,field2,field3,field4,field5,field6) VALUES(N'{0}',N'{1}',N'{2}',N'{3}',N'{4}',N'{5}',N'{6}')";
                            string queryInsert = string.Format(queryInsertTemp, "cmpsite-cn-tsx", so.symbol, so.name, so.current, so.change, so.changePercent, so.chsname);
                            int rowsInserted = dbConnection.ExecuteQuery(queryInsert);
                        }

                        // Close DB connection
                        dbConnection.Close();
                    }
                }
                catch (Exception ex)
                {
                    dbConnection.Close();
                    Console.WriteLine("Exception: {0}", ex.Message);
                }                

                Console.WriteLine("----------------------------------");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception: {0}", ex.Message);
            }
        }

        private static void ProcessYahooCSV(ref Config config)
        {
            Console.WriteLine("ProcessYahooCSV: processing ProcessYahooCSV...");
            try
            {
                XmlDocument xmlDoc = new XmlDocument();
                xmlDoc.Load("ConfigYahooCSV.xml");
                XmlNodeList nodeList = xmlDoc.SelectNodes("/Config/CSVS/CSV");
                Console.WriteLine("ProcessYahooCSV: Number of nodes found {0}", nodeList.Count);
                XmlNodeList nodeListDelete = xmlDoc.SelectNodes("/Config/Delete/stype");
                List<YahooCSV> csvList = new List<YahooCSV>();
                foreach (XmlNode xn in nodeList)
                {
                    YahooCSV ycsv = new YahooCSV();
                    // Read the attributes
                    ycsv.url = xn.Attributes["url"].InnerText;
                    ycsv.symbol = xn.Attributes["symbol"].InnerText;
                    ycsv.stype = xn.Attributes["stype"].InnerText;
                    ycsv.name = xn.Attributes["name"].InnerText;
                    ycsv.fieldIndex = xn.Attributes["fieldIndex"].InnerText;
                    ycsv.extraField = xn.Attributes["extraField"].InnerText;
                    Console.Write(string.Format("ProcessYahooCSV: downloading {0}...", ycsv.url));
                    // Initialize
                    if (ycsv.Initialize(ycsv.url))
                    {
                        Console.WriteLine("DONE");
                        csvList.Add(ycsv);
                    }
                    else
                        Console.WriteLine("Error: failed to load {0}", ycsv.url);
                }
                xmlDoc = null;

                // Write data into database
                DBConnection dbConnection = null;
                try
                {
                    dbConnection = new DBConnection(config.connectionString);
                    if (dbConnection.Connect())
                    {
                        // Delete the records
                        foreach (XmlNode xn in nodeListDelete)
                        {
                            string queryDelete = string.Format("DELETE FROM {0} WHERE stype=N'{1}'", "stock_summary", xn.Attributes["stype"].InnerText);
                            int rowsDelete = dbConnection.ExecuteQuery(queryDelete);
                        }
                        // Insert all objects
                        for (int i = 0; i < nodeList.Count; i++)
                        {
                            Console.Write(string.Format("ProcessYahooCSV: saving {0}...", csvList[i].url));
                            Console.WriteLine("DONE");
                            string queryInsert = csvList[i].CreateInsertQuery("stock_summary", nodeList[i]);
                            int rowsInserted = dbConnection.ExecuteQuery(queryInsert);
                        }
                        // Close DB connection
                        dbConnection.Close();
                    }
                }
                catch (Exception ex)
                {
                    dbConnection.Close();
                    Console.WriteLine("Exception: {0}", ex.Message);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception: {0}", ex.Message);
            }
        }
    }
}
