<?php
// Connects to your Database
$serverName = "localhost\MSSQLSERVER2008";
$connectionInfo = array("Database"=>"ccbnewsonline", "UID"=>"mssqladmin", "PWD"=>"1234");
// Connect to MSSQL
$conn = sqlsrv_connect($serverName, $connectionInfo);// or die('Failed to connect to MS SQL'); 
if($conn)
{
	echo "Connection established.<br/>";
}
else
{
	echo "Connection could not be established.<br/>";
	die(print_r(sqlsrv_errors(), true));
}
$sqlQuery = "SELECT TOP 10 * FROM stock_gainer_tsx";
$params = array(1, "");
//$data = sqlsrv_query($conn, $sqlQuery, $params);
$stmt = sqlsrv_query($conn, $sqlQuery);
if($stmt === false)
{
	die(print_r(sqlsrv_errors(), true));
}

Print "<table border cellpadding=3>";
while($row = sqlsrv_fetch_array($stmt, SQLSRV_FETCH_ASSOC)) 
{
	Print "<tr>";
	Print "<th>symbol:</th> <td>".$row['symbol'] . "</td> ";
	Print "<th>name:</th> <td>".$row['name'] . "</td> ";
	Print "<th>change:</th> <td>".$row['change'] . "</td> ";
	Print "<th>volume:</th> <td>".$row['volume'] . " </td></tr>";
}
Print "</table>";

sqlsrv_free_stmt($stmt);
?>
