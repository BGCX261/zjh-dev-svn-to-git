<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?><table width=100% align=center cellpadding=3 cellspacing=1 class="tableborder"><tr><td width=16% height=25 bgcolor=ffffff>标题</td><td bgcolor=ffffff><table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#DBEAF5">
<tr> 
  <td height="25" bgcolor="#FFFFFF">
<?=$tts?"<select name='ttid'><option value='0'>标题分类</option>$tts</select>":""?>
	<input type=text name=title value="<?=htmlspecialchars(stripSlashes($r[title]))?>" size="60"> 
	<input type="button" name="button" value="图文" onclick="document.add.title.value=document.add.title.value+'(图文)';"> 
  </td>
</tr>
<tr> 
  <td height="25" bgcolor="#FFFFFF">属性: 
	<input name="titlefont[b]" type="checkbox" value="b"<?=$titlefontb?>>粗体
	<input name="titlefont[i]" type="checkbox" value="i"<?=$titlefonti?>>斜体
	<input name="titlefont[s]" type="checkbox" value="s"<?=$titlefonts?>>删除线
	&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;颜色: <input name="titlecolor" type="text" value="<?=stripSlashes($r[titlecolor])?>" size="10"><a onclick="foreColor();"><img src="../data/images/color.gif" width="21" height="21" align="absbottom"></a>
  </td>
</tr>
</table></td></tr><tr><td width=16% height=25 bgcolor=ffffff>特殊属性</td><td bgcolor=ffffff><table width="100%" border="0" cellpadding="0" cellspacing="0" bgcolor="#DBEAF5">
  <tr>
    <td height="25" bgcolor="#FFFFFF">信息属性: 
      <input name="checked" type="checkbox" value="1"<?=$r[checked]?' checked':''?>>
      审核 &nbsp;&nbsp; 推荐 
      <select name="isgood" id="isgood">
        <option value="0"<?=$r[isgood]==0?' selected':''?>>不推荐</option>
        <option value="1"<?=$r[isgood]==1?' selected':''?>>一级推荐</option>
        <option value="2"<?=$r[isgood]==2?' selected':''?>>二级推荐</option>
        <option value="3"<?=$r[isgood]==3?' selected':''?>>三级推荐</option>
        <option value="4"<?=$r[isgood]==4?' selected':''?>>四级推荐</option>
        <option value="5"<?=$r[isgood]==5?' selected':''?>>五级推荐</option>
        <option value="6"<?=$r[isgood]==6?' selected':''?>>六级推荐</option>
        <option value="7"<?=$r[isgood]==7?' selected':''?>>七级推荐</option>
        <option value="8"<?=$r[isgood]==8?' selected':''?>>八级推荐</option>
        <option value="9"<?=$r[isgood]==9?' selected':''?>>九级推荐</option>
      </select>
      &nbsp;&nbsp; 头条 
      <select name="firsttitle" id="firsttitle">
        <option value="0"<?=$r[firsttitle]==0?' selected':''?>>非头条</option>
        <option value="1"<?=$r[firsttitle]==1?' selected':''?>>一级头条</option>
        <option value="2"<?=$r[firsttitle]==2?' selected':''?>>二级头条</option>
        <option value="3"<?=$r[firsttitle]==3?' selected':''?>>三级头条</option>
        <option value="4"<?=$r[firsttitle]==4?' selected':''?>>四级头条</option>
        <option value="5"<?=$r[firsttitle]==5?' selected':''?>>五级头条</option>
        <option value="6"<?=$r[firsttitle]==6?' selected':''?>>六级头条</option>
        <option value="7"<?=$r[firsttitle]==7?' selected':''?>>七级头条</option>
        <option value="8"<?=$r[firsttitle]==8?' selected':''?>>八级头条</option>
        <option value="9"<?=$r[firsttitle]==9?' selected':''?>>九级头条</option>
      </select></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF">关键字&nbsp;&nbsp;&nbsp;: 
      <input name="keyboard" type="text" size="52" value="<?=stripSlashes($r[keyboard])?>">
      <font color="#666666">(多个请用&quot;,&quot;隔开)</font></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF">外部链接: 
      <input name="titleurl" type="text" value="<?=stripSlashes($r[titleurl])?>" size="52">
      <font color="#666666">(填写后信息连接地址将为此链接)</font></td>
  </tr>
