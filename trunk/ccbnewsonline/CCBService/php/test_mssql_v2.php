<html>
<head>
<title>php paged</title>
</head>
<body>

<?php
//為了便於理解和更快地應用到工作中去，我們以ms sql server的northwind數據庫customers表為例。
$gpagesize= 10; //每頁顯示的記錄數
$hostname = "localhost\SQLEXPRESS"; //mssql server
$dbuser = "sqladmin"; //用戶名
$dbpasswd = "1234"; //密碼

echo "<p>dbuser = " + $dbuser + "</p>";
echo '<p>Hello World</p>';
echo '<p>Hello World</p>';

//連接數據庫 
$id = mssql_connect($hostname,$dbuser,$dbpasswd) or die("Couldn't connect to the database server !");
//選擇數據庫，為了方便，這裡以mssql server的northwind數據庫為例 
$db = mssql_select_db("ccb",$id) or die("Couldn't select the database!"); 
//以customers表為例,構建查詢字符串 
$query = "select * from stock_up_tsx"; 
//執行查詢語句 
$rresult = mssql_query($query) or die("Couldn't execute sql：$query"); 
?>

</body>
</html>
</font>
