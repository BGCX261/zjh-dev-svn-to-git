<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?><script>
function AddFj(str)
{var r;
var a;
a=document.add.softfj.value;
r=a.split(str);
if(r.length!=1)
{return true;}
document.add.softfj.value+="/"+str;
}
function DelFj(str)
{
var a;
a=document.add.softfj.value;
document.add.softfj.value=a.replace("/"+str,"");
}
</script>
<table width=100% align=center cellpadding=3 cellspacing=1 class="tableborder">
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>��������(*)</td>
    <td bgcolor=ffffff><table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#DBEAF5">
<tr> 
  <td height="25" bgcolor="#FFFFFF">
<?=$tts?"<select name='ttid'><option value='0'>�������</option>$tts</select>":""?>
	<input type=text name=title value="<?=htmlspecialchars(stripSlashes($r[title]))?>" size="60"> 
	<input type="button" name="button" value="ͼ��" onclick="document.add.title.value=document.add.title.value+'(ͼ��)';"> 
  </td>
</tr>
<tr> 
  <td height="25" bgcolor="#FFFFFF">����: 
	<input name="titlefont[b]" type="checkbox" value="b"<?=$titlefontb?>>����
	<input name="titlefont[i]" type="checkbox" value="i"<?=$titlefonti?>>б��
	<input name="titlefont[s]" type="checkbox" value="s"<?=$titlefonts?>>ɾ����
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;��ɫ: <input name="titlecolor" type="text" value="<?=stripSlashes($r[titlecolor])?>" size="10"><a onclick="foreColor();"><img src="../data/images/color.gif" width="21" height="21" align="absbottom"></a>
  </td>
</tr>
</table></td>
  </tr>
  <tr>
    <td width='16%' height=25 bgcolor='ffffff'>��������</td>
    <td bgcolor='ffffff'><table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#DBEAF5">
  <tr>
    <td height="25" bgcolor="#FFFFFF">��Ϣ����: 
      <input name="checked" type="checkbox" value="1"<?=$r[checked]?' checked':''?>>
      ��� &nbsp;&nbsp; �Ƽ� 
      <select name="isgood" id="isgood">
        <option value="0"<?=$r[isgood]==0?' selected':''?>>���Ƽ�</option>
        <option value="1"<?=$r[isgood]==1?' selected':''?>>һ���Ƽ�</option>
        <option value="2"<?=$r[isgood]==2?' selected':''?>>�����Ƽ�</option>
        <option value="3"<?=$r[isgood]==3?' selected':''?>>�����Ƽ�</option>
        <option value="4"<?=$r[isgood]==4?' selected':''?>>�ļ��Ƽ�</option>
        <option value="5"<?=$r[isgood]==5?' selected':''?>>�弶�Ƽ�</option>
        <option value="6"<?=$r[isgood]==6?' selected':''?>>�����Ƽ�</option>
        <option value="7"<?=$r[isgood]==7?' selected':''?>>�߼��Ƽ�</option>
        <option value="8"<?=$r[isgood]==8?' selected':''?>>�˼��Ƽ�</option>
        <option value="9"<?=$r[isgood]==9?' selected':''?>>�ż��Ƽ�</option>
      </select>
      &nbsp;&nbsp; ͷ�� 
      <select name="firsttitle" id="firsttitle">
        <option value="0"<?=$r[firsttitle]==0?' selected':''?>>��ͷ��</option>
        <option value="1"<?=$r[firsttitle]==1?' selected':''?>>һ��ͷ��</option>
        <option value="2"<?=$r[firsttitle]==2?' selected':''?>>����ͷ��</option>
        <option value="3"<?=$r[firsttitle]==3?' selected':''?>>����ͷ��</option>
        <option value="4"<?=$r[firsttitle]==4?' selected':''?>>�ļ�ͷ��</option>
        <option value="5"<?=$r[firsttitle]==5?' selected':''?>>�弶ͷ��</option>
        <option value="6"<?=$r[firsttitle]==6?' selected':''?>>����ͷ��</option>
        <option value="7"<?=$r[firsttitle]==7?' selected':''?>>�߼�ͷ��</option>
        <option value="8"<?=$r[firsttitle]==8?' selected':''?>>�˼�ͷ��</option>
        <option value="9"<?=$r[firsttitle]==9?' selected':''?>>�ż�ͷ��</option>
      </select></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF">�ؼ���&nbsp;&nbsp;&nbsp;: 
      <input name="keyboard" type="text" size="52" value="<?=stripSlashes($r[keyboard])?>">
      <font color="#666666">(�������&quot;,&quot;����)</font></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF">�ⲿ����: 
      <input name="titleurl" type="text" value="<?=stripSlashes($r[titleurl])?>" size="52">
      <font color="#666666">(��д����Ϣ���ӵ�ַ��Ϊ������)</font></td>
  </tr>
