<?php
require("../class/connect.php");
require("../class/db_sql.php");
require("../class/q_functions.php");
require("../data/dbcache/class.php");
require("../class/user.php");
require("../data/dbcache/MemberLevel.php");
$link=db_connect();
$empire=new mysqlquery();
require('CheckUser.php');//��֤�û�
require('template/'.$spacestyle.'/userinfo.temp.php');
db_close();
$empire=null;
?>