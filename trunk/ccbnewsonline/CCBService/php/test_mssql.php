<html>
<head>
<title>php分頁</title>
</head>
<body>

<?
//為了便於理解和更快地應用到工作中去，我們以ms sql server的northwind數據庫customers表為例。
$gpagesize= 10; //每頁顯示的記錄數 
$hostname = "localhost"; //mssql server 
$dbuser = "sa"; //用戶名 
$dbpasswd = "1111111"; //密碼 
//連接數據庫 
$id = mssql_connect($hostname,$dbuser,$dbpasswd) or die("無法連接數據庫服務器！"); 
//選擇數據庫，為了方便，這裡以mssql server的northwind數據庫為例 
$db = mssql_select_db("northwind",$id) or die("無法連接數據庫！"); 
//以customers表為例,構建查詢字符串 
$query = "select * from customers"; 
//執行查詢語句 
$rresult = mssql_query($query) or die("無法執行sql：$query"); 
//$page變量標示當前顯示的頁 
if(!isset($page)) $page=1; 
if($page==0) $page=1; 
//得到當前查詢到的紀錄數 $nnumrows 
if(($nnumrows= mssql_num_rows($rresult))<=0) 
{ 
echo "<p align=center>沒有紀錄";
exit;
}; 
//得到最大頁碼數maxpage 
$maxpage = (int)ceil($nnumrows/$gpagesize); 
if((int)$page > $maxpage) 
$page=$maxpage; 
?>
 
<table border=0><tr><td>
<?echo "<font size=2>第$page 頁，共 $maxpage 頁</font>"; ?>
</td><td></td></tr></table>
<table border="1" bordercborlight="#cc9966" bgcbor="#00f2ee" bordercbordark="#ffffff">
<tr bgcbor="#f7f2ff">
<?
//顯示表格頭 
for($icnt = 0; $icnt < mssql_num_fields($rresult); $icnt++) 
{
	echo "<td>".mssql_field_name($rresult,$icnt)."</td>" ;
} 
?>
</tr>

<?
//根據偏移量($page - 1)*$gpagesize,運用mssql_data_seek函數得到要顯示的頁面 
if( mssql_data_seek($rresult,($page-1)*$gpagesize) )
{
$i=0; 
//循環顯示當前紀錄集 
for($i;$i<$gpagesize;$i++) 
{ 
echo "<tr style="font-size:12px">"; 
//得到當前紀錄，填充到數組$arr; 
$arr= mssql_fetch_row($rresult); 
if($arr) 
{ 
//循環顯示當前紀錄的所有字段值 
for($noffset = 0;$noffset < count($arr);$noffset++) 
{ 
echo "<td>".$arr[$noffset]."</td>"; 
} 
}
echo "</tr>"; 
}
}
?>
</table>

<hr size=1 width=80%>
<div align=center>
<? 
//首頁和上一頁的鏈接 
if( $nnumrows>1 && $page>1) 
{ 
$prevpage=$page-1; 
echo " <a href=$php_self?page=1>首頁</a> "; 
echo " <a href=$php_self?page=$prevpage >上一頁</a> "; 
} 
//下一頁和末頁的鏈接 
if( $page>=1 && $page<$maxpage) 
{ 
$nextpage= $page+1; 
echo " <a href=$php_self?page=$nextpage >下一頁</a> "; 
echo " <a href=$php_self?page=$maxpage >末頁</a> "; 
} 
?>
</div>
</body>
</html>
</font>
