<?php
define('EmpireCMSAdmin','1');
require("../class/connect.php");
require("../class/db_sql.php");
require("../class/functions.php");
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
CheckLevel($logininid,$loginin,$classid,"zt");
$enews=$_GET['enews'];
$url="<a href=ListZt.php>����ר��</a>&nbsp;>&nbsp;����ר��";
$postword='����ר��';
//��ʹ������
$r[reorder]="newstime DESC";
$r[maxnum]=0;
$r[ztnum]=25;
$r[zttype]=".html";
$r[newline]=10;
$r[hotline]=10;
$r[goodline]=10;
$r[hotplline]=10;
$r[firstline]=10;
$pripath='s/';
//����ר��
$docopy=$_GET['docopy'];
if($docopy&&$enews=="AddZt")
{
	$copyclass=1;
}
$ecmsfirstpost=1;
//�޸�ר��
if($enews=="EditZt"||$copyclass)
{
	$ecmsfirstpost=0;
	if($copyclass)
	{
		$thisdo="����";
	}
	else
	{
		$thisdo="�޸�";
	}
	$ztid=(int)$_GET['ztid'];
	$r=$empire->fetch1("select * from {$dbtbpre}enewszt where ztid='$ztid'");
	$addr=$empire->fetch1("select * from {$dbtbpre}enewsztadd where ztid='$ztid'");
	$url="<a href=ListZt.php>����ר��</a>&nbsp;>&nbsp;".$thisdo."ר�⣺".$r[ztname];
	$postword=$thisdo.'ר��';
	//ר��Ŀ¼
	$mycr=GetPathname($r[ztpath]);
	$pripath=$mycr[1];
	$ztpath=$mycr[0];
	//����ר��
	if($copyclass)
	{
		$r[ztname].='(1)';
		$ztpath.='1';
	}
}
//�б�ģ��
$msql=$empire->query("select mid,mname from {$dbtbpre}enewsmod order by myorder,mid");
while($mr=$empire->fetch($msql))
{
	$listtemp_options.="<option value=0 style='background:#99C4E3'>".$mr[mname]."</option>";
	$l_sql=$empire->query("select tempid,tempname from ".GetTemptb("enewslisttemp")." where modid='$mr[mid]'");
	while($l_r=$empire->fetch($l_sql))
	{
		if($l_r[tempid]==$r[listtempid])
		{$l_d=" selected";}
		else
		{$l_d="";}
		$listtemp_options.="<option value=".$l_r[tempid].$l_d."> |-".$l_r[tempname]."</option>";
	}
}
//��Ŀ
$options=ShowClass_AddClass("",$r[classid],0,"|-",0,0);
//jsģ��
$jstempsql=$empire->query("select tempid,tempname from ".GetTemptb("enewsjstemp")." order by tempid");
while($jstempr=$empire->fetch($jstempsql))
{
	$select="";
	if($r[jstempid]==$jstempr[tempid])
	{
		$select=" selected";
	}
	$jstemp.="<option value='".$jstempr[tempid]."'".$select.">".$jstempr[tempname]."</option>";
}
//����ģ��
$classtempsql=$empire->query("select tempid,tempname from ".GetTemptb("enewsclasstemp")." order by tempid");
while($classtempr=$empire->fetch($classtempsql))
{
	$select="";
	if($r[classtempid]==$classtempr[tempid])
	{
		$select=" selected";
	}
	$classtemp.="<option value='".$classtempr[tempid]."'".$select.">".$classtempr[tempname]."</option>";
}
//����
$zcstr="";
$zcsql=$empire->query("select classid,classname from {$dbtbpre}enewsztclass order by classid");
while($zcr=$empire->fetch($zcsql))
{
	$select="";
	if($zcr[classid]==$r[zcid])
	{
		$select=" selected";
	}
	$zcstr.="<option value='".$zcr[classid]."'".$select.">".$zcr[classname]."</option>";
}
//�Ż�����
$yh_options='';
$yhsql=$empire->query("select id,yhname from {$dbtbpre}enewsyh order by id");
while($yhr=$empire->fetch($yhsql))
{
	$select='';
	if($r[yhid]==$yhr[id])
	{
		$select=' selected';
	}
	$yh_options.="<option value='".$yhr[id]."'".$select.">".$yhr[yhname]."</option>";
}
//��ǰʹ�õ�ģ����
$thegid=GetDoTempGid();
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>����ר��</title>
<link href="adminstyle/<?=$loginadminstyleid?>/adminstyle.css" rel="stylesheet" type="text/css">
<script>
//���
function CheckForm(obj){
	if(obj.ztname.value=='')
	{
		alert("������ר������");
		obj.ztname.focus();
		return false;
	}
	if(obj.ztpath.value=="")
	{
		alert("������ר��Ŀ¼");
		obj.ztpath.focus();
		return false;
	}
	if(obj.listtempid.value==0)
	{
		alert("��ѡ���б�ģ��");
		obj.listtempid.focus();
		return false;
	}
}
  </script>

