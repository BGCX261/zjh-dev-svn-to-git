<?php
define('EmpireCMSAdmin','1');
require("../class/connect.php");
require("../class/db_sql.php");
require("../class/functions.php");
require("../data/dbcache/class.php");
$link=db_connect();
$empire=new mysqlquery();
//��֤�û�
$lur=is_login();
$logininid=$lur['userid'];
$loginin=$lur['username'];
$loginrnd=$lur['rnd'];
$loginlevel=$lur['groupid'];
$loginadminstyleid=$lur['adminstyleid'];
//��֤Ȩ��
CheckLevel($logininid,$loginin,$classid,"totaldata");
$totaltype=(int)$_POST['totaltype'];
$classid=(int)$_POST['classid'];
$ztid=(int)$_POST['ztid'];
$tbname=RepPostVar($_POST['tbname']);
$startday=RepPostVar($_POST['startday']);
$endday=RepPostVar($_POST['endday']);
$userid=(int)$_POST['userid'];
$onclick=0;
$allnum=0;
$nochecknum=0;
$checknum=0;
$bfb=0;
//�����ͳ��
if($totaltype==0)
{
	$ztid=0;
	$tbname='';
	if($classid&&!$class_r[$classid][tbname])
	{
		printerror("ErrorUrl","history.go(-1)");
	}
	//δ���
	$query="select count(*) as total from {$dbtbpre}ecms_".$class_r[$classid][tbname]." where checked=0";
	//�����
	$query1="select count(*) as total from {$dbtbpre}ecms_".$class_r[$classid][tbname]." where checked=1";
	//���
	$onclickquery="select avg(onclick) as total from {$dbtbpre}ecms_".$class_r[$classid][tbname]." where 1=1";
	if($classid)
	{
		//�м����
		if(empty($class_r[$classid][islast]))
		{
			$where=ReturnClass($class_r[$classid][sonclass]);
		}
		//�ռ����
		else
		{
			$where="classid='$classid'";
		}
		$query.=" and (".$where.")";
		$query1.=" and (".$where.")";
		$onclickquery.=" and (".$where.")";
	}
}
//����ͳ��
elseif($totaltype==1)
{
	$ztid=0;
	$classid=0;
	if(!$tbname)
	{
		printerror("ErrorUrl","history.go(-1)");
	}
	//δ���
	$query="select count(*) as total from {$dbtbpre}ecms_".$tbname." where checked=0";
	//�����
	$query1="select count(*) as total from {$dbtbpre}ecms_".$tbname." where checked=1";
	//���
	$onclickquery="select avg(onclick) as total from {$dbtbpre}ecms_".$tbname." where 1=1";
}
//��ר��ͳ��
elseif($totaltype==2)
{
	$classid=0;
	$tbname='';
	if(!$class_zr[$ztid][tbname])
	{
		printerror("ErrorUrl","history.go(-1)");
	}
	//δ���
	$query="select count(*) as total from {$dbtbpre}ecms_".$class_zr[$ztid][tbname]." where checked=0 and ztid like '%|$ztid|%'";
	//�����
	$query1="select count(*) as total from {$dbtbpre}ecms_".$class_zr[$ztid][tbname]." where checked=1 and ztid like '%|$ztid|%'";
	//���
	$onclickquery="select avg(onclick) as total from {$dbtbpre}ecms_".$class_zr[$ztid][tbname]." where 1=1 and ztid like '%|$ztid|%'";
}
else
{
	printerror("ErrorUrl","history.go(-1)");
}
//ʱ��
if($startday&&$endday)
{
	$start=$startday." 00:00:00";
	$end=$endday." 23:59:59";
	$timeadd=" and (newstime>='".to_time($start)."' and newstime<='".to_time($end)."')";
	$query.=$timeadd;
	$query1.=$timeadd;
	$onclickquery.=$timeadd;
}
//�û�
if($userid)
{
	$useradd=" and userid='$userid'";
	$query.=$useradd;
	$query1.=$useradd;
	$onclickquery.=$useradd;
}
//���ݱ�
$htb=0;
$tbsql=$empire->query("select tbname,tname from {$dbtbpre}enewstable order by tid");
while($tbr=$empire->fetch($tbsql))
{
	$select="";
	if($tbr[tbname]==$tbname)
	{
		$htb=1;
		$select=" selected";
	}
	$tbstr.="<option value='".$tbr[tbname]."'".$select.">".$tbr[tname]."</option>";
}
if($totaltype==1&&$htb==0)
{
	printerror('ErrorUrl','');
}
if($classid||$ztid||$tbname)
{
	//���
	$checknum=$empire->gettotal($query1);
	//δ���
	$nochecknum=$empire->gettotal($query);
	//����Ϣ��
	$allnum=$checknum+$nochecknum;
	//�����
	$onclick=$empire->gettotal($onclickquery);
}
//��Ŀ
$fcfile="../data/fc/ListEnews.php";
$class="<script src=../data/fc/cmsclass.js></script>";
if(!file_exists($fcfile))
{$class=ShowClass_AddClass("",$classid,0,"|-",0,0);}
//ר��ͳ��
$ztsql=$empire->query("select ztid,ztname from {$dbtbpre}enewszt order by ztid");
while($ztr=$empire->fetch($ztsql))
{
	$select="";
	if($ztr[ztid]==$ztid)
	{
		$select=" selected";
	}
	$ztstr.="<option value='".$ztr[ztid]."'".$select.">".$ztr[ztname]."</option>";
}
//�û�
$usersql=$empire->query("select userid,username from {$dbtbpre}enewsuser order by userid");
while($userr=$empire->fetch($usersql))
{
	if($userr[userid]==$userid)
	{$select=" selected";}
	else
	{$select="";}
	$user.="<option value='".$userr[userid]."'".$select.">".$userr[username]."</option>";
}
db_close();
$empire=null;
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>ͳ������</title>
<link href="adminstyle/<?=$loginadminstyleid?>/adminstyle.css" rel="stylesheet" type="text/css">
<script src="ecmseditor/fieldfile/setday.js"></script>
</head>