</table>
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>����ʱ��</td>
    <td bgcolor=ffffff><input name="newstime" type="text" value="<?=$r[newstime]?>"><input type=button name=button value="��Ϊ��ǰʱ��" onclick="document.add.newstime.value='<?=$todaytime?>'"></td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>����Ԥ��ͼ</td>
    <td bgcolor=ffffff>
<input name="titlepic" type="text" id="titlepic" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[titlepic]))?>" size="45">
<a onclick="window.open('ecmseditor/FileMain.php?type=1&classid=<?=$classid?>&filepass=<?=$filepass?>&doing=1&field=titlepic','','width=700,height=550,scrollbars=yes');" title="ѡ�����ϴ���ͼƬ"><img src="../data/images/changeimg.gif" border="0" align="absbottom"></a> 
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>��������</td>
    <td bgcolor=ffffff><input name="softwriter" type="text" size=60 id="softwriter" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[softwriter]))?>">
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>������ҳ</td>
    <td bgcolor=ffffff><input name="homepage" type="text" size=60 id="homepage" value="<?=$ecmsfirstpost==1?"http://":htmlspecialchars(stripSlashes($r[homepage]))?>">
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>ϵͳ��ʾ</td>
    <td bgcolor=ffffff><input name="demo" type="text" size=60 id="demo" value="<?=$ecmsfirstpost==1?"http://":htmlspecialchars(stripSlashes($r[demo]))?>">
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>���л���</td>
    <td bgcolor=ffffff><input name="softfj" type="text" size=60 id="softfj" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[softfj]))?>">
</td>
  </tr>
  <tr> 
    <td height=25 bgcolor=ffffff>&nbsp;</td>
    <td bgcolor=ffffff><input type=checkbox name=check value='Win9X/Me' onclick="if(this.checked){AddFj(this.value);}else{DelFj(this.value);}">
      Win9X/Me&nbsp; <input type=checkbox name=check value='WinNT/2000/XP' onclick="if(this.checked){AddFj(this.value);}else{DelFj(this.value);}">
      WinNT/2000/XP&nbsp; <input type=checkbox name=check value='Unix' onclick="if(this.checked){AddFj(this.value);}else{DelFj(this.value);}">
      Unix&nbsp; <input type=checkbox name=check value='Linux' onclick="if(this.checked){AddFj(this.value);}else{DelFj(this.value);}">
      Linux&nbsp; <input type=checkbox name=check value='DOS' onclick="if(this.checked){AddFj(this.value);}else{DelFj(this.value);}">
      DOS&nbsp; <input type=checkbox name=check value='MAC OS' onclick="if(this.checked){AddFj(this.value);}else{DelFj(this.value);}">
      MAC OS&nbsp; <input type=checkbox name=check value='Other' onclick="if(this.checked){AddFj(this.value);}else{DelFj(this.value);}">
      Other</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>��������</td>
    <td bgcolor=ffffff>�������ԣ�<select name="language" id="language"><option value="��������"<?=$r[language]=="��������"?' selected':''?>>��������</option><option value="��������"<?=$r[language]=="��������"?' selected':''?>>��������</option><option value="Ӣ��"<?=$r[language]=="Ӣ��"?' selected':''?>>Ӣ��</option><option value="�������"<?=$r[language]=="�������"?' selected':''?>>�������</option></select>���������ͣ�<select name="softtype" id="softtype"><option value="��������"<?=$r[softtype]=="��������"?' selected':''?>>��������</option><option value="��������"<?=$r[softtype]=="��������"?' selected':''?>>��������</option><option value="��������"<?=$r[softtype]=="��������"?' selected':''?>>��������</option></select>����Ȩ��ʽ��<select name="softsq" id="softsq"><option value="��������"<?=$r[softsq]=="��������"?' selected':''?>>��������</option><option value="�������"<?=$r[softsq]=="�������"?' selected':''?>>�������</option><option value="��������"<?=$r[softsq]=="��������"?' selected':''?>>��������</option><option value="��������"<?=$r[softsq]=="��������"?' selected':''?>>��������</option><option value="��ʾ����"<?=$r[softsq]=="��ʾ����"?' selected':''?>>��ʾ����</option><option value="��ҵ����"<?=$r[softsq]=="��ҵ����"?' selected':''?>>��ҵ����</option></select>���������ۣ�<select name="star" id="star"><option value="1"<?=$r[star]=="1"?' selected':''?>>1��</option><option value="2"<?=$r[star]=="2"||$ecmsfirstpost==1?' selected':''?>>2��</option><option value="3"<?=$r[star]=="3"?' selected':''?>>3��</option><option value="4"<?=$r[star]=="4"?' selected':''?>>4��</option><option value="5"<?=$r[star]=="5"?' selected':''?>>5��</option></select></td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>�ļ�</td>
    <td bgcolor=ffffff>�ļ����ͣ�<input name="filetype" type="text" id="filetype" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[filetype]))?>">
