<?php
define('EmpireCMSAdmin','1');
require("../../class/connect.php");
require("../../class/db_sql.php");
require("../../class/functions.php");
$link=db_connect();
$empire=new mysqlquery();
$editor=1;
//��֤�û�
$lur=is_login();
$logininid=$lur['userid'];
$loginin=$lur['username'];
$loginrnd=$lur['rnd'];
$loginlevel=$lur['groupid'];
$loginadminstyleid=$lur['adminstyleid'];
//��֤Ȩ��
CheckLevel($logininid,$loginin,$classid,"userpage");
$sql=$empire->query("select classid,classname from {$dbtbpre}enewspageclass order by classid desc");
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title></title>
<link href="../adminstyle/<?=$loginadminstyleid?>/adminstyle.css" rel="stylesheet" type="text/css">
</head>

<body>
<table width="98%%" border="0" align="center" cellpadding="3" cellspacing="1">
  <tr>
    <td><p>λ�ã�<a href="ListPage.php">�����Զ���ҳ��</a> &gt; <a href="PageClass.php">�����Զ���ҳ�����</a></p>
      </td>
  </tr>
</table>
<form name="form1" method="post" action="../ecmscom.php">
  <table width="98%%" border="0" align="center" cellpadding="3" cellspacing="1" class="tableborder">
    <tr class="header">
      <td height="25">�����Զ���ҳ�����: 
        <input name=enews type=hidden id="enews" value=AddPageClass>
		<input name=doing type=hidden value=page>
        </td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF"> �������: 
        <input name="classname" type="text" id="classname">
        <input type="submit" name="Submit" value="����">
        <input type="reset" name="Submit2" value="����"></td>
    </tr>
  </table>
</form>
<table width="98%%" border="0" align="center" cellpadding="3" cellspacing="1" class="tableborder">
  <tr class="header">
    <td width="10%"><div align="center">ID</div></td>
    <td width="59%" height="25"><div align="center">�������</div></td>
    <td width="31%" height="25"><div align="center">����</div></td>
  </tr>
  <?
  while($r=$empire->fetch($sql))
  {
  ?>
  <form name=form2 method=post action=../ecmscom.php>
    <input type=hidden name=enews value=EditPageClass>
	<input name=doing type=hidden value=page>
    <input type=hidden name=classid value=<?=$r[classid]?>>
    <tr bgcolor="#FFFFFF" onmouseout="this.style.backgroundColor='#ffffff'" onmouseover="this.style.backgroundColor='#C3EFFF'">
      <td><div align="center"><?=$r[classid]?></div></td>
      <td height="25"> <div align="center">
          <input name="classname" type="text" id="classname" value="<?=$r[classname]?>">
        </div></td>
      <td height="25"><div align="center"> 
          <input type="submit" name="Submit3" value="�޸�">
          &nbsp; 
          <input type="button" name="Submit4" value="ɾ��" onclick="self.location.href='../ecmscom.php?enews=DelPageClass&classid=<?=$r[classid]?>&doing=page';">
        </div></td>
    </tr>
  </form>
  <?
  }
  db_close();
  $empire=null;
  ?>
</table>
</body>
</html>