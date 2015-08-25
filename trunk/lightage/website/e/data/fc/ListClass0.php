<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?><!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312">
<title>管理栏目</title>
<SCRIPT lanuage="JScript">
function turnit(ss)
{
 if (ss.style.display=="") 
  ss.style.display="none";
 else
  ss.style.display=""; 
}
var newWindow = null

//调用地址
function tvurl(classid){
	window.open('view/ClassUrl.php?classid='+classid,'','width=500,height=250');
}
//刷新栏目
function relist(classid){
	self.location.href='enews.php?enews=ReListHtml&from=ListClass.php&classid='+classid;
}
//刷新信息
function renews(classid,tbname){
	window.open('ReHtml/DoRehtml.php?enews=ReNewsHtml&from=ListClass.php&classid='+classid+'&tbname[]='+tbname);
}
//归档
function docinfo(classid){
	if(confirm('确认归档?'))
	{
		self.location.href='ecmsinfo.php?enews=InfoToDoc&ecmsdoc=1&docfrom=ListClass.php&classid='+classid;
	}
}
//刷新JS
function rejs(classid){
	self.location.href='ecmschtml.php?enews=ReSingleJs&doing=0&classid='+classid;
}
//复制
function copyc(classid){
	self.location.href='AddClass.php?classid='+classid+'&enews=AddClass&docopy=1';
}
//修改
function editc(classid){
	self.location.href='AddClass.php?classid='+classid+'&enews=EditClass';
}
//删除
function delc(classid){
	if(confirm('确认要删除此栏目，将删除所属子栏目及信息'))
	{
		self.location.href='ecmsclass.php?classid='+classid+'&enews=DelClass';
	}
}
//标题分类
function ttc(classid){
	window.open('ClassInfoType.php?classid='+classid);
}
</SCRIPT>
</head>
<body>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1">
  <tr> 
    <td width="18%">位置: <a href="ListClass.php">管理栏目</a></td>
    <td width="82%"> <div align="right" class="emenubutton">
        <input type="button" name="Submit6" value="增加栏目" onclick="self.location.href='AddClass.php?enews=AddClass'">
        <input type="button" name="Submit" value="刷新首页" onclick="self.location.href='ecmschtml.php?enews=ReIndex'">
        <input type="button" name="Submit2" value="刷新所有栏目页" onclick="window.open('ecmschtml.php?enews=ReListHtml_all&from=ListClass.php','','');">
        <input type="button" name="Submit3" value="刷新所有信息页面" onclick="window.open('ReHtml/DoRehtml.php?enews=ReNewsHtml&start=0&from=ListClass.php','','');">
        <input type="button" name="Submit4" value="刷新所有JS调用" onclick="window.open('ecmschtml.php?enews=ReAllNewsJs&from=ListClass.php','','');">
      </div></td>
  </tr>
