<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>�鿴��Ϣ</title>
<link href="../../data/images/qcss.css" rel="stylesheet" type="text/css">
</head>

<body>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class=tableborder style='word-break:break-all'>
  <tr class=header> 
    <td height="25" colspan="2">���⣺<?=$r[title]?></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td width="19%" height="25">�ύ��:</td>
    <td width="81%" height="25"> 
      <?=$r[uname]?>
    </td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25">����ʱ��:</td>
    <td height="25"> 
      <?=$r[addtime]?>
    </td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25">IP��ַ:</td>
    <td height="25"> 
      <?=$r[ip]?>
    </td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25">����:</td>
    <td height="25"><?=$r[name]?></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25">��˾����:</td>
    <td height="25"><?=$r[company]?></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25">��ϵ����:</td>
    <td height="25"><?=$r[email]?></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25">��ϵ�绰:</td>
    <td height="25"><?=$r[phone]?></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25">����:</td>
    <td height="25"><?=$r[fax]?></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25">��ϵ��ַ:</td>
    <td height="25"><?=$r[address]?>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;�ʱࣺ<?=$r[zip]?></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25">��Ϣ����:</td>
    <td height="25"><?=$r[title]?></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25" valign="top">��Ϣ����:</td>
    <td height="25"><?=nl2br($r[ftext])?></td>
  </tr>
  <tr bgcolor="#FFFFFF"> 
    <td height="25" colspan="2"><div align="center">[ <a href="javascript:window.close();">�� 
        ��</a> ]</div></td>
  </tr>
</table>
</body>
</html>