<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?><!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>������Ŀ</title>
<SCRIPT lanuage="JScript">
function turnit(ss)
{
 if (ss.style.display=="") 
  ss.style.display="none";
 else
  ss.style.display=""; 
}
var newWindow = null

//���õ�ַ
function tvurl(classid){
	window.open('view/ClassUrl.php?classid='+classid,'','width=500,height=250');
}
//ˢ����Ŀ
function relist(classid){
	self.location.href='enews.php?enews=ReListHtml&from=ListClass.php&classid='+classid;
}
//ˢ����Ϣ
function renews(classid,tbname){
	window.open('ReHtml/DoRehtml.php?enews=ReNewsHtml&from=ListClass.php&classid='+classid+'&tbname[]='+tbname);
}
//�鵵
function docinfo(classid){
	if(confirm('ȷ�Ϲ鵵?'))
	{
		self.location.href='ecmsinfo.php?enews=InfoToDoc&ecmsdoc=1&docfrom=ListClass.php&classid='+classid;
	}
}
//ˢ��JS
function rejs(classid){
	self.location.href='ecmschtml.php?enews=ReSingleJs&doing=0&classid='+classid;
}
//����
function copyc(classid){
	self.location.href='AddClass.php?classid='+classid+'&enews=AddClass&docopy=1';
}
//�޸�
function editc(classid){
	self.location.href='AddClass.php?classid='+classid+'&enews=EditClass';
}
//ɾ��
function delc(classid){
	if(confirm('ȷ��Ҫɾ������Ŀ����ɾ����������Ŀ����Ϣ'))
	{
		self.location.href='ecmsclass.php?classid='+classid+'&enews=DelClass';
	}
}
//�������
function ttc(classid){
	window.open('ClassInfoType.php?classid='+classid);
}
</SCRIPT>
</head>
<body>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1">
  <tr> 
    <td width="18%">λ��: <a href="ListClass.php">������Ŀ</a></td>
    <td width="82%"> <div align="right" class="emenubutton">
        <input type="button" name="Submit6" value="������Ŀ" onclick="self.location.href='AddClass.php?enews=AddClass'">
        <input type="button" name="Submit" value="ˢ����ҳ" onclick="self.location.href='ecmschtml.php?enews=ReIndex'">
        <input type="button" name="Submit2" value="ˢ��������Ŀҳ" onclick="window.open('ecmschtml.php?enews=ReListHtml_all&from=ListClass.php','','');">
        <input type="button" name="Submit3" value="ˢ��������Ϣҳ��" onclick="window.open('ReHtml/DoRehtml.php?enews=ReNewsHtml&start=0&from=ListClass.php','','');">
        <input type="button" name="Submit4" value="ˢ������JS����" onclick="window.open('ecmschtml.php?enews=ReAllNewsJs&from=ListClass.php','','');">
      </div></td>
  </tr>
