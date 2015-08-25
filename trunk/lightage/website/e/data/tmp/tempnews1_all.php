<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>[!--pagetitle--] - Powered by EmpireCMS</title>
<meta name="keywords" content="[!--pagekey--]" />
<meta name="description" content="[!--pagedes--]" />
<link href="[!--news.url--]skin/default/css/style.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="[!--news.url--]skin/default/js/tabs.js"></script>
<script type="text/javascript" src="[!--news.url--]e/data/js/ajax.js"></script>
</head>
<body class="showpage news">
<table align="center" width="980" border="0" cellspacing="0" cellpadding="0" background="/images/tbbg.jpg">
  <tr>
    <td width="326" height="100">&nbsp;</td>
    <td width="654" valign="top" style="font-size:12px" >
	<div class="aa" align="right" style="padding:10px 60px 0 0"><a href="/" target="_self">中文版</a>&nbsp;&nbsp;|&nbsp;&nbsp;<a href="/home" target="_self">English</a></div>
	
	<ul id="MenuBar1" class="MenuBarHorizontal" style="padding-top:25px">
          <li class="menu">
        	<div class="cn"><a  href="/">网站首页</a></div>
            <div class="en">HOME</div>
          </li>
          <li class="menu">
          	<div class="cn"><a class="MenuBarItemSubmenu" href="/gywm">关于我们</a></div>
            <div class="en">ABOUT US</div>
          </li >
          <li class="menu">
          	 <div class="cn"><a class="MenuBarItemSubmenu" href="/zpxs">作品欣赏</a></div>
             <div class="en">OUR WORKS</div>
          </li>
          <li class="menu">
          	<div class="cn"><a  class="MenuBarItemSubmenu" href="/ywfw">业务范围</a></div>
            <div class="en">SCOPE</div>
         </li>
          <li class="menu">
          	<div class="cn"><a  href="/zprc" class="MenuBarItemSubmenu">招聘人才</a></div>
            <div class="en">RECRUITMENT</div>
          </li>
            <li class="menu">
            	<div class="cn"><a  href="/lxwm">联系我们</a></div>
                <div class="en">CONTACT US</div>
           </li>
      </ul>
	</td>
  </tr>
  <tr>
    <td colspan="2" align="center" bgcolor="#12141B"><? @sys_FlashPixpic(1,6,980,300,0,0,0,2,0,0);?></td>
  </tr>
</table>
<table width="100%" border="0" cellspacing="10" cellpadding="0">
<tr valign="top">
<td class="main"><table width="100%" border="0" cellspacing="0" cellpadding="0" class="position">
<tr>
<td>您当前的位置：[!--newsnav--]</td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="box">
<tr>
<td><table width="100%" border="0" cellpadding="0" cellspacing="0" class="title_info">
<tr>
<td><h1>[!--title--]</h1></td>
</tr>
<tr>
<td class="info_text">时间：[!--newstime--]&nbsp;&nbsp;来源：[!--befrom--]&nbsp;&nbsp;作者：[!--writer--]</td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
<tr>
<td id="text">[!--newstext--]
<p align="center" class="pageLink">[!--page.url--]</p></td>
</tr>
</table>
<table border="0" align="center" cellpadding="0" cellspacing="8">
<tr>
<td><table border="0" align="center" cellpadding="0" cellspacing="0" class="digg">
<tr>
<td class="diggnum" id="diggnum"><strong><script type="text/javascript" src="[!--news.url--]e/public/ViewClick/?classid=[!--classid--]&id=[!--id--]&down=5"></script></strong></td>
</tr>
<tr>
<td class="diggit"><a href="JavaScript:makeRequest('[!--news.url--]e/public/digg/?classid=[!--classid--]&id=[!--id--]&dotop=1&doajax=1&ajaxarea=diggnum','EchoReturnedText','GET','');">来顶一下</a></td>
</tr>
</table></td>
<td><table border="0" align="center" cellpadding="0" cellspacing="0" class="digg">
<tr>
<td valign="middle" class="diggnum"><strong><a href="[!--news.url--]"><img src="[!--news.url--]skin/default/images/back.gif" alt="返回首页" width="12" height="13" border="0" align="absmiddle" /></a></strong></td>
</tr>
<tr>
<td class="diggit"><a href="[!--news.url--]">返回首页</a></td>
</tr>
</table></td>
</tr>
</table>
          </td>
