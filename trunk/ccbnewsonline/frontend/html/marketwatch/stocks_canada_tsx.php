<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta content="IE=10.000" http-equiv="X-UA-Compatible">
<link href="../../statics/css/ccb_stock.css" rel="stylesheet" type="text/css" />
<link href="../../statics/css/quote-top.css" rel="stylesheet" type="text/css" />
<link href="marketwatch.css" rel="stylesheet" type="text/css" />
<!--
<link rel="stylesheet" media="screen" href="http://www.tmxmoney.com/en/styles/screen.css">
<link rel="stylesheet" media="screen" href="http://www.tmxmoney.com/en/styles/sub.css">
<link rel="stylesheet" media="screen" href="http://www.tmxmoney.com/en/styles/market.css">
<link rel="stylesheet" media="print" href="http://www.tmxmoney.com/en/styles/print.css">
<link rel="stylesheet" media="screen" href="http://web.tmxmoney.com/assets/css/base.css">
-->
</head>
<body id="quotesSection">

<?php
include "../../php/ccb_odbc_utility.php";

$id_index = 1;
$id_time = "12:30 PM";
$id_change = 12;
$id_volume = 10;
$id_dayhigh = "dh";
$id_daylow = "dl";
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
// Run the query for general index for TSX
$sqlQuery = "SELECT field1,field2,field3,field4,field5,field6 FROM stock_summary WHERE stype='tmxmoney'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
{
	die(print_r(odbc_errormsg(), true));
}

$id_index = odbc_result($rs,"field1");
$id_time = odbc_result($rs,"field2");
$id_change = odbc_result($rs,"field3");
$id_volume = odbc_result($rs,"field4");
$id_daylow = odbc_result($rs,"field5");
$id_dayhigh = odbc_result($rs,"field6");

$parts = str_split($id_change);

// Query tsx gainer
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='tsx' AND stype='gainer'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_tsx_g = ccb_odbc_utility_fetch_array($rs);
// Query tsx loser
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='tsx' AND stype='loser'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_tsx_l = ccb_odbc_utility_fetch_array($rs);
// Query tsxv gainer
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='tsxv' AND stype='gainer'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_tsxv_g = ccb_odbc_utility_fetch_array($rs);
// Query tsxv loser
$sqlQuery = "SELECT TOP 20 symbol,name,last_trade,last_trade_time,change,change_percent,volume FROM stock_gainer_loser WHERE smarket='tsxv' AND stype='loser'";
$rs = odbc_exec($connection, $sqlQuery);
if(!$rs)
	die(print_r(odbc_errormsg(), true));
$a_tsxv_l = ccb_odbc_utility_fetch_array($rs);

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

<div id="mainContent" style="width: 517px; margin-left: 5px; font-style: normal; font-family: Verdana, Geneva, sans-serif;">

<div class="qmQuoteTop">
		<div class="pageLeft">
			<div border="0" cellpadding="3" cellspacing="0" width="100%" id="quotedata" style="height:80px;">
			<div class="qmCompanyName">
            	<div class="qmCompanyName">S&P/TSX Composite Index (^TSX)</div>
				<div class="qmCompanyExchange">Exchange: Toronto Stock Exchange Index</div>
			</div>
			<div align="right" class="qmCompanyLogo">
			</div>
			</div>
			<div class="qmDataTop">
				<div class="qm-last-date">
                    <div class="last"><span style="font-weight:bold">Index: </span><span><?php echo $id_index; ?></span>
						<?php
							if($parts[0] == '+')
								Print "<img src='images/up.gif' width='23' height='23' alt='' border='0'>";
							elseif($parts[0] == '-')
								Print "<img src='images/down.gif' width='23' height='23' alt='' border='0'>";
						?>
					</div>
					<br/>
					<div class="date"><span style="font-weight:bold">Update Time: </span><span><?php echo $id_time; ?></span></div><br/>
				</div>
				<div class="qm-quote-data">
                	<div class="change change-down"><span style="font-weight:bold">Change: </span><span><?php echo $id_change; ?></span></div><br/>
                    <div class="volume"><span style="font-weight:bold">Volume: </span><span><?php echo $id_volume; ?></span></div>
                </div>
				<br>
	 			<div class="lowHighBars">
	 				<div class="lowhigh" title="Prev. Close: 14,210.37 (arrow)<br>Last Price: 14,205.72 (bar)">
	 					<div class="low"><span style="font-weight:bold">Day Low: </span><span><?php echo $id_daylow; ?></span>
	 					</div>
						<div class="high"><span style="font-weight:bold">Day High: </span><span><?php echo $id_dayhigh; ?></span>
						</div>
						<div class="lowHighBar">														
							<div class="bar">
																<div class="filler" style="width:0%"></div>
							</div>
						</div>
	 				</div>
					
												
						<div class="lowHighBar" title="Prev. Close: 14,210.37 (arrow)<br>Last Price: 14,205.72 (bar)">
														<div class="triangle_indicator" style="position: relative; left:94%"></div>
														<div class="bar">
								<div class="filler" style="width:98%"></div>
							</div>
						</div>
					</div>
	 			</div>
			</div>
		</div>			
	</div>

<div>
<img id="qm_img_7226" width="268" height="165" border="0" src="http://app.quotemedia.com/quotetools/getChart?chscale=1d&webmasterId=101020&snap=true&symbol=^TSX&chtype=AreaChart&chwid=268&chhig=165&chbdr=D8DCE5&chfill=cc6d9641&chfill2=6d9641&chgrd=D8DCE5&chln=313942&chfrmon=false&chton=some&chdon=off&chlgdon=off&chaaon=true&chsym=%20&locale=en&chsplton=off&chdivdon=off&chearnon=off" galleryimg="no">
</div>

<br/>
<div class="qmCompanyName"><span>TSX Venture Exchange</span></div>

<div>
<img id="qm_img_tsxv" src="http://app.quotemedia.com/quotetools/getChart?chscale=1d&webmasterId=101020&snap=true&symbol=^JX&chtype=AreaChart&chwid=268&chhig=165&chbdr=D8DCE5&chfill=cc6d9641&chfill2=6d9641&chgrd=D8DCE5&chln=313942&chfrmon=false&chton=some&chdon=off&chlgdon=off&chaaon=true&chsym=%20&locale=en&chsplton=off&chdivdon=off&chearnon=off" />
</div>

<br/><br/>
<h1><span class="mkTableTitleName">TSX 涨幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_tsx_gainer" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_tsx_g);
?>
</table>

<br/>

<h1><span class="mkTableTitleName">TSX 跌幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_tsx_loser" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_tsx_l);
?>
</table>

<br/>

<h1><span class="mkTableTitleName">TSX Venture 涨幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_tsxv_gainer" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_tsxv_g);
?>
</table>

<br/>

<h1><span class="mkTableTitleName">TSX Venture 跌幅榜</span></h1>
<table class="summary_reference" width="100%" id="main_table_tsxv_loser" border="1" class="t1">
<tr>
   <th style="width:80px">Symbol</th>
   <th>Name</th>
   <th style="width:80px">Last Trade</th>
   <th style="width:60px">Change</th>
   <th style="width:80px">Volume</th>
</tr>
<?php
	output_table_list($a_tsxv_l);
?>
</table>

</div>

</body>
</html>