</table>
<table width="100%" border="0" cellpadding="3" cellspacing="1" class="tableborder">
  <form name=editorder method=post action=ecmsclass.php onsubmit="return confirm('确认要操作?');">
    <tr class="header" height="25"> 
      <td width="5%" align="center">顺序</td>
      <td width="7%" align="center"><a href='ListClass.php?doopen=1&open=1' title='收缩'><img src='../data/images/displayadd.gif' width='15' height='15' border='0'></a></td>
      <td width="6%" align="center">ID</td>
      <td width="36%">栏目名</td>
      <td width="6%" align="center">访问</td>
      <td width="14%">栏目管理</td>
      <td width="29%">操作</td>
    </tr>
    <tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=1></td><td><a href='AddNews.php?enews=AddNews&classid=1' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>1</td><td><input type=checkbox name=reclassid[] value=1> <a href='/' target=_blank>网站首页</a></td><td align=center>0</td><td><a href='#e' onclick=editc(1)>修改</a> <a href='#e' onclick=copyc(1)>复制</a> <a href='#e' onclick=delc(1)>删除</a></td><td><a href='#e' onclick=relist(1)>刷新</a> <a href='#e' onclick=renews(1,'news')>信息</a> <a href='#e' onclick=rejs(1)>JS</a> <a href='#e' onclick=tvurl(1)>调用</a> <a href='#e' onclick=ttc(1)>分类</a> <a href='#e' onclick=docinfo(1)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=2></td><td><a href='AddNews.php?enews=AddNews&classid=2' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>2</td><td><input type=checkbox name=reclassid[] value=2> <a href='/gywm/' target=_blank>关于我们</a></td><td align=center>0</td><td><a href='#e' onclick=editc(2)>修改</a> <a href='#e' onclick=copyc(2)>复制</a> <a href='#e' onclick=delc(2)>删除</a></td><td><a href='#e' onclick=relist(2)>刷新</a> <a href='#e' onclick=renews(2,'news')>信息</a> <a href='#e' onclick=rejs(2)>JS</a> <a href='#e' onclick=tvurl(2)>调用</a> <a href='#e' onclick=ttc(2)>分类</a> <a href='#e' onclick=docinfo(2)>归档</a></td></tr><tr bgcolor='#DBEAF5' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=3></td><td onMouseUp='turnit(classdiv3);' style='CURSOR:hand'><img src='../data/images/dir.gif'></td><td align=center>3</td><td><input type=checkbox name=reclassid[] value=3> <a href='/zpxs/' target=_blank>作品欣赏</a></td><td align=center>0</td><td><a href='#e' onclick=editc(3)>修改</a> <a href='#e' onclick=copyc(3)>复制</a> <a href='#e' onclick=delc(3)>删除</a></td><td><a href='#e' onclick=relist(3)>刷新</a> <a href='#e' onclick=renews(3,'news')>信息</a> <a href='#e' onclick=rejs(3)>JS</a> <a href='#e' onclick=tvurl(3)>调用</a></td></tr><tbody id='classdiv3'><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=7></td><td>&nbsp;&nbsp;&nbsp;<img src='../data/images/dir.gif'></td><td align=center>7</td><td><input type=checkbox name=reclassid[] value=7> <a href='/zpxs/1/' target=_blank>写实风格</a></td><td align=center>0</td><td><a href='#e' onclick=editc(7)>修改</a> <a href='#e' onclick=copyc(7)>复制</a> <a href='#e' onclick=delc(7)>删除</a></td><td><a href='#e' onclick=relist(7)>刷新</a> <a href='#e' onclick=renews(7,'news')>信息</a> <a href='#e' onclick=rejs(7)>JS</a> <a href='#e' onclick=tvurl(7)>调用</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=14></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=14' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>14</td><td><input type=checkbox name=reclassid[] value=14> <a href='/zpxs/1/1/' target=_blank>中国风</a></td><td align=center>0</td><td><a href='#e' onclick=editc(14)>修改</a> <a href='#e' onclick=copyc(14)>复制</a> <a href='#e' onclick=delc(14)>删除</a></td><td><a href='#e' onclick=relist(14)>刷新</a> <a href='#e' onclick=renews(14,'news')>信息</a> <a href='#e' onclick=rejs(14)>JS</a> <a href='#e' onclick=tvurl(14)>调用</a> <a href='#e' onclick=ttc(14)>分类</a> <a href='#e' onclick=docinfo(14)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=15></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=15' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>15</td><td><input type=checkbox name=reclassid[] value=15> <a href='/zpxs/1/2/' target=_blank>欧美风</a></td><td align=center>0</td><td><a href='#e' onclick=editc(15)>修改</a> <a href='#e' onclick=copyc(15)>复制</a> <a href='#e' onclick=delc(15)>删除</a></td><td><a href='#e' onclick=relist(15)>刷新</a> <a href='#e' onclick=renews(15,'news')>信息</a> <a href='#e' onclick=rejs(15)>JS</a> <a href='#e' onclick=tvurl(15)>调用</a> <a href='#e' onclick=ttc(15)>分类</a> <a href='#e' onclick=docinfo(15)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=16></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=16' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>16</td><td><input type=checkbox name=reclassid[] value=16> <a href='/zpxs/1/3/' target=_blank>场景</a></td><td align=center>0</td><td><a href='#e' onclick=editc(16)>修改</a> <a href='#e' onclick=copyc(16)>复制</a> <a href='#e' onclick=delc(16)>删除</a></td><td><a href='#e' onclick=relist(16)>刷新</a> <a href='#e' onclick=renews(16,'news')>信息</a> <a href='#e' onclick=rejs(16)>JS</a> <a href='#e' onclick=tvurl(16)>调用</a> <a href='#e' onclick=ttc(16)>分类</a> <a href='#e' onclick=docinfo(16)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=8></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=8' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>8</td><td><input type=checkbox name=reclassid[] value=8> <a href='/zpxs/2/' target=_blank>卡通风格</a></td><td align=center>0</td><td><a href='#e' onclick=editc(8)>修改</a> <a href='#e' onclick=copyc(8)>复制</a> <a href='#e' onclick=delc(8)>删除</a></td><td><a href='#e' onclick=relist(8)>刷新</a> <a href='#e' onclick=renews(8,'news')>信息</a> <a href='#e' onclick=rejs(8)>JS</a> <a href='#e' onclick=tvurl(8)>调用</a> <a href='#e' onclick=ttc(8)>分类</a> <a href='#e' onclick=docinfo(8)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=9></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=9' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>9</td><td><input type=checkbox name=reclassid[] value=9> <a href='/zpxs/3/' target=_blank>唯美风格</a></td><td align=center>0</td><td><a href='#e' onclick=editc(9)>修改</a> <a href='#e' onclick=copyc(9)>复制</a> <a href='#e' onclick=delc(9)>删除</a></td><td><a href='#e' onclick=relist(9)>刷新</a> <a href='#e' onclick=renews(9,'news')>信息</a> <a href='#e' onclick=rejs(9)>JS</a> <a href='#e' onclick=tvurl(9)>调用</a> <a href='#e' onclick=ttc(9)>分类</a> <a href='#e' onclick=docinfo(9)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=10></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=10' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>10</td><td><input type=checkbox name=reclassid[] value=10> <a href='/zpxs/4/' target=_blank>插画</a></td><td align=center>0</td><td><a href='#e' onclick=editc(10)>修改</a> <a href='#e' onclick=copyc(10)>复制</a> <a href='#e' onclick=delc(10)>删除</a></td><td><a href='#e' onclick=relist(10)>刷新</a> <a href='#e' onclick=renews(10,'news')>信息</a> <a href='#e' onclick=rejs(10)>JS</a> <a href='#e' onclick=tvurl(10)>调用</a> <a href='#e' onclick=ttc(10)>分类</a> <a href='#e' onclick=docinfo(10)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=11></td><td>&nbsp;&nbsp;&nbsp;<img src='../data/images/dir.gif'></td><td align=center>11</td><td><input type=checkbox name=reclassid[] value=11> <a href='/zpxs/5/' target=_blank>漫画</a></td><td align=center>0</td><td><a href='#e' onclick=editc(11)>修改</a> <a href='#e' onclick=copyc(11)>复制</a> <a href='#e' onclick=delc(11)>删除</a></td><td><a href='#e' onclick=relist(11)>刷新</a> <a href='#e' onclick=renews(11,'news')>信息</a> <a href='#e' onclick=rejs(11)>JS</a> <a href='#e' onclick=tvurl(11)>调用</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=12></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=12' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>12</td><td><input type=checkbox name=reclassid[] value=12> <a href='/zpxs/5/1/' target=_blank>小将岳云</a></td><td align=center>0</td><td><a href='#e' onclick=editc(12)>修改</a> <a href='#e' onclick=copyc(12)>复制</a> <a href='#e' onclick=delc(12)>删除</a></td><td><a href='#e' onclick=relist(12)>刷新</a> <a href='#e' onclick=renews(12,'news')>信息</a> <a href='#e' onclick=rejs(12)>JS</a> <a href='#e' onclick=tvurl(12)>调用</a> <a href='#e' onclick=ttc(12)>分类</a> <a href='#e' onclick=docinfo(12)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=13></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=13' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>13</td><td><input type=checkbox name=reclassid[] value=13> <a href='/zpxs/6/' target=_blank>3D模型</a></td><td align=center>0</td><td><a href='#e' onclick=editc(13)>修改</a> <a href='#e' onclick=copyc(13)>复制</a> <a href='#e' onclick=delc(13)>删除</a></td><td><a href='#e' onclick=relist(13)>刷新</a> <a href='#e' onclick=renews(13,'news')>信息</a> <a href='#e' onclick=rejs(13)>JS</a> <a href='#e' onclick=tvurl(13)>调用</a> <a href='#e' onclick=ttc(13)>分类</a> <a href='#e' onclick=docinfo(13)>归档</a></td></tr></tbody><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=4></td><td><a href='AddNews.php?enews=AddNews&classid=4' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>4</td><td><input type=checkbox name=reclassid[] value=4> <a href='/ywfw/' target=_blank>业务范围</a></td><td align=center>0</td><td><a href='#e' onclick=editc(4)>修改</a> <a href='#e' onclick=copyc(4)>复制</a> <a href='#e' onclick=delc(4)>删除</a></td><td><a href='#e' onclick=relist(4)>刷新</a> <a href='#e' onclick=renews(4,'news')>信息</a> <a href='#e' onclick=rejs(4)>JS</a> <a href='#e' onclick=tvurl(4)>调用</a> <a href='#e' onclick=ttc(4)>分类</a> <a href='#e' onclick=docinfo(4)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=5></td><td><a href='AddNews.php?enews=AddNews&classid=5' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>5</td><td><input type=checkbox name=reclassid[] value=5> <a href='/zprc/' target=_blank>招聘人才</a></td><td align=center>0</td><td><a href='#e' onclick=editc(5)>修改</a> <a href='#e' onclick=copyc(5)>复制</a> <a href='#e' onclick=delc(5)>删除</a></td><td><a href='#e' onclick=relist(5)>刷新</a> <a href='#e' onclick=renews(5,'news')>信息</a> <a href='#e' onclick=rejs(5)>JS</a> <a href='#e' onclick=tvurl(5)>调用</a> <a href='#e' onclick=ttc(5)>分类</a> <a href='#e' onclick=docinfo(5)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=6></td><td><a href='AddNews.php?enews=AddNews&classid=6' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>6</td><td><input type=checkbox name=reclassid[] value=6> <a href='/lxwm/' target=_blank>联系我们</a></td><td align=center>0</td><td><a href='#e' onclick=editc(6)>修改</a> <a href='#e' onclick=copyc(6)>复制</a> <a href='#e' onclick=delc(6)>删除</a></td><td><a href='#e' onclick=relist(6)>刷新</a> <a href='#e' onclick=renews(6,'news')>信息</a> <a href='#e' onclick=rejs(6)>JS</a> <a href='#e' onclick=tvurl(6)>调用</a> <a href='#e' onclick=ttc(6)>分类</a> <a href='#e' onclick=docinfo(6)>归档</a></td></tr><tr bgcolor='#DBEAF5' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=17></td><td onMouseUp='turnit(classdiv17);' style='CURSOR:hand'><img src='../data/images/dir.gif'></td><td align=center>17</td><td><input type=checkbox name=reclassid[] value=17> <a href='/home/' target=_blank>HOME</a></td><td align=center>0</td><td><a href='#e' onclick=editc(17)>修改</a> <a href='#e' onclick=copyc(17)>复制</a> <a href='#e' onclick=delc(17)>删除</a></td><td><a href='#e' onclick=relist(17)>刷新</a> <a href='#e' onclick=renews(17,'news')>信息</a> <a href='#e' onclick=rejs(17)>JS</a> <a href='#e' onclick=tvurl(17)>调用</a></td></tr><tbody id='classdiv17'></tbody><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=18></td><td><a href='AddNews.php?enews=AddNews&classid=18' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>18</td><td><input type=checkbox name=reclassid[] value=18> <a href='/about/' target=_blank>ABOUT US</a></td><td align=center>0</td><td><a href='#e' onclick=editc(18)>修改</a> <a href='#e' onclick=copyc(18)>复制</a> <a href='#e' onclick=delc(18)>删除</a></td><td><a href='#e' onclick=relist(18)>刷新</a> <a href='#e' onclick=renews(18,'news')>信息</a> <a href='#e' onclick=rejs(18)>JS</a> <a href='#e' onclick=tvurl(18)>调用</a> <a href='#e' onclick=ttc(18)>分类</a> <a href='#e' onclick=docinfo(18)>归档</a></td></tr><tr bgcolor='#DBEAF5' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=19></td><td onMouseUp='turnit(classdiv19);' style='CURSOR:hand'><img src='../data/images/dir.gif'></td><td align=center>19</td><td><input type=checkbox name=reclassid[] value=19> <a href='/Gallery/' target=_blank>GALLERY</a></td><td align=center>0</td><td><a href='#e' onclick=editc(19)>修改</a> <a href='#e' onclick=copyc(19)>复制</a> <a href='#e' onclick=delc(19)>删除</a></td><td><a href='#e' onclick=relist(19)>刷新</a> <a href='#e' onclick=renews(19,'news')>信息</a> <a href='#e' onclick=rejs(19)>JS</a> <a href='#e' onclick=tvurl(19)>调用</a></td></tr><tbody id='classdiv19'><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=23></td><td>&nbsp;&nbsp;&nbsp;<img src='../data/images/dir.gif'></td><td align=center>23</td><td><input type=checkbox name=reclassid[] value=23> <a href='/Gallery/1/' target=_blank>Realist Style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(23)>修改</a> <a href='#e' onclick=copyc(23)>复制</a> <a href='#e' onclick=delc(23)>删除</a></td><td><a href='#e' onclick=relist(23)>刷新</a> <a href='#e' onclick=renews(23,'news')>信息</a> <a href='#e' onclick=rejs(23)>JS</a> <a href='#e' onclick=tvurl(23)>调用</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=28></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=28' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>28</td><td><input type=checkbox name=reclassid[] value=28> <a href='/Gallery/1/1/' target=_blank>Chinese Style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(28)>修改</a> <a href='#e' onclick=copyc(28)>复制</a> <a href='#e' onclick=delc(28)>删除</a></td><td><a href='#e' onclick=relist(28)>刷新</a> <a href='#e' onclick=renews(28,'news')>信息</a> <a href='#e' onclick=rejs(28)>JS</a> <a href='#e' onclick=tvurl(28)>调用</a> <a href='#e' onclick=ttc(28)>分类</a> <a href='#e' onclick=docinfo(28)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=29></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=29' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>29</td><td><input type=checkbox name=reclassid[] value=29> <a href='/Gallery/1/2/' target=_blank>Western Style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(29)>修改</a> <a href='#e' onclick=copyc(29)>复制</a> <a href='#e' onclick=delc(29)>删除</a></td><td><a href='#e' onclick=relist(29)>刷新</a> <a href='#e' onclick=renews(29,'news')>信息</a> <a href='#e' onclick=rejs(29)>JS</a> <a href='#e' onclick=tvurl(29)>调用</a> <a href='#e' onclick=ttc(29)>分类</a> <a href='#e' onclick=docinfo(29)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=30></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=30' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>30</td><td><input type=checkbox name=reclassid[] value=30> <a href='/Gallery/1/3/' target=_blank>Scene</a></td><td align=center>0</td><td><a href='#e' onclick=editc(30)>修改</a> <a href='#e' onclick=copyc(30)>复制</a> <a href='#e' onclick=delc(30)>删除</a></td><td><a href='#e' onclick=relist(30)>刷新</a> <a href='#e' onclick=renews(30,'news')>信息</a> <a href='#e' onclick=rejs(30)>JS</a> <a href='#e' onclick=tvurl(30)>调用</a> <a href='#e' onclick=ttc(30)>分类</a> <a href='#e' onclick=docinfo(30)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=24></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=24' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>24</td><td><input type=checkbox name=reclassid[] value=24> <a href='/Gallery/2/' target=_blank>Cartoon style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(24)>修改</a> <a href='#e' onclick=copyc(24)>复制</a> <a href='#e' onclick=delc(24)>删除</a></td><td><a href='#e' onclick=relist(24)>刷新</a> <a href='#e' onclick=renews(24,'news')>信息</a> <a href='#e' onclick=rejs(24)>JS</a> <a href='#e' onclick=tvurl(24)>调用</a> <a href='#e' onclick=ttc(24)>分类</a> <a href='#e' onclick=docinfo(24)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=25></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=25' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>25</td><td><input type=checkbox name=reclassid[] value=25> <a href='/Gallery/3/' target=_blank>Aesthetic style</a></td><td align=center>0</td><td><a href='#e' onclick=editc(25)>修改</a> <a href='#e' onclick=copyc(25)>复制</a> <a href='#e' onclick=delc(25)>删除</a></td><td><a href='#e' onclick=relist(25)>刷新</a> <a href='#e' onclick=renews(25,'news')>信息</a> <a href='#e' onclick=rejs(25)>JS</a> <a href='#e' onclick=tvurl(25)>调用</a> <a href='#e' onclick=ttc(25)>分类</a> <a href='#e' onclick=docinfo(25)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=26></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=26' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>26</td><td><input type=checkbox name=reclassid[] value=26> <a href='/Gallery/4/' target=_blank>Illustration</a></td><td align=center>0</td><td><a href='#e' onclick=editc(26)>修改</a> <a href='#e' onclick=copyc(26)>复制</a> <a href='#e' onclick=delc(26)>删除</a></td><td><a href='#e' onclick=relist(26)>刷新</a> <a href='#e' onclick=renews(26,'news')>信息</a> <a href='#e' onclick=rejs(26)>JS</a> <a href='#e' onclick=tvurl(26)>调用</a> <a href='#e' onclick=ttc(26)>分类</a> <a href='#e' onclick=docinfo(26)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=27></td><td>&nbsp;&nbsp;&nbsp;<img src='../data/images/dir.gif'></td><td align=center>27</td><td><input type=checkbox name=reclassid[] value=27> <a href='/Gallery/5/' target=_blank>Comic</a></td><td align=center>0</td><td><a href='#e' onclick=editc(27)>修改</a> <a href='#e' onclick=copyc(27)>复制</a> <a href='#e' onclick=delc(27)>删除</a></td><td><a href='#e' onclick=relist(27)>刷新</a> <a href='#e' onclick=renews(27,'news')>信息</a> <a href='#e' onclick=rejs(27)>JS</a> <a href='#e' onclick=tvurl(27)>调用</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=32></td><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=32' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>32</td><td><input type=checkbox name=reclassid[] value=32> <a href='/Gallery/5/1/' target=_blank>Yueyun</a></td><td align=center>0</td><td><a href='#e' onclick=editc(32)>修改</a> <a href='#e' onclick=copyc(32)>复制</a> <a href='#e' onclick=delc(32)>删除</a></td><td><a href='#e' onclick=relist(32)>刷新</a> <a href='#e' onclick=renews(32,'news')>信息</a> <a href='#e' onclick=rejs(32)>JS</a> <a href='#e' onclick=tvurl(32)>调用</a> <a href='#e' onclick=ttc(32)>分类</a> <a href='#e' onclick=docinfo(32)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=31></td><td>&nbsp;&nbsp;&nbsp;<a href='AddNews.php?enews=AddNews&classid=31' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>31</td><td><input type=checkbox name=reclassid[] value=31> <a href='/Gallery/6/' target=_blank>3D model</a></td><td align=center>0</td><td><a href='#e' onclick=editc(31)>修改</a> <a href='#e' onclick=copyc(31)>复制</a> <a href='#e' onclick=delc(31)>删除</a></td><td><a href='#e' onclick=relist(31)>刷新</a> <a href='#e' onclick=renews(31,'news')>信息</a> <a href='#e' onclick=rejs(31)>JS</a> <a href='#e' onclick=tvurl(31)>调用</a> <a href='#e' onclick=ttc(31)>分类</a> <a href='#e' onclick=docinfo(31)>归档</a></td></tr></tbody><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=20></td><td><a href='AddNews.php?enews=AddNews&classid=20' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>20</td><td><input type=checkbox name=reclassid[] value=20> <a href='/Offerings/' target=_blank>OFFERINGS</a></td><td align=center>0</td><td><a href='#e' onclick=editc(20)>修改</a> <a href='#e' onclick=copyc(20)>复制</a> <a href='#e' onclick=delc(20)>删除</a></td><td><a href='#e' onclick=relist(20)>刷新</a> <a href='#e' onclick=renews(20,'news')>信息</a> <a href='#e' onclick=rejs(20)>JS</a> <a href='#e' onclick=tvurl(20)>调用</a> <a href='#e' onclick=ttc(20)>分类</a> <a href='#e' onclick=docinfo(20)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=21></td><td><a href='AddNews.php?enews=AddNews&classid=21' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>21</td><td><input type=checkbox name=reclassid[] value=21> <a href='/Career/' target=_blank>CAREER</a></td><td align=center>0</td><td><a href='#e' onclick=editc(21)>修改</a> <a href='#e' onclick=copyc(21)>复制</a> <a href='#e' onclick=delc(21)>删除</a></td><td><a href='#e' onclick=relist(21)>刷新</a> <a href='#e' onclick=renews(21,'news')>信息</a> <a href='#e' onclick=rejs(21)>JS</a> <a href='#e' onclick=tvurl(21)>调用</a> <a href='#e' onclick=ttc(21)>分类</a> <a href='#e' onclick=docinfo(21)>归档</a></td></tr><tr bgcolor='#ffffff' height=25><td><input type=text name=myorder[] value=0 size=2><input type=hidden name=classid[] value=22></td><td><a href='AddNews.php?enews=AddNews&classid=22' target=_blank><img src='../data/images/txt.gif' border=0></a></td><td align=center>22</td><td><input type=checkbox name=reclassid[] value=22> <a href='/CONTACT/' target=_blank>CONTACT US</a></td><td align=center>0</td><td><a href='#e' onclick=editc(22)>修改</a> <a href='#e' onclick=copyc(22)>复制</a> <a href='#e' onclick=delc(22)>删除</a></td><td><a href='#e' onclick=relist(22)>刷新</a> <a href='#e' onclick=renews(22,'news')>信息</a> <a href='#e' onclick=rejs(22)>JS</a> <a href='#e' onclick=tvurl(22)>调用</a> <a href='#e' onclick=ttc(22)>分类</a> <a href='#e' onclick=docinfo(22)>归档</a></td></tr>    <tr class="header"> 
      <td height="25" colspan="7"> <div align="left"> &nbsp;&nbsp;
          <input type="submit" name="Submit5" value="修改栏目顺序" onClick="document.editorder.enews.value='EditClassOrder';document.editorder.action='ecmsclass.php';">&nbsp;&nbsp;
          <input name="enews" type="hidden" id="enews" value="EditClassOrder">
          <input type="submit" name="Submit7" value="刷新栏目页面" onClick="document.editorder.enews.value='GoReListHtmlMoreA';document.editorder.action='ecmschtml.php';">&nbsp;&nbsp;
          <input type="submit" name="Submit72" value="终极栏目属性转换" onClick="document.editorder.enews.value='ChangeClassIslast';document.editorder.action='ecmsclass.php';">
        </div></td>
    </tr>
    <tr bgcolor="#FFFFFF"> 
      <td height="25" colspan="7"><strong>终极栏目属性转换说明(只能选择单个栏目)：</strong><br>
        如果你选择的是<font color="#FF0000">非终极栏目</font>，则转为<font color="#FF0000">终极栏目</font><font color="#666666">(此栏目不能有子栏目)</font><br>
        如果你选择的是<font color="#FF0000">终极栏目</font>，则转为<font color="#FF0000">非终极栏目</font><font color="#666666">(请先把当前栏目的数据转移，否则会出现冗余数据)<br>
        </font><strong>修改栏目顺序:顺序值越小越前面</strong></td>
    </tr>
    <input name="from" type="hidden" value="ListClass.php">
    <input name="gore" type="hidden" value="0">
  </form>