</tr>
</table>
<script>
		  function CheckPl(obj)
		  {
		  if(obj.saytext.value=="")
		  {
		  alert("您没什么话要说吗？");
		  obj.saytext.focus();
		  return false;
		  }
		  return true;
		  }
		  </script><form action="[!--news.url--]e/enews/index.php" method="post" name="saypl" id="saypl" onsubmit="return CheckPl(document.saypl)">
<table width="100%" border="0" cellpadding="0" cellspacing="0" id="plpost">

<tr>
<td><table width="100%" border="0" cellpadding="0" cellspacing="0" class="title">
<tr>
<td><strong>发表评论</strong></td>
<td align="right"><a href="[!--news.url--]e/pl/?classid=[!--classid--]&amp;id=[!--id--]">共有<span><script type="text/javascript" src="[!--news.url--]e/public/ViewClick/?classid=[!--classid--]&id=[!--id--]&down=2"></script></span>条评论</a></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="10" cellpadding="0">
<tr>
<td><table width="100%" border="0" cellpadding="0" cellspacing="2">
<tr>
<td width="56%" align="left">用户名:
<input name="username" type="text" class="inputText" id="username" value="" size="16" /></td>
<td width="44%" align="left">密码:
<input name="password" type="password" class="inputText" id="password" value="" size="16" /></td>
</tr>
<tr>
<td align="left">验证码:
<input name="key" type="text" class="inputText" size="10" />
<img src="[!--news.url--]e/ShowKey/?v=pl" align="absmiddle" /> </td>
<td align="left"><input name="nomember" type="checkbox" id="nomember" value="1" checked="checked" />
匿名发表</td>
</tr>
</table>
<textarea name="saytext" rows="6" id="saytext"></textarea><input name="imageField" type="image" src="[!--news.url--]e/data/images/postpl.gif"/>
<input name="id" type="hidden" id="id" value="[!--id--]" />
<input name="classid" type="hidden" id="classid" value="[!--classid--]" />
<input name="enews" type="hidden" id="enews" value="AddPl" />
<input name="repid" type="hidden" id="repid" value="0" />
<input type="hidden" name="ecmsfrom" value="[!--titleurl--]"></td>
</tr>
</table>
</td>
</tr>
</table></form>
</td>
<td class="sider"><table width="100%" border="0" cellspacing="0" cellpadding="0" class="title">
<tr>
<td><strong>推荐资讯</strong></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="8" cellpadding="0" class="box">
<tr>
<td><? @sys_GetClassNewsPic('news',2,4,128,90,1,20,20);?>
</td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="title margin_top">
<tr>
<td><strong>相关文章</strong></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="box">
<tr>
<td><ul>
[!--other.link--]
</ul></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="title margin_top">
<tr>
<td><strong>栏目更新</strong></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="box">
<tr>
<td><ul>
              <script src='[!--news.url--]d/js/class/class[!--self.classid--]_newnews.js'></script></ul></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="title margin_top">
<tr>
<td><strong>栏目热门</strong></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="box">
<tr>
<td><ul>
              <script src='[!--news.url--]d/js/class/class[!--self.classid--]_hotnews.js'></script></ul></td>
</tr>
</table></td>
</tr>
</table>
<table width="980" height="110" align="center" border="0" cellspacing="0" background="/images/dbbg.jpg" cellpadding="0">
  <tr>
    <td  align="center" height="70px"><div style="font-size:12px; color:#FFFFFF; line-height:22px;font-family:Arial, Helvetica, sans-serif">京ICP备12051708号&nbsp;&nbsp;版权所有 2012-2013 光线时代（北京）数码科技有限公司&nbsp;&nbsp;&nbsp;&nbsp;地址：北京市朝阳区建国路15号院甲1号北岸1292自由创意区B座6层<br />
电话：010-85376281&nbsp;&nbsp;业务合作：lightmaking@163.com&nbsp;&nbsp;业务QQ：562374011&nbsp;&nbsp;2206199834&nbsp;&nbsp;</div>
</td>
  </tr>
</table>
[!--page.stats--]
</body>
</html>