</table>
<table width="100%" border="0" cellpadding="3" cellspacing="1" class="tableborder">
  <form name=editorder method=post action=ecmsclass.php onsubmit="return confirm('ȷ��Ҫ����?');">
    <tr class="header" height="25"> 
      <td width="5%" align="center">˳��</td>
      <td width="7%" align="center"><a href='ListClass.php?doopen=1&open=1' title='����'><img src='../data/images/displayadd.gif' width='15' height='15' border='0'></a></td>
      <td width="6%" align="center">ID</td>
      <td width="36%">��Ŀ��</td>
      <td width="6%" align="center">����</td>
      <td width="14%">��Ŀ����</td>
      <td width="29%">����</td>
    </tr>
    <tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=1></td><td><a href='AddNews.php?enews=AddNews&classid=1' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>1</td><td><input type=checkbox name=reclassid[] value=1> <a href='/' target=_blank>��վ��ҳ</a></td><td align=center>0</td><td><a href='#e' onclick=editc(1)>�޸�</a> <a href='#e' onclick=copyc(1)>����</a> <a href='#e' onclick=delc(1)>ɾ��</a></td><td><a href='#e' onclick=relist(1)>ˢ��</a> <a href='#e' onclick=renews(1,'news')>��Ϣ</a> <a href='#e' onclick=rejs(1)>JS</a> <a href='#e' onclick=tvurl(1)>����</a> <a href='#e' onclick=ttc(1)>����</a> <a href='#e' onclick=docinfo(1)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=2></td><td><a href='AddNews.php?enews=AddNews&classid=2' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>2</td><td><input type=checkbox name=reclassid[] value=2> <a href='/gywm/' target=_blank>��������</a></td><td align=center>0</td><td><a href='#e' onclick=editc(2)>�޸�</a> <a href='#e' onclick=copyc(2)>����</a> <a href='#e' onclick=delc(2)>ɾ��</a></td><td><a href='#e' onclick=relist(2)>ˢ��</a> <a href='#e' onclick=renews(2,'news')>��Ϣ</a> <a href='#e' onclick=rejs(2)>JS</a> <a href='#e' onclick=tvurl(2)>����</a> <a href='#e' onclick=ttc(2)>����</a> <a href='#e' onclick=docinfo(2)>�鵵</a></td></tr><tr bgcolor='#DBEAF5' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=3></td><td onMouseUp='turnit(classdiv3);' style='CURSOR:hand'><img src='../data/images/dir.gif'></td><td align=center>3</td><td><input type=checkbox name=reclassid[] value=3> <a href='/zpxs/' target=_blank>��Ʒ����</a></td><td align=center>0</td><td><a href='#e' onclick=editc(3)>�޸�</a> <a href='#e' onclick=copyc(3)>����</a> <a href='#e' onclick=delc(3)>ɾ��</a></td><td><a href='#e' onclick=relist(3)>ˢ��</a> <a href='#e' onclick=renews(3,'news')>��Ϣ</a> <a href='#e' onclick=rejs(3)>JS</a> <a href='#e' onclick=tvurl(3)>����</a></td></tr><tbody id='classdiv3'><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=7></td><td>&nbsp;&nbsp;&nbsp;<img src='../data/images/dir.gif'></td><td align=center>7</td><td><input type=checkbox name=reclassid[] value=7> <a href='/zpxs/1/' target=_blank>дʵ���</a></td><td align=center>0</td><td><a href='#e' onclick=editc(7)>�޸�</a> <a href='#e' onclick=copyc(7)>����</a> <a href='#e' onclick=delc(7)>ɾ��</a></td><td><a href='#e' onclick=relist(7)>ˢ��</a> <a href='#e' onclick=renews(7,'news')>��Ϣ</a> <a href='#e' onclick=rejs(7)>JS</a> <a href='#e' onclick=tvurl(7)>����</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=14></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=14' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>14</td><td><input type=checkbox name=reclassid[] value=14> <a href='/zpxs/1/1/' target=_blank>�й���</a></td><td align=center>0</td><td><a href='#e' onclick=editc(14)>�޸�</a> <a href='#e' onclick=copyc(14)>����</a> <a href='#e' onclick=delc(14)>ɾ��</a></td><td><a href='#e' onclick=relist(14)>ˢ��</a> <a href='#e' onclick=renews(14,'news')>��Ϣ</a> <a href='#e' onclick=rejs(14)>JS</a> <a href='#e' onclick=tvurl(14)>����</a> <a href='#e' onclick=ttc(14)>����</a> <a href='#e' onclick=docinfo(14)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=15></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=15' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>15</td><td><input type=checkbox name=reclassid[] value=15> <a href='/zpxs/1/2/' target=_blank>ŷ����</a></td><td align=center>0</td><td><a href='#e' onclick=editc(15)>�޸�</a> <a href='#e' onclick=copyc(15)>����</a> <a href='#e' onclick=delc(15)>ɾ��</a></td><td><a href='#e' onclick=relist(15)>ˢ��</a> <a href='#e' onclick=renews(15,'news')>��Ϣ</a> <a href='#e' onclick=rejs(15)>JS</a> <a href='#e' onclick=tvurl(15)>����</a> <a href='#e' onclick=ttc(15)>����</a> <a href='#e' onclick=docinfo(15)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=16></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=16' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>16</td><td><input type=checkbox name=reclassid[] value=16> <a href='/zpxs/1/3/' target=_blank>����</a></td><td align=center>0</td><td><a href='#e' onclick=editc(16)>�޸�</a> <a href='#e' onclick=copyc(16)>����</a> <a href='#e' onclick=delc(16)>ɾ��</a></td><td><a href='#e' onclick=relist(16)>ˢ��</a> <a href='#e' onclick=renews(16,'news')>��Ϣ</a> <a href='#e' onclick=rejs(16)>JS</a> <a href='#e' onclick=tvurl(16)>����</a> <a href='#e' onclick=ttc(16)>����</a> <a href='#e' onclick=docinfo(16)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=8></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=8' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>8</td><td><input type=checkbox name=reclassid[] value=8> <a href='/zpxs/2/' target=_blank>��ͨ���</a></td><td align=center>0</td><td><a href='#e' onclick=editc(8)>�޸�</a> <a href='#e' onclick=copyc(8)>����</a> <a href='#e' onclick=delc(8)>ɾ��</a></td><td><a href='#e' onclick=relist(8)>ˢ��</a> <a href='#e' onclick=renews(8,'news')>��Ϣ</a> <a href='#e' onclick=rejs(8)>JS</a> <a href='#e' onclick=tvurl(8)>����</a> <a href='#e' onclick=ttc(8)>����</a> <a href='#e' onclick=docinfo(8)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=9></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=9' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>9</td><td><input type=checkbox name=reclassid[] value=9> <a href='/zpxs/3/' target=_blank>Ψ�����</a></td><td align=center>0</td><td><a href='#e' onclick=editc(9)>�޸�</a> <a href='#e' onclick=copyc(9)>����</a> <a href='#e' onclick=delc(9)>ɾ��</a></td><td><a href='#e' onclick=relist(9)>ˢ��</a> <a href='#e' onclick=renews(9,'news')>��Ϣ</a> <a href='#e' onclick=rejs(9)>JS</a> <a href='#e' onclick=tvurl(9)>����</a> <a href='#e' onclick=ttc(9)>����</a> <a href='#e' onclick=docinfo(9)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=10></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=10' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>10</td><td><input type=checkbox name=reclassid[] value=10> <a href='/zpxs/4/' target=_blank>�廭</a></td><td align=center>0</td><td><a href='#e' onclick=editc(10)>�޸�</a> <a href='#e' onclick=copyc(10)>����</a> <a href='#e' onclick=delc(10)>ɾ��</a></td><td><a href='#e' onclick=relist(10)>ˢ��</a> <a href='#e' onclick=renews(10,'news')>��Ϣ</a> <a href='#e' onclick=rejs(10)>JS</a> <a href='#e' onclick=tvurl(10)>����</a> <a href='#e' onclick=ttc(10)>����</a> <a href='#e' onclick=docinfo(10)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=11></td><td>&nbsp;&nbsp;&nbsp;<img src='../data/images/dir.gif'></td><td align=center>11</td><td><input type=checkbox name=reclassid[] value=11> <a href='/zpxs/5/' target=_blank>����</a></td><td align=center>0</td><td><a href='#e' onclick=editc(11)>�޸�</a> <a href='#e' onclick=copyc(11)>����</a> <a href='#e' onclick=delc(11)>ɾ��</a></td><td><a href='#e' onclick=relist(11)>ˢ��</a> <a href='#e' onclick=renews(11,'news')>��Ϣ</a> <a href='#e' onclick=rejs(11)>JS</a> <a href='#e' onclick=tvurl(11)>����</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=12></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=12' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>12</td><td><input type=checkbox name=reclassid[] value=12> <a href='/zpxs/5/1/' target=_blank>С������</a></td><td align=center>0</td><td><a href='#e' onclick=editc(12)>�޸�</a> <a href='#e' onclick=copyc(12)>����</a> <a href='#e' onclick=delc(12)>ɾ��</a></td><td><a href='#e' onclick=relist(12)>ˢ��</a> <a href='#e' onclick=renews(12,'news')>��Ϣ</a> <a href='#e' onclick=rejs(12)>JS</a> <a href='#e' onclick=tvurl(12)>����</a> <a href='#e' onclick=ttc(12)>����</a> <a href='#e' onclick=docinfo(12)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=13></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=13' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>13</td><td><input type=checkbox name=reclassid[] value=13> <a href='/zpxs/6/' target=_blank>3Dģ��</a></td><td align=center>0</td><td><a href='#e' onclick=editc(13)>�޸�</a> <a href='#e' onclick=copyc(13)>����</a> <a href='#e' onclick=delc(13)>ɾ��</a></td><td><a href='#e' onclick=relist(13)>ˢ��</a> <a href='#e' onclick=renews(13,'news')>��Ϣ</a> <a href='#e' onclick=rejs(13)>JS</a> <a href='#e' onclick=tvurl(13)>����</a> <a href='#e' onclick=ttc(13)>����</a> <a href='#e' onclick=docinfo(13)>�鵵</a></td></tr></tbody><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=4></td><td><a href='AddNews.php?enews=AddNews&classid=4' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>4</td><td><input type=checkbox name=reclassid[] value=4> <a href='/ywfw/' target=_blank>ҵ��Χ</a></td><td align=center>0</td><td><a href='#e' onclick=editc(4)>�޸�</a> <a href='#e' onclick=copyc(4)>����</a> <a href='#e' onclick=delc(4)>ɾ��</a></td><td><a href='#e' onclick=relist(4)>ˢ��</a> <a href='#e' onclick=renews(4,'news')>��Ϣ</a> <a href='#e' onclick=rejs(4)>JS</a> <a href='#e' onclick=tvurl(4)>����</a> <a href='#e' onclick=ttc(4)>����</a> <a href='#e' onclick=docinfo(4)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=5></td><td><a href='AddNews.php?enews=AddNews&classid=5' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>5</td><td><input type=checkbox name=reclassid[] value=5> <a href='/zprc/' target=_blank>��Ƹ�˲�</a></td><td align=center>0</td><td><a href='#e' onclick=editc(5)>�޸�</a> <a href='#e' onclick=copyc(5)>����</a> <a href='#e' onclick=delc(5)>ɾ��</a></td><td><a href='#e' onclick=relist(5)>ˢ��</a> <a href='#e' onclick=renews(5,'news')>��Ϣ</a> <a href='#e' onclick=rejs(5)>JS</a> <a href='#e' onclick=tvurl(5)>����</a> <a href='#e' onclick=ttc(5)>����</a> <a href='#e' onclick=docinfo(5)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=6></td><td><a href='AddNews.php?enews=AddNews&classid=6' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>6</td><td><input type=checkbox name=reclassid[] value=6> <a href='/lxwm/' target=_blank>��ϵ����</a></td><td align=center>0</td><td><a href='#e' onclick=editc(6)>�޸�</a> <a href='#e' onclick=copyc(6)>����</a> <a href='#e' onclick=delc(6)>ɾ��</a></td><td><a href='#e' onclick=relist(6)>ˢ��</a> <a href='#e' onclick=renews(6,'news')>��Ϣ</a> <a href='#e' onclick=rejs(6)>JS</a> <a href='#e' onclick=tvurl(6)>����</a> <a href='#e' onclick=ttc(6)>����</a> <a href='#e' onclick=docinfo(6)>�鵵</a></td></tr><tr bgcolor='#DBEAF5' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=17></td><td onMouseUp='turnit(classdiv17);' style='CURSOR:hand'><img src='../data/images/dir.gif'></td><td align=center>17</td><td><input type=checkbox name=reclassid[] value=17> <a href='/home/' target=_blank>HOME</a></td><td align=center>0</td><td><a href='#e' onclick=editc(17)>�޸�</a> <a href='#e' onclick=copyc(17)>����</a> <a href='#e' onclick=delc(17)>ɾ��</a></td><td><a href='#e' onclick=relist(17)>ˢ��</a> <a href='#e' onclick=renews(17,'news')>��Ϣ</a> <a href='#e' onclick=rejs(17)>JS</a> <a href='#e' onclick=tvurl(17)>����</a></td></tr><tbody id='classdiv17'></tbody><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=18></td><td><a href='AddNews.php?enews=AddNews&classid=18' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>18</td><td><input type=checkbox name=reclassid[] value=18> <a href='/about/' target=_blank>ABOUT US</a></td><td align=center>0</td><td><a href='#e' onclick=editc(18)>�޸�</a> <a href='#e' onclick=copyc(18)>����</a> <a href='#e' onclick=delc(18)>ɾ��</a></td><td><a href='#e' onclick=relist(18)>ˢ��</a> <a href='#e' onclick=renews(18,'news')>��Ϣ</a> <a href='#e' onclick=rejs(18)>JS</a> <a href='#e' onclick=tvurl(18)>����</a> <a href='#e' onclick=ttc(18)>����</a> <a href='#e' onclick=docinfo(18)>�鵵</a></td></tr><tr bgcolor='#DBEAF5' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=19></td><td onMouseUp='turnit(classdiv19);' style='CURSOR:hand'><img src='../data/images/dir.gif'></td><td align=center>19</td><td><input type=checkbox name=reclassid[] value=19> <a href='/Gallery/' target=_blank>GALLERY</a></td><td align=center>0</td><td><a href='#e' onclick=editc(19)>�޸�</a> <a href='#e' onclick=copyc(19)>����</a> <a href='#e' onclick=delc(19)>ɾ��</a></td><td><a href='#e' onclick=relist(19)>ˢ��</a> <a href='#e' onclick=renews(19,'news')>��Ϣ</a> <a href='#e' onclick=rejs(19)>JS</a> <a href='#e' onclick=tvurl(19)>����</a></td></tr><tbody id='classdiv19'><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=23></td><td>&nbsp;&nbsp;&nbsp;<img src='../data/images/dir.gif'></td><td align=center>23</td><td><input type=checkbox name=reclassid[] value=23> <a href='/Gallery/1/' target=_blank>Realist Style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(23)>�޸�</a> <a href='#e' onclick=copyc(23)>����</a> <a href='#e' onclick=delc(23)>ɾ��</a></td><td><a href='#e' onclick=relist(23)>ˢ��</a> <a href='#e' onclick=renews(23,'news')>��Ϣ</a> <a href='#e' onclick=rejs(23)>JS</a> <a href='#e' onclick=tvurl(23)>����</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=28></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=28' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>28</td><td><input type=checkbox name=reclassid[] value=28> <a href='/Gallery/1/1/' target=_blank>Chinese Style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(28)>�޸�</a> <a href='#e' onclick=copyc(28)>����</a> <a href='#e' onclick=delc(28)>ɾ��</a></td><td><a href='#e' onclick=relist(28)>ˢ��</a> <a href='#e' onclick=renews(28,'news')>��Ϣ</a> <a href='#e' onclick=rejs(28)>JS</a> <a href='#e' onclick=tvurl(28)>����</a> <a href='#e' onclick=ttc(28)>����</a> <a href='#e' onclick=docinfo(28)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=29></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=29' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>29</td><td><input type=checkbox name=reclassid[] value=29> <a href='/Gallery/1/2/' target=_blank>Western Style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(29)>�޸�</a> <a href='#e' onclick=copyc(29)>����</a> <a href='#e' onclick=delc(29)>ɾ��</a></td><td><a href='#e' onclick=relist(29)>ˢ��</a> <a href='#e' onclick=renews(29,'news')>��Ϣ</a> <a href='#e' onclick=rejs(29)>JS</a> <a href='#e' onclick=tvurl(29)>����</a> <a href='#e' onclick=ttc(29)>����</a> <a href='#e' onclick=docinfo(29)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=30></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=30' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>30</td><td><input type=checkbox name=reclassid[] value=30> <a href='/Gallery/1/3/' target=_blank>Scene</a></td><td align=center>0</td><td><a href='#e' onclick=editc(30)>�޸�</a> <a href='#e' onclick=copyc(30)>����</a> <a href='#e' onclick=delc(30)>ɾ��</a></td><td><a href='#e' onclick=relist(30)>ˢ��</a> <a href='#e' onclick=renews(30,'news')>��Ϣ</a> <a href='#e' onclick=rejs(30)>JS</a> <a href='#e' onclick=tvurl(30)>����</a> <a href='#e' onclick=ttc(30)>����</a> <a href='#e' onclick=docinfo(30)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=24></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=24' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>24</td><td><input type=checkbox name=reclassid[] value=24> <a href='/Gallery/2/' target=_blank>Cartoon style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(24)>�޸�</a> <a href='#e' onclick=copyc(24)>����</a> <a href='#e' onclick=delc(24)>ɾ��</a></td><td><a href='#e' onclick=relist(24)>ˢ��</a> <a href='#e' onclick=renews(24,'news')>��Ϣ</a> <a href='#e' onclick=rejs(24)>JS</a> <a href='#e' onclick=tvurl(24)>����</a> <a href='#e' onclick=ttc(24)>����</a> <a href='#e' onclick=docinfo(24)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=25></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=25' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>25</td><td><input type=checkbox name=reclassid[] value=25> <a href='/Gallery/3/' target=_blank>Aesthetic style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(25)>�޸�</a> <a href='#e' onclick=copyc(25)>����</a> <a href='#e' onclick=delc(25)>ɾ��</a></td><td><a href='#e' onclick=relist(25)>ˢ��</a> <a href='#e' onclick=renews(25,'news')>��Ϣ</a> <a href='#e' onclick=rejs(25)>JS</a> <a href='#e' onclick=tvurl(25)>����</a> <a href='#e' onclick=ttc(25)>����</a> <a href='#e' onclick=docinfo(25)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=26></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=26' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>26</td><td><input type=checkbox name=reclassid[] value=26> <a href='/Gallery/4/' target=_blank>Illustration</a></td><td align=center>0</td><td><a href='#e' onclick=editc(26)>�޸�</a> <a href='#e' onclick=copyc(26)>����</a> <a href='#e' onclick=delc(26)>ɾ��</a></td><td><a href='#e' onclick=relist(26)>ˢ��</a> <a href='#e' onclick=renews(26,'news')>��Ϣ</a> <a href='#e' onclick=rejs(26)>JS</a> <a href='#e' onclick=tvurl(26)>����</a> <a href='#e' onclick=ttc(26)>����</a> <a href='#e' onclick=docinfo(26)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=27></td><td>&nbsp;&nbsp;&nbsp;<img src='../data/images/dir.gif'></td><td align=center>27</td><td><input type=checkbox name=reclassid[] value=27> <a href='/Gallery/5/' target=_blank>Comic</a></td><td align=center>0</td><td><a href='#e' onclick=editc(27)>�޸�</a> <a href='#e' onclick=copyc(27)>����</a> <a href='#e' onclick=delc(27)>ɾ��</a></td><td><a href='#e' onclick=relist(27)>ˢ��</a> <a href='#e' onclick=renews(27,'news')>��Ϣ</a> <a href='#e' onclick=rejs(27)>JS</a> <a href='#e' onclick=tvurl(27)>����</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=32></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=32' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>32</td><td><input type=checkbox name=reclassid[] value=32> <a href='/Gallery/5/1/' target=_blank>Yueyun</a></td><td align=center>0</td><td><a href='#e' onclick=editc(32)>�޸�</a> <a href='#e' onclick=copyc(32)>����</a> <a href='#e' onclick=delc(32)>ɾ��</a></td><td><a href='#e' onclick=relist(32)>ˢ��</a> <a href='#e' onclick=renews(32,'news')>��Ϣ</a> <a href='#e' onclick=rejs(32)>JS</a> <a href='#e' onclick=tvurl(32)>����</a> <a href='#e' onclick=ttc(32)>����</a> <a href='#e' onclick=docinfo(32)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=31></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=31' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>31</td><td><input type=checkbox name=reclassid[] value=31> <a href='/Gallery/6/' target=_blank>3D model</a></td><td align=center>0</td><td><a href='#e' onclick=editc(31)>�޸�</a> <a href='#e' onclick=copyc(31)>����</a> <a href='#e' onclick=delc(31)>ɾ��</a></td><td><a href='#e' onclick=relist(31)>ˢ��</a> <a href='#e' onclick=renews(31,'news')>��Ϣ</a> <a href='#e' onclick=rejs(31)>JS</a> <a href='#e' onclick=tvurl(31)>����</a> <a href='#e' onclick=ttc(31)>����</a> <a href='#e' onclick=docinfo(31)>�鵵</a></td></tr></tbody><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=20></td><td><a href='AddNews.php?enews=AddNews&classid=20' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>20</td><td><input type=checkbox name=reclassid[] value=20> <a href='/Offerings/' target=_blank>OFFERINGS</a></td><td align=center>0</td><td><a href='#e' onclick=editc(20)>�޸�</a> <a href='#e' onclick=copyc(20)>����</a> <a href='#e' onclick=delc(20)>ɾ��</a></td><td><a href='#e' onclick=relist(20)>ˢ��</a> <a href='#e' onclick=renews(20,'news')>��Ϣ</a> <a href='#e' onclick=rejs(20)>JS</a> <a href='#e' onclick=tvurl(20)>����</a> <a href='#e' onclick=ttc(20)>����</a> <a href='#e' onclick=docinfo(20)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=21></td><td><a href='AddNews.php?enews=AddNews&classid=21' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>21</td><td><input type=checkbox name=reclassid[] value=21> <a href='/Career/' target=_blank>CAREER</a></td><td align=center>0</td><td><a href='#e' onclick=editc(21)>�޸�</a> <a href='#e' onclick=copyc(21)>����</a> <a href='#e' onclick=delc(21)>ɾ��</a></td><td><a href='#e' onclick=relist(21)>ˢ��</a> <a href='#e' onclick=renews(21,'news')>��Ϣ</a> <a href='#e' onclick=rejs(21)>JS</a> <a href='#e' onclick=tvurl(21)>����</a> <a href='#e' onclick=ttc(21)>����</a> <a href='#e' onclick=docinfo(21)>�鵵</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=22></td><td><a href='AddNews.php?enews=AddNews&classid=22' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>22</td><td><input type=checkbox name=reclassid[] value=22> <a href='/CONTACT/' target=_blank>CONTACT US</a></td><td align=center>0</td><td><a href='#e' onclick=editc(22)>�޸�</a> <a href='#e' onclick=copyc(22)>����</a> <a href='#e' onclick=delc(22)>ɾ��</a></td><td><a href='#e' onclick=relist(22)>ˢ��</a> <a href='#e' onclick=renews(22,'news')>��Ϣ</a> <a href='#e' onclick=rejs(22)>JS</a> <a href='#e' onclick=tvurl(22)>����</a> <a href='#e' onclick=ttc(22)>����</a> <a href='#e' onclick=docinfo(22)>�鵵</a></td></tr>    <tr class="header"> 
      <td height="25" colspan="7"> <div align="left"> &nbsp;&nbsp;
          <input type="submit" name="Submit5" value="�޸���Ŀ˳��" onClick="document.editorder.enews.value='EditClassOrder';document.editorder.action='ecmsclass.php';">&nbsp;&nbsp;
          <input name="enews" type="hidden" id="enews" value="EditClassOrder">
          <input type="submit" name="Submit7" value="ˢ����Ŀҳ��" onClick="document.editorder.enews.value='GoReListHtmlMoreA';document.editorder.action='ecmschtml.php';">&nbsp;&nbsp;
          <input type="submit" name="Submit72" value="�ռ���Ŀ����ת��" onClick="document.editorder.enews.value='ChangeClassIslast';document.editorder.action='ecmsclass.php';">
        </div></td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td height="25" colspan="7"><strong>�ռ���Ŀ����ת��˵��(ֻ��ѡ�񵥸���Ŀ)��</strong><br>
        �����ѡ�����<font color="#FF0000">���ռ���Ŀ</font>����תΪ<font color="#FF0000">�ռ���Ŀ</font><font color="#666666">(����Ŀ����������Ŀ)</font><br>
        �����ѡ�����<font color="#FF0000">�ռ���Ŀ</font>����תΪ<font color="#FF0000">���ռ���Ŀ</font><font color="#666666">(���Ȱѵ�ǰ��Ŀ������ת�ƣ�����������������)<br>
        </font><strong>�޸���Ŀ˳��:˳��ֵԽСԽǰ��</strong></td>
    </tr>
    <input name="from" type="hidden" value="ListClass.php">
    <input name="gore" type="hidden" value="0">
  </form>