</head>

<body>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1">
  <tr>
    <td>λ�ã� 
      <?=$url?>
    </td>
  </tr>
</table>
<br>
  
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class="tableborder">
  <form name="form1" method="post" action="ecmsclass.php" onsubmit="return CheckForm(document.form1);">
    <tr class="header"> 
      <td height="25" colspan="2"> 
        <?=$postword?>
        <input type=hidden name=enews value=<?=$enews?>> </td>
    </tr>
    <tr> 
      <td height="25" colspan="2">��������</td>
    </tr>
    <tr> 
      <td width="24%" height="25" bgcolor="#FFFFFF">ר������(*)</td>
      <td width="76%" height="25" bgcolor="#FFFFFF"> <input name="ztname" type="text" id="ztname" value="<?=$r[ztname]?>" size="38"> 
        <?
	  if($enews=="AddZt")
	  {
	  ?>
        <input type="button" name="Submit5" value="����ƴ��Ŀ¼" onclick="window.open('GetPinyin.php?hz='+document.form1.ztname.value+'&returnform=opener.document.form1.ztpath.value','','width=160,height=100');"> 
        <?
	  }
	  ?>
        <input name="ztid" type="hidden" id="ztid" value="<?=$ztid?>"> <input name="oldztid" type="hidden" id="oldztid" value="<?=$ztid?>"> 
      </td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">������Ϣ��Ŀ</td>
      <td height="25" bgcolor="#FFFFFF"> <select name="classid" id="classid">
          <option value="0">������������Ŀ</option>
          <?=$options?>
        </select> <input type="button" name="Submit622232" value="������Ŀ" onclick="window.open('ListClass.php');"> 
        <font color="#666666">(ѡ����Ŀ����Ӧ��������Ŀ)</font></td>
    </tr>
    <tr> 
      <td height="25" valign="top" bgcolor="#FFFFFF">����ļ��� 
        <input name="oldztpath" type="hidden" id="oldztpath2" value="<?=$r[ztpath]?>"> 
        <input name="oldpripath" type="hidden" id="oldztpath3" value="<?=$pripath?>"> 
      </td>
      <td bgcolor="#FFFFFF"> <table border="0" cellspacing="1" cellpadding="3">
          <tr bgcolor="DBEAF5"> 
            <td bgcolor="DBEAF5">&nbsp;</td>
            <td bgcolor="DBEAF5">�ϲ�Ŀ¼</td>
            <td bgcolor="DBEAF5">��ר��Ŀ¼</td>
            <td bgcolor="DBEAF5">&nbsp;</td>
          </tr>
          <tr> 
            <td><div align="right">��Ŀ¼/</div></td>
            <td><input name="pripath" type="text" id="pripath" value="<?=$pripath?>" size="30"></td>
            <td><input name="ztpath" type="text" id="ztpath2" value="<?=$ztpath?>" size="16"></td>
            <td><input type="button" name="Submit3" value="���Ŀ¼" onclick="javascript:window.open('ecmscom.php?enews=CheckPath&pripath='+document.form1.pripath.value+'&classpath='+document.form1.ztpath.value,'','width=100,height=100,top=250,left=450');"></td>
          </tr>
        </table></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">ʹ���Ż�����</td>
      <td bgcolor="#FFFFFF"><select name="yhid" id="yhid">
          <option name="0">��ʹ��</option>
          <?=$yh_options?>
        </select> <input type="button" name="Submit63" value="�����Ż�����" onclick="window.open('db/ListYh.php');"></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">�ļ���չ��</td>
      <td bgcolor="#FFFFFF"> <input name="zttype" type="text" id="zttype4" value="<?=$r[zttype]?>" size="38"> 
        <select name="select" onchange="document.form1.zttype.value=this.value">
          <option value=".html">��չ��</option>
          <option value=".html">.html</option>
          <option value=".htm">.htm</option>
          <option value=".php">.php</option>
          <option value=".shtml">.shtml</option>
        </select> </td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">������</td>
      <td bgcolor="#FFFFFF"> <input name="zturl" type="text" id="zturl" value="<?=$r[zturl]?>" size="38"> 
        <font color="#666666"> (�粻��,������.���������&quot;/&quot;)</font></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">��������</td>
      <td bgcolor="#FFFFFF"><select name="zcid" id="zcid">
          <option value="0">���������κη���</option>
          <?=$zcstr?>
        </select> <input type="button" name="Submit6222322" value="��������" onclick="window.open('ListZtClass.php');"></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">ר������ͼ</td>
      <td bgcolor="#FFFFFF"> <input name="ztimg" type="text" id="ztimg" value="<?=$r[ztimg]?>" size="38"> 
        <a onclick="window.open('ecmseditor/FileMain.php?type=1&classid=&doing=2&field=ztimg','','width=700,height=550,scrollbars=yes');" title="ѡ�����ϴ���ͼƬ"><img src="../data/images/changeimg.gif" width="22" height="22" border="0" align="absbottom"></a></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">��ҳ�ؼ���</td>
      <td bgcolor="#FFFFFF"> <input name="ztpagekey" type="text" id="ztpagekey" value="<?=$r[ztpagekey]?>" size="38"></td>
    </tr>
    <tr> 
      <td height="25" valign="top" bgcolor="#FFFFFF">ר����</td>
      <td bgcolor="#FFFFFF"> <textarea name="intro" cols="70" rows="8" id="intro"><?=stripSlashes($r[intro])?></textarea></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">����</td>
      <td bgcolor="#FFFFFF"><input name="myorder" type="text" id="myorder" value="<?=$r[myorder]?>" size="38"> 
        <font color="#666666"> (ֵԽСԽǰ��)</font></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">��ʾ������</td>
      <td bgcolor="#FFFFFF"> <input type="radio" name="showzt" value="0"<?=$r[showzt]==0?' checked':''?>>
        �� 
        <input type="radio" name="showzt" value="1"<?=$r[showzt]==1?' checked':''?>>
        ��<font color="#666666">���磺ר�⵼����ǩ��</font></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">��Ϣ��ѡ��</td>
      <td bgcolor="#FFFFFF"><input type="radio" name="usezt" value="0"<?=$r[usezt]==0?' checked':''?>>
        �� 
        <input type="radio" name="usezt" value="1"<?=$r[usezt]==1?' checked':''?>>
        ��<font color="#666666">�����ѡ�����ô������Ϣʱ������ʾ���ר�⣩</font></td>
    </tr>
    <tr> 
      <td height="25" colspan="2">ҳ������</td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">ҳ����ʾģʽ</td>
      <td height="25" bgcolor="#FFFFFF"><input type="radio" name="islist" value="0"<?=$r[islist]==0?' checked':''?>>
        ����ʽ 
        <input type="radio" name="islist" value="1"<?=$r[islist]==1?' checked':''?>>
        �б�ʽ 
        <input type="radio" name="islist" value="2"<?=$r[islist]==2?' checked':''?>>
        ҳ������ʽ 
        <input name="oldislist" type="hidden" id="oldislist" value="<?=$r[islist]?>"></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">&nbsp;</td>
      <td height="25" bgcolor="#FFFFFF"><font color="#666666">˵��������ʽҪѡ�����ģ�塢�б�ʽҪѡ���б�ģ�塢����ʽҪ¼��ҳ������</font></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">����ģ��</td>
      <td height="25" bgcolor="#FFFFFF"><select name="classtempid">
          <?=$classtemp?>
        </select> <input type="button" name="Submit6223" value="��������ģ��" onclick="window.open('template/ListClasstemp.php?gid=<?=$thegid?>');"></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">�����б�ģ��(*)</td>
      <td height="25" bgcolor="#FFFFFF"> <select name="listtempid" id="listtempid">
          <?=$listtemp_options?>
        </select> <input type="button" name="Submit622" value="�����б�ģ��" onclick="window.open('template/ListListtemp.php?gid=<?=$thegid?>');">
        *</td>
    </tr>
    <tr> 
      <td rowspan="3" valign="top" bgcolor="#FFFFFF">�б�ʽ����</td>
      <td height="25" bgcolor="#FFFFFF"> <input name="reorder" type="text" id="reorder" value="<?=$r[reorder]?>" size="38"> 
        <select name="orderselect" onchange="document.form1.reorder.value=this.value">
          <option value="newstime DESC"></option>
          <option value="newstime DESC">������ʱ�併������</option>
          <option value="id DESC">��ID��������</option>
          <option value="onclick DESC">������ʽ�������</option>
          <option value="totaldown DESC">����������������</option>
          <option value="plnum DESC">����������������</option>
        </select> </td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF"> <table border="0" cellspacing="0" cellpadding="0">
          <tr> 
            <td width="90">��ʾ�ܼ�¼��</td>
            <td><input name="maxnum" type="text" id="maxnum" value="<?=$r[maxnum]?>" size="6"> 
              <font color="#666666">(0Ϊ��ʾ���м�¼)</font> </td>
          </tr>
        </table></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF"> <table border="0" cellspacing="0" cellpadding="0">
          <tr> 
            <td width="90">ÿҳ��ʾ��¼��</td>
            <td><input name="ztnum" type="text" id="ztnum3" value="<?=$r[ztnum]?>" size="6"></td>
          </tr>
        </table></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">ҳ������<font color="#666666">(֧�ֱ�ǩͬ����ģ��)</font></td>
      <td height="25" bgcolor="#FFFFFF">�뽫����<a href="#ecms" onclick="window.clipboardData.setData('Text',document.form1.classtext.value);document.form1.classtext.select()" title="�������ģ������"><strong>���Ƶ�Dreamweaver(�Ƽ�)</strong></a>����ʹ��<a href="#ecms" onclick="window.open('template/editor.php?getvar=opener.document.form1.classtext.value&returnvar=opener.document.form1.classtext.value&fun=ReturnHtml','editclasstext','width=880,height=600,scrollbars=auto,resizable=yes');"><strong>ģ�����߱༭</strong></a>���п��ӻ��༭</td>
    </tr>
    <tr> 
      <td height="25" colspan="2" bgcolor="#FFFFFF">
