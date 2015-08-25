<?php
// Connects to your Database
$server = "localhost\MSSQLSERVER2008";
$database = "CCBOnlineNews";
$user = "sa";
$password = "117Chipwood";
$connection = odbc_connect("Driver={SQL Server Native Client 10.0};Server=$server;Database=$database;", $user, $password);
if($connection === false)
{
	echo "Connection could not be established.<br/>";
	die(print_r(odbc_errormsg(), true));	
}
else
{
	echo "Connection established.<br/>";	
}

// Run the query
$sqlQuery = "SELECT TOP 10 * FROM stock_gainer_tsx";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
{
	die(print_r(odbc_errormsg(), true));	
}

Print "<table border cellpadding=3>";
while($row = odbc_fetch_row($rs))
{
	Print "<tr>";
	Print "<th>symbol:</th> <td>".odbc_result($rs,"symbol") . "</td> ";
	Print "<th>name:</th> <td>".odbc_result($rs,"name") . "</td> ";
	Print "<th>change:</th> <td>".odbc_result($rs,"change") . "</td> ";
	Print "<th>volume:</th> <td>".odbc_result($rs,"volume") . " </td></tr>";
}
Print "</table>";

odbc_close($connection);
?>
