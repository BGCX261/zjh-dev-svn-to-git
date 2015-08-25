using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CCBService.Core
{
    public class DBQueryString
    {
        public static string InsertStockObject(Stock stock, StockObject so)
        {
            string queryTemp = "INSERT INTO {0} (smarket,stype,symbol,name,last_trade,last_trade_time,change,change_percent,volume) VALUES('{1}','{2}','{3}','{4}','{5}','{6}','{7}','{8}','{9}')";
            return string.Format(queryTemp, stock.table, stock.market, stock.type, so.symbol, so.name, so.lastTrade, so.lastTreadTime, so.change, so.changePercent, so.volume);
        }


        public static string DeleteAllStockObjects(Stock stock)
        {
            string queryTemp = "DELETE FROM {0} WHERE smarket='{1}' AND stype='{2}'";
            return string.Format(queryTemp, stock.table, stock.market, stock.type);
        }
    }
}