<textarea name="classtext" cols="80" rows="23" id="classtext" style="WIDTH: 100%"><?=htmlspecialchars(stripSlashes($addr[classtext]))?></textarea></td>
    </tr>
    <tr> 
      <td height="25" colspan="2">JS�������</td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">�Ƿ�����JS����</td>
      <td bgcolor="#FFFFFF">
<input type="radio" name="nrejs" value="0"<?=$r[nrejs]==0?' checked':''?>>
        ���� 
        <input type="radio" name="nrejs" value="1"<?=$r[nrejs]==1?' checked':''?>>
        ������</td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">����JSģ��</td>
      <td bgcolor="#FFFFFF">
<select name="jstempid" id="jstempid">
          <?=$jstemp?>
        </select> <input type="button" name="Submit62223" value="����JSģ��" onclick="window.open('template/ListJstemp.php?gid=<?=$thegid?>');"></td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">����ר��JS��ʾ</td>
      <td height="25" bgcolor="#FFFFFF"> <input name="newline" type="text" id="newline" value="<?=$r[newline]?>" size="38">
        ����¼</td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">����ר��JS��ʾ</td>
      <td height="25" bgcolor="#FFFFFF"> <input name="hotline" type="text" id="hotline" value="<?=$r[hotline]?>" size="38">
        ����¼</td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">�Ƽ�ר��JS��ʾ</td>
      <td height="25" bgcolor="#FFFFFF"> <input name="goodline" type="text" id="goodline" value="<?=$r[goodline]?>" size="38">
        ����¼</td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">����������Ϣjs��ʾ</td>
      <td bgcolor="#FFFFFF"> <input name="hotplline" type="text" id="hotplline" value="<?=$r[hotplline]?>" size="38">
        ����¼</td>
    </tr>
    <tr> 
      <td height="25" bgcolor="#FFFFFF">ͷ����Ϣjs��ʾ</td>
      <td bgcolor="#FFFFFF"> <input name="firstline" type="text" id="firstline" value="<?=$r[firstline]?>" size="38">
        ����¼</td>
    </tr>
	<?php
  	$ztfnum=$empire->gettotal("select count(*) as total from {$dbtbpre}enewsztf");
  	if($ztfnum)
  	{
  		$editorfnum=$empire->gettotal("select count(*) as total from {$dbtbpre}enewsztf where fform='editor' limit 1");	
		if($editorfnum)
		{
			include('ecmseditor/infoeditor/fckeditor.php');
		}
  	?>
    <tr> 
      <td height="25" colspan="2">�Զ����ֶ�����</td>
    </tr>
    <?php
	@include('../data/html/ztaddform.php');
	?>
	<tr bgcolor="#FFFFFF"> 
          
      <td height="30" colspan="2"><strong>ר���Զ����ֶε���˵��</strong><br>
        ���õ���ר���Զ����ֶκ�����ReturnZtAddField(ר��ID,�ֶ���)��ר��ID=0Ϊ��ǰר��ID��ȡ����ֶ����ݿ��ö��Ÿ��������ӣ�<br>
        ȡ��'classtext'�ֶ����ݣ�$value=ReturnZtAddField(0,'classtext'); //$value�����ֶ����ݡ�<br>
        ȡ�ö���ֶ����ݣ�$value=ReturnZtAddField(1,'ztid,classtext'); //$value['classtext']�����ֶ����ݡ�</td>
    </tr>
	<?php
	}
	?>
    <tr> 
      <td height="25" bgcolor="#FFFFFF"> <div align="center"></div></td>
      <td bgcolor="#FFFFFF"> <input type="submit" name="Submit" value="�ύ"> &nbsp;&nbsp; 
        <input type="reset" name="Submit2" value="����"> </td>
    </tr>
    <tr> 
      <td colspan="2"> 
  </form>
</table>
</body>
</html>
<?php
db_close();
$empire=null;
?>