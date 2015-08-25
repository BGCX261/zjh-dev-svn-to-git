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
</head>
<body class="listpage">
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
<td class="news_list"><table width="100%" border="0" cellspacing="0" cellpadding="0" class="position">
<tr>
<td>您当前的位置：[!--newsnav--]</td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="box">
<tr>
<td>[!--empirenews.listtemp--]<ul>
<!--list.var1-->
<!--list.var2-->
<!--list.var3-->
<!--list.var4-->
<!--list.var5--></ul>
[!--empirenews.listtemp--]
<table width="100%" border="0" cellspacing="0" cellpadding="0">
<tr>
                <td height="38"><div class="epages">[!--show.listpage--]</div></td>
</tr>
</table>
</td>
</tr>
</table></td>
<td class="sider"><table width="100%" border="0" cellspacing="0" cellpadding="0" class="title">
<tr>
<td><strong>推荐资讯</strong></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="8" cellpadding="0" class="box">
<tr>
<td><? @sys_GetClassNewsPic('selfinfo',2,4,128,90,1,20,2);?>
</td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="title margin_top">
<tr>
<td><strong>最后更新</strong></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="box">
<tr>
<td><ul>
<? @sys_GetEcmsInfo('selfinfo',10,44,0,0,2,0);?> 
</ul></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="title margin_top">
<tr>
<td><strong>热门点击</strong></td>
</tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0" class="box">
<tr>
<td><ol class="rank">
<? @sys_GetEcmsInfo('selfinfo',10,40,0,1,10,0);?> 
</ol></td>
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
</body>
</html>