<?php
// Global variables for the database
$ccb_db_mssql_server = "localhost\MSSQLSERVER2008";
$ccb_db_mssql_database = "CCBOnlineNews";
$ccb_db_mssql_user = "sa";
$ccb_db_mssql_password = "117Chipwood";

// Connect to the database
function ccb_db_mssql_connect()
{
	return odbc_connect("Driver={SQL Server Native Client 10.0};Server='localhost\\MSSQLSERVER2008';Database='CCBOnlineNews';", 'sa', '117Chipwood');
}

// Close the connection
function ccb_db_mssql_close($connection)
{
	return odbc_close($connection);
}
?>
