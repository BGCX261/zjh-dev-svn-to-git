<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>[!--pagetitle--] - 光线时代（北京）数码科技有限公司</title>
<meta name="keywords" content="[!--pagekey--]" />
<meta name="description" content="[!--pagedes--]" />

<link href="/images/SpryMenuBarHorizontal.css" rel="stylesheet" type="text/css" />
<script src="/images/jquery-1.2.1.min.js" type="text/javascript"></script>
<script src="/images/menu.js" type="text/javascript"></script>
<link rel="stylesheet" type="text/css" href="/images/css.css" />
<style type="text/css">
.aa {color:#999999; font-family:Arial, Helvetica, sans-serif; font-size:12px}
.aa a{color:#999999; font-size:12px; text-decoration:none}
.aa a:hover{color:#FF0000; font-size:12px; text-decoration:none}
</style>
</head>

<body bgcolor="#12141B" style="padding:0; margin:0">
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


<table align="center" width="980" border="0" cellspacing="0" cellpadding="0" style="background:url(/images/titlebg.jpg) no-repeat">
  <tr>
    <td height="20px"></td>
  </tr>
  <tr>
    <td><table align="center" width="980" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td valign="top" width="210"><table width="210" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td height="19" background="/images/index_37.jpg"></td>
  </tr>
  <tr>
    <td style="overflow:hidden"><ul id="menu">
		<li>
			<a href="#">写实风格</a>
			<ul><? @sys_ShowClassByTemp(7,1,0,0);?></ul>
		</li>
		
		<li><a href="/zpxs/2/" target="_self">卡通风格</a></li>
		<li><a href="/zpxs/3/" target="_self">唯美风格</a></li>
		<li><a href="/zpxs/4/" target="_self">插画</a></li>
		<li>
			<a href="#">漫画</a>
			<ul><? @sys_ShowClassByTemp(11,1,0,0);?></ul>
		</li>
		<li><a href="/zpxs/6/" target="_self">3D模型</a></li>
	</ul></td>
  </tr>
</table>
</td>
    <td width="20px"></td>
    <td valign="top"><table width="750" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="554" height="40px" align="left" style="border-bottom:1px solid #333333;FONT: 14px/16px 'Microsoft YaHei'; color:#FFFFFF; padding-left:20px">[!--class.name--]</td>
    <td width="196" style="border-bottom:1px solid #FF0000"><div style="font-size:12px; color:#666666; font-family:'宋体'">您当前的位置：首页&nbsp;&gt;&nbsp;[!--class.name--]</div></td>
  </tr>
  <tr>
    <td colspan="2" align="center" valign="top"><div style="padding:10px 0 0 15px">
 
<link href="/images/productquery_dolphin.css" rel="stylesheet" type="text/css" />
 
[!--empirenews.listtemp--]<!--list.var1-->[!--empirenews.listtemp--]
 

 
 

 
 

 
 
<script> 
$("div.picFit").each(function(){
			maxHeight=parseInt($(this).css("height"));
			maxWidth=parseInt($(this).css("width"));
			accMax=maxWidth/maxHeight;
 
			$(this).find("img").each(function(){
				
				$(this).css({width:"",height:""});
						if($(this)[0].offsetHeight>=$(this)[0].offsetWidth/accMax){
							$(this).css({height:"231px"});	
							MT = (maxHeight-$(this)[0].offsetHeight)/2 + "px";
							$(this).css({marginTop:MT});
						}else{
							$(this).css({width:"231px"});
							MT = (maxHeight-$(this)[0].offsetHeight)/2 + "px";
							$(this).css({marginTop:MT});
						}
			});
		});
</script>
<div id="showpages" >
	  <div id="pages"  class="aa" style="font-family:'宋体'"> [!--show.listpage--]</div>
     </div>
 
</div></td>
  </tr>
</table>
</td>
  </tr>
</table></td>
  </tr>
</table>

<table align="center" width="980" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td height="20px"></td>
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