</table>
</td></tr><tr><td width=16% height=25 bgcolor=ffffff>发布时间</td><td bgcolor=ffffff><input name="newstime" type="text" value="<?=$r[newstime]?>"><input type=button name=button value="设为当前时间" onclick="document.add.newstime.value='<?=$todaytime?>'"></td></tr><tr><td width=16% height=25 bgcolor=ffffff>信息内容</td><td bgcolor=ffffff><textarea name="smalltext" cols="80" rows="10" id="smalltext"><?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[smalltext]))?></textarea>
</td></tr><tr><td width=16% height=25 bgcolor=ffffff>图片</td><td bgcolor=ffffff>
<input name="titlepic" type="text" id="titlepic" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[titlepic]))?>" size="45">
<a onclick="window.open('ecmseditor/FileMain.php?type=1&classid=<?=$classid?>&filepass=<?=$filepass?>&doing=1&field=titlepic','','width=700,height=550,scrollbars=yes');" title="选择已上传的图片"><img src="../data/images/changeimg.gif" border="0" align="absbottom"></a> 
</td></tr><tr><td width=16% height=25 bgcolor=ffffff>所在地</td><td bgcolor=ffffff><select name="myarea" id="myarea" size=6 style="width=150"><option value="东城区"<?=$r[myarea]=="东城区"||$ecmsfirstpost==1?' selected':''?>>东城区</option><option value="西城区"<?=$r[myarea]=="西城区"?' selected':''?>>西城区</option><option value="崇文区"<?=$r[myarea]=="崇文区"?' selected':''?>>崇文区</option><option value="宣武区"<?=$r[myarea]=="宣武区"?' selected':''?>>宣武区</option><option value="朝阳区"<?=$r[myarea]=="朝阳区"?' selected':''?>>朝阳区</option><option value="海淀区"<?=$r[myarea]=="海淀区"?' selected':''?>>海淀区</option><option value="丰台区"<?=$r[myarea]=="丰台区"?' selected':''?>>丰台区</option><option value="石景山区"<?=$r[myarea]=="石景山区"?' selected':''?>>石景山区</option><option value="通州区"<?=$r[myarea]=="通州区"?' selected':''?>>通州区</option><option value="昌平区"<?=$r[myarea]=="昌平区"?' selected':''?>>昌平区</option><option value="大兴区"<?=$r[myarea]=="大兴区"?' selected':''?>>大兴区</option><option value="其它"<?=$r[myarea]=="其它"?' selected':''?>>其它</option></select></td></tr><tr><td width=16% height=25 bgcolor=ffffff>联系邮箱</td><td bgcolor=ffffff><input name="email" type="text" id="email" value="<?=$ecmsfirstpost==1?$memberinfor[$user_email]:htmlspecialchars(stripSlashes($r[email]))?>" size="60">
</td></tr><tr><td width=16% height=25 bgcolor=ffffff>联系方式</td><td bgcolor=ffffff><input name="mycontact" type="text" size=60 id="mycontact" value="<?=$ecmsfirstpost==1?"":htmlspecialchars(stripSlashes($r[mycontact]))?>">
</td></tr><tr><td width=16% height=25 bgcolor=ffffff>联系地址</td><td bgcolor=ffffff><input name="address" type="text" id="address" value="<?=$ecmsfirstpost==1?$memberinfor[address]:htmlspecialchars(stripSlashes($r[address]))?>" size="60">
</td></tr></table>