</table>
<br>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class="tableborder">
  <tr class="header"> 
    <td width="13%" height="25"> 
      <div align="center">����</div></td>
    <td width="39%" height="25">���õ�ַ</td>
    <td width="13%">
<div align="center">����</div></td>
    <td width="35%"> 
      <div align="center">���õ�ַ</div></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF"><div align="center">������Ϣ����</div></td>
    <td height="25" bgcolor="#FFFFFF"> <input name="textfield" type="text" value="/d/js/js/hotnews.js">
      [<a href="ecmschtml.php?enews=ReHot_NewNews">ˢ��</a>][<a href="view/js.php?js=hotnews&p=js" target="_blank">Ԥ��</a>]</td>
    <td bgcolor="#FFFFFF"><div align="center">����������</div></td>
    <td bgcolor="#FFFFFF"> <div align="left"> 
        <input name="textfield3" type="text" value="/d/js/js/search_news1.js">
        [<a href="view/js.php?js=search_news1&p=js" target="_blank">Ԥ��</a>]</div></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF"> <div align="center">������Ϣ����</div></td>
    <td height="25" bgcolor="#FFFFFF"> <input name="textfield2" type="text" value="/d/js/js/newnews.js">
      [<a href="ecmschtml.php?enews=ReHot_NewNews">ˢ��</a>][<a href="view/js.php?js=newnews&p=js" target="_blank">Ԥ��</a>]</td>
    <td bgcolor="#FFFFFF"><div align="center">����������</div></td>
    <td bgcolor="#FFFFFF"> <div align="left"> 
        <input name="textfield4" type="text" value="/d/js/js/search_news2.js">
        [<a href="view/js.php?js=search_news2&p=js" target="_blank">Ԥ��</a>]</div></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF"><div align="center">�Ƽ���Ϣ����</div></td>
    <td height="25" bgcolor="#FFFFFF"><input name="textfield22" type="text" value="/d/js/js/goodnews.js">
      [<a href="ecmschtml.php?enews=ReHot_NewNews">ˢ��</a>][<a href="view/js.php?js=goodnews&p=js" target="_blank">Ԥ��</a>]</td>
    <td bgcolor="#FFFFFF"><div align="center">����ҳ���ַ</div></td>
    <td bgcolor="#FFFFFF"> <div align="left"> 
        <input name="textfield5" type="text" value="/search">
        [<a href="../../search" target="_blank">Ԥ��</a>]</div></td>
  </tr>
  <tr> 
    <td height="24" bgcolor="#FFFFFF"> 
      <div align="center">��������ַ</div></td>
    <td height="24" bgcolor="#FFFFFF">
<input name="textfield52" type="text" value="/e/member/cp">
      [<a href="../member/cp" target="_blank">Ԥ��</a>]</td>
    <td bgcolor="#FFFFFF"><div align="center"></div></td>
    <td bgcolor="#FFFFFF"><div align="center"></div></td>
  </tr>
  <tr class="header"> 
    <td height="25" colspan="4">js���÷�ʽ��&lt;script src=js��ַ&gt;&lt;/script&gt;</td>
  </tr>
</table>
</body>
</html>
