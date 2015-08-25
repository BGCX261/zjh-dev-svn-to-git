package TestCase;

import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import MSSQL.SqlConnection;

public class SqlConnectionTest
{
	static public void TestSqlConnection()
	{
		try
		{
			String sqlQuery = "SELECT [ID],[CardNum],[CardPin],[TimeBalance] FROM [RebuyInternetTimeDB].[dbo].[CardTable]";
			
			SqlConnection sqlConnection = new SqlConnection();
			if(0 != sqlConnection.OpenConnection())
			{
				// Execute a SQL query
				ResultSet rs = sqlConnection.ExecuteQuery(sqlQuery);
				if(null != rs)
				{
					// Get meta data
					ResultSetMetaData rsmd = rs.getMetaData();
					int nColumnCount = rsmd.getColumnCount();
					System.out.println("nColumnCount = " + nColumnCount);
					// Output column names. The index is from [1~Count]
					for(int i=1; i<=nColumnCount; i++)
					{
						System.out.println();
						System.out.print(rsmd.getColumnName(i));
					}
					System.out.println();
					// Output each row. The index is from [1~Count]
					while(rs.next())
					{
						System.out.println("----------------------------------");
						for(int i=1; i<=nColumnCount; i++)
						{
							System.out.println(rs.getString(i));							
						}
					}
				}
				sqlConnection.CloseConnection();
			}
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
		}
	}
}
