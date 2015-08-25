<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta content="IE=10.000" http-equiv="X-UA-Compatible">
<link href="../../statics/css/ccb_stock.css" rel="stylesheet" type="text/css" />
<link href="marketwatch.css" rel="stylesheet" type="text/css" />

</head>
<body id="quotesSection">

<?php
include "../../php/ccb_database.php";
include "../../php/ccb_odbc_utility.php";

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

// Query
$sqlQuery = "SELECT * FROM stock_summary WHERE stype = 'wi-asia'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_asia = ccb_odbc_utility_fetch_array($rs);

// Close DB connection
odbc_close($connection);

$yahooRef = "http://ca.finance.yahoo.com/q?s=";
?>

<h1><span class="mkTableTitleName">亚洲指数</span></h1>
<br/>
<table class="summary_reference" width="100%" id="main_table_europe" border="1" class="t1">
<tr>
   <th style="width:60px">Symbol</th>
   <th style="width:60px">Last Trade</th>
   <th style="width:40px">Change</th>
   <th style="width:60px">Update Time</th>
</tr>
<?php
foreach($a_asia as $x=>$x_value)
{
	$parts = str_split($x_value["field5"]);
	Print "<tr>";
	Print "<td><b><a href='".$yahooRef.$x_value["field1"]." 'target='_blank'>".$x_value["field1"]."</a></b></td>";
	Print "<td>".$x_value["field2"]."</td>";
	if($parts[0] == '+')
		Print "<td>"."<img src='images/up_g.gif'/>".$x_value["field5"]."</td>";
	else if($parts[0] == '-')
		Print "<td>"."<img src='images/down_r.gif'/>".$x_value["field5"]."</td>";
	else
		Print "<td>".$x_value["field5"]."</td>";
	Print "<td>".$x_value["field3"].",".$x_value["field4"]."</td>";
	Print "</tr>";
}
?>
</table>

<br/>

<img id="img_aord" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eAORD&lang=en-CA&region=CA&width=300&height=180" />
<img id="img_ssec" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=000001.SS&lang=en-CA&region=CA&width=300&height=180" />
<img id="img_hsi" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eHSI&lang=en-CA&region=CA&width=300&height=180" />
<img id="img_bsesn" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eBSESN&lang=en-CA&region=CA&width=300&height=180" />
<img id="img_jkse" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eJKSE&lang=en-CA&region=CA&width=300&height=180" />
<img id="img_klse" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eKLSE&lang=en-CA&region=CA&width=300&height=180" />
<img id="img_sti" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eSTI&lang=en-CA&region=CA&width=300&height=180" />
<img id="img_twii" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eTWII&lang=en-CA&region=CA&width=300&height=180" />

</body>
</html>