<body>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1">
  <tr>
    <td height="25">λ�ã�<a href="TotalData.php">ͳ������</a></td>
  </tr>
</table>

<form name="form1" method="post" action="TotalData.php">
  <table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class="tableborder">
    <tr class="header"> 
      <td height="25" colspan="2">ͳ������ 
        <input name="enews" type="hidden" id="enews" value="TotalData"> </td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td width="19%" height="25"><input name="totaltype" type="radio" value="0"<?=$totaltype==0?' checked':''?>>
        ����Ŀͳ��</td>
      <td width="81%" height="25"><select name="classid" id="classid">
          <?=$class?>
        </select>
        ����ѡ����Ŀ����ͳ������������Ŀ�� </td>
    </tr>
    <tr bgcolor="#FFFFFF">
      <td height="25"><input name="totaltype" type="radio" value="1"<?=$totaltype==1?' checked':''?>>
        �����ݱ�ͳ��</td>
      <td height="25"><select name="tbname" id="tbname">
	  <?=$tbstr?>
        </select></td>
    </tr>
    <tr bgcolor="#FFFFFF">
      <td height="25"><input name="totaltype" type="radio" value="2"<?=$totaltype==2?' checked':''?>>
        ��ר��ͳ��</td>
      <td height="25"><select name="ztid" id="ztid">
	  <?=$ztstr?>
        </select></td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td height="25">¼���ߣ�</td>
      <td height="25"><select name="userid" id="userid">
          <option value="0">����¼����</option>
          <?=$user?>
        </select></td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td height="25">ʱ�䷶Χ��</td>
      <td height="25">�� 
        <input name="startday" type="text" value="<?=$startday?>" size="12" onclick="setday(this)">
        �� 
        <input name="endday" type="text" value="<?=$endday?>" size="12" onclick="setday(this)">
        ֮�������(����Ϊ����Ϊ����������)</td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td height="25">&nbsp;</td>
      <td height="25"><input type="submit" name="Submit" value="��ʼͳ��"> <input type="reset" name="Submit2" value="����"></td>
    </tr>
  </table>
</form>

<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class="tableborder">
  <tr bgcolor="#FFFFFF"> 
    <td height="25" colspan="4"> <div align="center">ͳ��ʱ�䣺 
        <?=date("Y-m-d H:i:s")?>
      </div></td>
  </tr>
  <tr class="header"> 
    <td width="23%" height="25"><div align="center">����Ϣ��</div></td>
    <td width="23%" height="25"> <p align="center">δ�����</p></td>
    <td width="23%" height="25"> <div align="center">�������</div></td>
    <td width="15%"><div align="center">ƽ�������</div></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25"><div align="center"><font color=red> 
        <?=$allnum?>
        </font></div></td>
    <td height="25"><div align="center"> 
        <?=$nochecknum?>
      </div></td>
    <td height="25"><div align="center"> 
        <?=$checknum?>
      </div></td>
    <td><div align="center">
        <?=$onclick?>
      </div></td>
  </tr>
</table>
<p>&nbsp;</p>
</body>
</html>