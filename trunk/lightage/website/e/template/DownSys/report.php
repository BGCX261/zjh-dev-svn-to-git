<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?>
<?php
$url="<a href=../../../>��ҳ</a>&nbsp;>&nbsp;<a href='".$titleurl."'>".$r[title]."</a>&nbsp;>&nbsp;�ύ���󱨸�";
require(ECMS_PATH.'e/data/template/cp_1.php');
?>
<form name="form1" method="post" action="../../enews/index.php">
  <table width="600" border="0" align="center" cellpadding="3" cellspacing="1"class=tableborder>
  <input type="hidden" name="cid" value="<?=$cid?>">
    <tr class=header> 
      <td height="23" colspan="2">�ύ���󱨸�</td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td width="137" height="23"><div align="left">��Ϣ����:</div></td>
      <td width="448" height="23"><a href='<?=$titleurl?>' target=_blank><?=$r[title]?></a></td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td height="23"><div align="left">��������:</div></td>
      <td height="23"><input name="email" type="text" id="email">
        ������ظ�����</td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td height="23"><div align="left">��������(*):</div></td>
      <td height="23"><textarea name="errortext" cols="60" rows="12" id="name4"></textarea></td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td height="23">&nbsp;</td>
      <td height="23"><input type="submit" name="Submit" value="�ύ"> <input type="reset" name="Submit2" value="����"> 
        <input name="enews" type="hidden" id="enews" value="AddError">
        <input name="id" type="hidden" id="id" value="<?=$id?>">
        <input name="classid" type="hidden" id="classid" value="<?=$classid?>"></td>
    </tr>
  </table>
</form>
<?php
require(ECMS_PATH.'e/data/template/cp_2.php');
?>