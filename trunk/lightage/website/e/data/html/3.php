<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?><table width=100% align=center cellpadding=3 cellspacing=1 class=tableborder>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>ͼƬ����(*)</td>
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
    <td width=16% height=25 bgcolor=ffffff>�ļ���С</td>
    <td bgcolor=ffffff><input name="filesize" type="text" size=60 id="filesize" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[filesize]))?>">
<select name="select" onchange="document.add.filesize.value+=this.value">
        <option value="">��λ</option>
        <option value=" MB">MB</option>
        <option value=" KB">KB</option>
        <option value=" GB">GB</option>
        <option value=" BYTES">BYTES</option>
      </select></td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>��ͼ����</td>
    <td bgcolor=ffffff>ͼƬ�ߴ磺<input name="picsize" type="text" id="picsize" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[picsize]))?>">
��ͼƬ�ֱ��ʣ�<input name="picfbl" type="text" id="picfbl" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[picfbl]))?>">
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>��Դ</td>
    <td bgcolor=ffffff><input name="picfrom" type="text" size=60 id="picfrom" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[picfrom]))?>">
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>ͼƬСͼ</td>
    <td bgcolor=ffffff>
<input name="titlepic" type="text" id="titlepic" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[titlepic]))?>" size="45">
<a onclick="window.open('ecmseditor/FileMain.php?type=1&classid=<?=$classid?>&filepass=<?=$filepass?>&doing=1&field=titlepic','','width=700,height=550,scrollbars=yes');" title="ѡ�����ϴ���ͼƬ"><img src="../data/images/changeimg.gif" border="0" align="absbottom"></a> 
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>ͼƬ��ͼ</td>
    <td bgcolor=ffffff>
<input name="picurl" type="text" id="picurl" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[picurl]))?>" size="45">
<a onclick="window.open('ecmseditor/FileMain.php?type=1&classid=<?=$classid?>&filepass=<?=$filepass?>&doing=1&field=picurl','','width=700,height=550,scrollbars=yes');" title="ѡ�����ϴ���ͼƬ"><img src="../data/images/changeimg.gif" border="0" align="absbottom"></a> 
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>ͼƬ��</td>
    <td bgcolor=ffffff><script>
function dopicadd()
{var i;
var str="";
var oldi=0;
var j=0;
oldi=parseInt(document.add.morepicnum.value);
for(i=1;i<=document.add.downmorepicnum.value;i++)
{
j=i+oldi;
str=str+"<tr><td width=7%><div align=center>"+j+"</div></td><td width=33%><div align=center><input name=msmallpic[] type=text size=28 id=msmallpic"+j+" ondblclick=SpOpenChFile(1,'msmallpic"+j+"')><br><input type=file name=msmallpfile[] size=15></div></td><td width=30%><div align=center><input name=mbigpic[] type=text size=28 id=mbigpic"+j+" ondblclick=SpOpenChFile(1,'mbigpic"+j+"')><br><input type=file name=mbigpfile[] size=15></div></td><td width=30%><div align=center><input name=mpicname[] type=text></div></td></tr>";
}
document.getElementById("addpicdown").innerHTML="<table width='100%' border=0 cellspacing=1 cellpadding=3>"+str+"</table>";
}
</script>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td height="25">
	ͼƬ��ַǰ׺:
      <input name="mpicurl_qz" type="text" id="mpicurl_qz">&nbsp;&nbsp;
	  <input type="checkbox" name="msavepic" value="1">Զ�̱���&nbsp;<input type="checkbox" name="mcreatespic" value="1" onclick="if(this.checked){setmcreatespic.style.display='';}else{setmcreatespic.style.display='none';}">������ͼ
	  <span id="setmcreatespic" style="display=none">��<input type=text name="mcreatespicwidth" size=4 value="<?=$public_r[spicwidth]?>">*<input type=text name="mcreatespicheight" size=4 value="<?=$public_r[spicheight]?>">(��*��)</span>
 </td>
  </tr>
  <tr> 
    <td><table width="100%" border=0 align=center cellpadding=3 cellspacing=1>
  <tr bgcolor="#DBEAF5"> 
    <td width="7%"><div align=center>���</div></td>
    <td width="33%"><div align=center>��ͼ <font color="#666666">(˫��ѡ��)</font></div></td>
    <td width="30%"><div align=center>��ͼ <font color="#666666">(˫��ѡ��)</font></div></td>
    <td width="30%"><div align=center>ͼƬ˵��</div></td>
  </tr>
