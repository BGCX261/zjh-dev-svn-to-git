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

// Query us gainer
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='us' AND stype='gainer'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_us_g = ccb_odbc_utility_fetch_array($rs);
// Query us loser
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='us' AND stype='loser'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_us_l = ccb_odbc_utility_fetch_array($rs);
// Query nasdaq gainer
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='nasdaq' AND stype='gainer'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_nasdaq_g = ccb_odbc_utility_fetch_array($rs);
// Query nasdaq loser
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='nasdaq' AND stype='loser'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_nasdaq_l = ccb_odbc_utility_fetch_array($rs);
// Query amex gainer
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='amex' AND stype='gainer'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_amex_g = ccb_odbc_utility_fetch_array($rs);
// Query amex loser
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='amex' AND stype='loser'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_amex_l = ccb_odbc_utility_fetch_array($rs);
// Query nyse gainer
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='nyse' AND stype='gainer'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_nyse_g = ccb_odbc_utility_fetch_array($rs);
// Query nyse loser
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='nyse' AND stype='loser'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_nyse_l = ccb_odbc_utility_fetch_array($rs);

// Close DB connection
odbc_close($connection);

$yahooRef = "http://ca.finance.yahoo.com/q?s=";

function output_table_list($arrayList)
{
	foreach($arrayList as $x=>$x_value)
	{
		$parts = str_split($x_value["change"]);
		Print "<tr>";
		Print "<td><b><a href='".$yahooRef.$x_value["symbol"]." 'target='_blank'>".$x_value["symbol"]."</a></b></td>";
		Print "<td>".$x_value["name"]."</td>";
		Print "<td>".$x_value["last_trade"]."</td>";
		if($parts[0] == '+')
			Print "<td>"."<img src='images/up_g.gif'/>".$x_value["change"]."</td>";
		else if($parts[0] == '-')
			Print "<td>"."<img src='images/down_r.gif'/>".$x_value["change"]."</td>";
		else
			Print "<td>".$x_value["change"]."</td>";
		Print "<td>".$x_value["volume"]."</td>";
		Print "</tr>";
	}
}
?>

<img id="img_sp" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eGSPC&lang=en-US&region=US&width=300&height=180" />
<img id="img_dow" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eDJI&lang=en-US&region=US&width=300&height=180" />
<img id="img_nasdaq" width="300" height="180" border="0" src="http://chart.finance.yahoo.com/t?s=%5eIXIC&lang=en-US&region=US&width=300&height=180" />

<h1><span class="mkTableTitleName">AMEX 涨幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_amex_gainer" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_amex_g);
?>
</table>

<br/>

<h1><span class="mkTableTitleName">AMEX 跌幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_amex_loser" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_amex_l);
?>
</table>

<br/>

<h1><span class="mkTableTitleName">NYSE 涨幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_nyse_gainer" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_nyse_g);
?>
</table>

<br/>

<h1><span class="mkTableTitleName">NYSE 跌幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_nyse_loser" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_nyse_l);
?>
</table>

<br/>

<h1><span class="mkTableTitleName">NASDAQ 涨幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_nasdaq_gainer" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_nasdaq_g);
?>
</table>

<br/>

<h1><span class="mkTableTitleName">NASDAQ 跌幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_nasdaq_loser" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_nasdaq_l);
?>
</table>

</body>
</html>