<select name="select2" onchange="document.add.filetype.value=this.value">
        <option value="">����</option>
        <option value=".zip">.zip</option>
        <option value=".rar">.rar</option>
        <option value=".exe">.exe</option>
      </select>���ļ���С��<input name="filesize" type="text" id="filesize" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[filesize]))?>">
<select name="select" onchange="document.add.filesize.value+=this.value">
        <option value="">��λ</option>
        <option value=" MB">MB</option>
        <option value=" KB">KB</option>
        <option value=" GB">GB</option>
        <option value=" BYTES">BYTES</option>
      </select></td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>���ص�ַ(*)</td>
    <td bgcolor=ffffff><script>
function doadd()
{var i;
var str="";
var oldi=0;
var j=0;
oldi=parseInt(document.add.editnum.value);
for(i=1;i<=document.add.downnum.value;i++)
{
j=i+oldi;
str=str+"<tr><td width=7%> <div align=center>"+j+"</div></td><td width=19%><div align=left><input name=downname[] type=text id=downname[] value=���ص�ַ"+j+" size=17></div></td><td width=40%><input name=downpath[] type=text size=36 id=downpath"+j+" ondblclick=SpOpenChFile(0,'downpath"+j+"')><select name=thedownqz[]><option value=''>--��ַǰ׺--</option><?=$newdownqz?></select></td><td width=21%><div align=center><select name=downuser[] id=select><option value=0>�ο�</option><?=$ygroup?></select></div></td><td width=13%><div align=center><input name=fen[] type=text id=fen[] value=0 size=6></div></td></tr>";
}
document.getElementById("adddown").innerHTML="<table width='100%' border=0 cellspacing=1 cellpadding=3>"+str+"</table>";
}
</script>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td height="25">���ص�ַǰ׺&nbsp;:
      <input name="downurl_qz" type="text" size="32">
      <select name="changeurl_qz" onchange="document.add.downurl_qz.value=document.add.changeurl_qz.value">
        <option value="" selected>ѡ��ǰ׺</option>
        <?=$downurlqz?>
      </select>
	  </td>
  </tr>
  <tr>
    <td height="25">ѡ��/�ϴ�����:
      <input name="changedown_url" id="changedown_url" type="text" size="32">
      <input type="button" name="Submit" value="ѡ��" onclick="window.open('ecmseditor/FileMain.php?type=0&classid=<?=$classid?>&filepass=<?=$filepass?>&doing=1&field=changedown_url','','width=700,height=550,scrollbars=yes');">&nbsp;
	  <input type="button" name="Submit" value="����" onclick="document.getElementById('changedown_url').focus();document.getElementById('changedown_url').select();clipboardData.setData('text',document.getElementById('changedown_url').value);"></td>
  </tr>
  <tr> 
    <td><table width="100%" border="0" cellpadding="3" cellspacing="1" bgcolor="#DBEAF5">
        <tr> 
          <td width="7%"> <div align="center">���</div></td>
          <td width="19%"><div align="left">��������</div></td>
          <td width="40%">���ص�ַ <font color="#666666">(˫��ѡ��)</font></td>
          <td width="21%"> <div align="center">Ȩ��</div></td>
          <td width="13%"> <div align="center">����</div></td>
        </tr>
      </table></td>
  </tr>
  <tr> 
    <td>
    <?php
    if($ecmsfirstpost==1)
    {
    ?>
	<table width='100%' border=0 cellspacing=1 cellpadding=3>
	<?php
	$editnum=3;
	for($pathi=1;$pathi<=$editnum;$pathi++)
	{
	?>
           <tr> 
              <td width='7%'> <div align=center><?=$pathi?></div></td>
              <td width='19%'> <div align=left> 
                  <input name=downname[] type=text value='���ص�ַ<?=$pathi?>' size=17>
                    </div></td>
              <td width='40%'>
	      <input name=downpath[] type=text size=36 id='downpath<?=$pathi?>' ondblclick="SpOpenChFile(0,'downpath<?=$pathi?>');">
	      <select name=thedownqz[]><option value=''>--��ַǰ׺--</option><?=$newdownqz?></select> 
                  </td>
                  <td width='21%'><div align=center> 
                      <select name=downuser[]>
                        <option value=0>�ο�</option>
                        <?=$ygroup?>
                      </select>
                    </div></td>
                  <td width='13%'> <div align=center> 
                      <input name=fen[] type=text value=0 size=6>
                    </div></td>
            </tr>
	<?php
	}
	?>
	</table>
    <?php
    }
    else
    {
	$editnum=0;
	$downloadpath="";
	if($r[downpath])
	{
		$r[downpath]=stripSlashes($r[downpath]);
		//���ص�ַ
		$j=0;
		$d_record=explode("\r\n",$r[downpath]);
		for($i=0;$i<count($d_record);$i++)
		{
			$j=$i+1;
			$d_field=explode("::::::",$d_record[$i]);
			//Ȩ��
			$tgroup=str_replace(" value=".$d_field[2].">"," value=".$d_field[2]." selected>",$ygroup);
			//��ַǰ׺
			$tnewdownqz=str_replace(" value='".$d_field[4]."'>"," value='".$d_field[4]."' selected>",$newdownqz);
			$downloadpath.="<tr><td width='7%'><div align=center>".$j."</div></td><td width='19%'><div align=left><input name=downname[] type=text id=downname[] value='".$d_field[0]."' size=17></div></td><td width='40%'><input name=downpath[] type=text id=downpath".$j." value='".$d_field[1]."' size=36 ondblclick=\"SpOpenChFile(0,'downpath".$j."');\"><select name=thedownqz[]><option value=''>--��ַǰ׺--</option>".$tnewdownqz."</select><input type=hidden name=pathid[] value=".$j."><input type=checkbox name=delpathid[] value=".$j.">ɾ</td><td width='21%'><div align=center><select name=downuser[] id=select><option value=0>�ο�</option>".$tgroup."</select></div></td><td width='13%'><div align=center><input name=fen[] type=text id=fen[] value='".$d_field[3]."' size=6></div></td></tr>";
		}
		$editnum=$j;
		$downloadpath="<table width='100%' border=0 cellspacing=1 cellpadding=3>".$downloadpath."</table>";
	}
	echo $downloadpath;
    }
    ?>
    </td>
  </tr>
  <tr> 
    <td height="25">���ص�ַ��չ����: <input name="editnum" type="hidden" id="editnum" value="<?=$editnum?>">
      <input name="downnum" type="text" id="downnum" value="1" size="6"> <input type="button" name="Submit5" value="�����ַ" onclick="javascript:doadd();"></td>
  </tr>
  <tr> 
    <td id=adddown></td>
  </tr>
</table>
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>�������(*)</td>
    <td bgcolor=ffffff><textarea name="softsay" cols="80" rows="10" id="softsay"><?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[softsay]))?></textarea>
</td>
  </tr>
</table>