</table></td>
  </tr>
  <tr> 
    <td>
    <?php
    if($ecmsfirstpost==1)
    {
	?>
	<table width='100%' border=0 align=center cellpadding=3 cellspacing=1>
	<?php
	$morepicnum=3;
	for($mppathi=1;$mppathi<=$morepicnum;$mppathi++)
	{
	?>
	<tr> 
		<td width='7%'><div align=center><?=$mppathi?></div></td>
		<td width='33%'><div align=center>
		<input name=msmallpic[] type=text id='msmallpic<?=$mppathi?>' size=28 ondblclick="SpOpenChFile(1,'msmallpic<?=$mppathi?>');">
		<br><input type=file name=msmallpfile[] size=15>
		</div></td>
		<td width='30%'><div align=center>
		<input name=mbigpic[] type=text id='mbigpic<?=$mppathi?>' size=28 ondblclick="SpOpenChFile(1,'mbigpic<?=$mppathi?>');">
		<br><input type=file name=mbigpfile[] size=15>
		</div></td>
		<td width='30%'><div align=center>
		<input name=mpicname[] type=text id='mpicname<?=$mppathi?>'>
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
	$morepicpath="";
	$morepicnum=0;
	if($r[morepic])
    	{
    		$r[morepic]=stripSlashes($r[morepic]);
    		//��ַ
    		$j=0;
    		$pd_record=explode("\r\n",$r[morepic]);
    		for($i=0;$i<count($pd_record);$i++)
    		{
			$j=$i+1;
    			$pd_field=explode("::::::",$pd_record[$i]);
			$morepicpath.="<tr> 
    <td width='7%'><div align=center>".$j."</div></td>
    <td width='33%'><div align=center>
        <input name=msmallpic[] type=text value='".$pd_field[0]."' size=28 id=msmallpic".$j." ondblclick=\"SpOpenChFile(1,'msmallpic".$j."');\">
		<br><input type=file name=msmallpfile[] size=15>
      </div></td>
    <td width='30%'><div align=center>
        <input name=mbigpic[] type=text value='".$pd_field[1]."' size=28 id=mbigpic".$j." ondblclick=\"SpOpenChFile(1,'mbigpic".$j."');\">
		<br><input type=file name=mbigpfile[] size=15>
      </div></td>
    <td width='30%'><div align=center>
        <input name=mpicname[] type=text value='".$pd_field[2]."'><input type=hidden name=mpicid[] value=".$j."><input type=checkbox name=mdelpicid[] value=".$j.">ɾ
      </div></td>
  </tr>";
    		}
    		$morepicnum=$j;
    		$morepicpath="<table width='100%' border=0 cellspacing=1 cellpadding=3>".$morepicpath."</table>";
    	}
	echo $morepicpath;
    }
    ?>
    </td>
  </tr>
  <tr> 
    <td height="25">��ַ��չ����: <input name="morepicnum" type="hidden" id="morepicnum" value="<?=$morepicnum?>">
      <input name="downmorepicnum" type="text" value="1" size="6"> <input type="button" name="Submit5" value="�����ַ" onclick="javascript:dopicadd();"></td>
  </tr>
  <tr> 
    <td id=addpicdown></td>
  </tr>
</table>
</td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>ͼ������</td>
    <td bgcolor=ffffff>ÿ����ʾ������<input name="num" type="text" size=3 id="num" value="<?=$ecmsfirstpost==1?"3":htmlspecialchars(stripSlashes($r[num]))?>">
����ͼ��С��<input name="width" type="text" size=6 id="width" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[width]))?>">
*<input name="height" type="text" size=6 id="height" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[height]))?>">
<font color="#666666">(��*��)</font></td>
  </tr>
  <tr> 
    <td width=16% height=25 bgcolor=ffffff>ͼƬ���(*)</td>
    <td bgcolor=ffffff><textarea name="picsay" cols="80" rows="10" id="picsay"><?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[picsay]))?></textarea>
</td>
  </tr>
</table>