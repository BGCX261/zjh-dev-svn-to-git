package MSSQL;

import java.sql.*;

import com.microsoft.sqlserver.jdbc.*;

public class SqlConnection
{
	public void SetServer(String strServer)
	{
		m_strServer = strServer;
	}
	public String GetServer()
	{
		return m_strServer;
	}
	public void SetServerPort(int nPort)
	{
		m_nServerPort = nPort;
	}
	public int GetServerPort()
	{
		return m_nServerPort;
	}
	public void SetDBName(String strDBName)
	{
		m_strDBName = strDBName;
	}
	public String GetDBName()
	{
		return m_strDBName;
	}
	public void SetUsername(String strUsername)
	{
		m_strUsername = strUsername;
	}
	public String GetUsername()
	{
		return m_strUsername;
	}
	public void SetPassword(String strPassword)
	{
		m_strPassword = strPassword;
	}
	public String GetPassword()
	{
		return m_strPassword;
	}	
	
	public int OpenConnection()
	{
		String sDBUrl = "jdbc:sqlserver://CARMACKVM-PC:1433;databaseName=RebuyInternetTimeDB;user=sqladmin;password=1234;";
		
		try
		{
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
			m_Connection = DriverManager.getConnection(sDBUrl);
			if(m_Connection != null)
			{
				m_Statement = m_Connection.createStatement();
				if(null != m_Statement)
				{
					return 1;
				}
			}
		}
		catch (Exception e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
			return 0;
		}
		
		return 0;
	}
	
	public int CloseConnection()
	{
		try
		{
			if(m_Statement != null)
			{
				m_Statement.close();
				m_Statement = null;
			}
			if(m_Connection != null)
			{
				m_Connection.close();
				m_Connection = null;
			}
		}
		catch(Exception e)
		{
		}
		
		return 1;
	}
	
	public ResultSet ExecuteQuery(String strQuery) throws SQLException
	{
		if(m_Statement != null)
		{
			return m_Statement.executeQuery(strQuery);
		}
		
		return null;
	}
	
	private String m_strServer;
	private int m_nServerPort;
	private String m_strDBName;
	private String m_strUsername;
	private String m_strPassword;
	// Connection objects
	private Connection m_Connection;
	private Statement m_Statement;
}
