using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;

namespace CCBService.Core
{
    public class DBConnection
    {
        public DBConnection(string conString)
        {
            try
            {
                m_stringConnection = conString;
                m_sqlConnection = new SqlConnection(m_stringConnection);
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }
        
        public bool Connect()
        {
            if (m_sqlConnection == null)
                return false;

            try
            {
                m_sqlConnection.Open();
            }
            catch (Exception)
            {
                //Console.WriteLine(e.ToString());
                return false;
            }

            return true;
        }

        public bool Close()
        {
            try
            {
                if (m_sqlConnection != null)
                {
                    m_sqlConnection.Close();
                    m_sqlConnection = null;
                }
                return true;
            }
            catch (Exception)
            {
                //Console.WriteLine(e.ToString());
                return false;
            }
        }

        public int ExecuteQuery(string query)
        {
            if (m_sqlConnection != null)
            {
                SqlCommand myCommand = new SqlCommand(query, m_sqlConnection);
                return myCommand.ExecuteNonQuery();
            }

            return 0;
        }

        public static string GetConnectionString(string server, string db, string user, string password)
        {
            return string.Format("Data Source={0};Initial Catalog={1};Trusted_connection=false;Integrated Security=false;User Id={2};Password={3}", server, db, user, password);
        }

        private string m_stringConnection = string.Empty;
        private SqlConnection m_sqlConnection = null;
    }
}