</table>
<br>
<table width="100%" border="0" align="center" cellpadding="3" cellspacing="1" class="tableborder">
  <tr class="header"> 
    <td width="13%" height="25"> 
      <div align="center">名称</div></td>
    <td width="39%" height="25">调用地址</td>
    <td width="13%">
<div align="center">名称</div></td>
    <td width="35%"> 
      <div align="center">调用地址</div></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF"><div align="center">热门信息调用</div></td>
    <td height="25" bgcolor="#FFFFFF"> <input name="textfield" type="text" value="/d/js/js/hotnews.js">
      [<a href="ecmschtml.php?enews=ReHot_NewNews">刷新</a>][<a href="view/js.php?js=hotnews&p=js" target="_blank">预览</a>]</td>
    <td bgcolor="#FFFFFF"><div align="center">横向搜索表单</div></td>
    <td bgcolor="#FFFFFF"> <div align="left"> 
        <input name="textfield3" type="text" value="/d/js/js/search_news1.js">
        [<a href="view/js.php?js=search_news1&p=js" target="_blank">预览</a>]</div></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF"> <div align="center">最新信息调用</div></td>
    <td height="25" bgcolor="#FFFFFF"> <input name="textfield2" type="text" value="/d/js/js/newnews.js">
      [<a href="ecmschtml.php?enews=ReHot_NewNews">刷新</a>][<a href="view/js.php?js=newnews&p=js" target="_blank">预览</a>]</td>
    <td bgcolor="#FFFFFF"><div align="center">纵向搜索表单</div></td>
    <td bgcolor="#FFFFFF"> <div align="left"> 
        <input name="textfield4" type="text" value="/d/js/js/search_news2.js">
        [<a href="view/js.php?js=search_news2&p=js" target="_blank">预览</a>]</div></td>
  </tr>
  <tr> 
    <td height="25" bgcolor="#FFFFFF"><div align="center">推荐信息调用</div></td>
    <td height="25" bgcolor="#FFFFFF"><input name="textfield22" type="text" value="/d/js/js/goodnews.js">
      [<a href="ecmschtml.php?enews=ReHot_NewNews">刷新</a>][<a href="view/js.php?js=goodnews&p=js" target="_blank">预览</a>]</td>
    <td bgcolor="#FFFFFF"><div align="center">搜索页面地址</div></td>
    <td bgcolor="#FFFFFF"> <div align="left"> 
        <input name="textfield5" type="text" value="/search">
        [<a href="../../search" target="_blank">预览</a>]</div></td>
  </tr>
  <tr> 
    <td height="24" bgcolor="#FFFFFF"> 
      <div align="center">控制面板地址</div></td>
    <td height="24" bgcolor="#FFFFFF">
<input name="textfield52" type="text" value="/e/member/cp">
      [<a href="../member/cp" target="_blank">预览</a>]</td>
    <td bgcolor="#FFFFFF"><div align="center"></div></td>
    <td bgcolor="#FFFFFF"><div align="center"></div></td>
  </tr>
  <tr class="header"> 
    <td height="25" colspan="4">js调用方式：&lt;script src=js地址&gt;&lt;/script&gt;</td>
  </tr>
</table>
</body>
</html>
