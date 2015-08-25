<?php
if(!defined('InEmpireCMS'))
{
	exit();
}
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>光线时代（北京）数码科技有限公司</title>
<meta name="keywords" content="光线时代（北京）数码科技有限公司" />
<meta name="description" content="光线时代（北京）数码科技有限公司是一家具有国际专业水准，致力于用国际专业标准为客户提供游戏设计制作全方位服务的数字技术提供商，领域涵盖游戏研发、概念设计、插画、漫画等，为不同行业的客户提供有针对性的产品和服务形式，以满足客户的不同需求。
" />

<link href="/images/SpryMenuBarHorizontal.css" rel="stylesheet" type="text/css" />

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
    <td valign="top"><table width="480" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td><table width="480" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="370" height="30px" style="border-bottom:1px solid #333333"><img src="/images/gywm.png" width="180" height="30" /></td>
    <td width="110"  style="border-bottom:1px solid #FF0000" align="center"><a href="/gywm" target="_self"><img src="/images/more.png" width="50" height="30" border="0" /></a></td>
  </tr>
</table>
</td>
  </tr>
  <tr>
    <td align="left"><div style="font-size:12px; color:#999999; line-height:20px; padding:5px">&nbsp;&nbsp;&nbsp;&nbsp;光线时代（北京）数码科技有限公司是一家具有国际专业水准，致力于用国际专业标准为客户提供游戏设计制作全方位服务的数字技术提供商，领域涵盖游戏研发、概念设计、插画、漫画等，为不同行业的客户提供有针对性的产品和服务形式，以满足客户的不同需求。<br />&nbsp;&nbsp;&nbsp;&nbsp;光线时代（北京）数码科技有限公司的前身光线制作（北京）工作室成立2005年核心人员均有八...</div></td>
  </tr>
</table>
</td>
    <td width="20px">&nbsp;</td>
    <td valign="top"><table width="480" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td><table width="480" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="370" height="30px" style="border-bottom:1px solid #333333"><img src="/images/zptj.png" width="180" height="30" /></td>
    <td width="110"  style="border-bottom:1px solid #FF0000" align="center"><a href="/zpxs" target="_self"><img src="/images/more.png" width="50" height="30" border="0" /></a></td>
  </tr>
</table>
</td>
  </tr>
  <tr>
    <td align="center">
           <link href="/images/productlist_cyrano_lef.css" rel="stylesheet" type="text/css" />
 
<div class="productlist_cyrano_lef">
<div style=" padding:5px;WIDTH: 460px; OVERFLOW: hidden" id="demo">
 <table align=left width="460" cellpadding=0 cellspace=0 border=0>
  	<tr>
		<td id="demo1" valign=top>
  			<table border=0 cellpadding=0 cellspacing=0>
  				<tr>

  <?php
$bqno=0;
$ecms_bq_sql=sys_ReturnEcmsLoopBq(3,16,2,0,0,0);
while($bqr=$empire->fetch($ecms_bq_sql)){
$bqsr=sys_ReturnEcmsLoopStext($bqr);
$bqno++;
?>

<td style="width:130px;">
	<div class="fang" style="height:130px">
	<div class="picFit" style="height:130px">
		<a href="<?=$bqsr[titleurl]?>" target="_blank" ><img src="<?=$bqr[titlepic]?>" style="height:100px;" border="0" /></a>
		<div align="center" style="padding:5px"><A href="<?=$bqsr[titleurl]?>" target="_blank" ><?=$bqr[title]?></A></div>
	</div>
	</div>
</td>
<?php
}
?>
				</tr>
  			</table>
 		</td>
		<td id="demo2" valign=top></td>
	</tr>
</table>
 
</div>
</div>
 
 
 
<script> 
	var speed=20;
	var GD=document.getElementById('demo'); 
	var GD1=document.getElementById('demo1');
	var GD2=document.getElementById('demo2');
	GD2.innerHTML=GD1.innerHTML;
	function Marquee(){
		if(GD2.offsetWidth-GD.scrollLeft<=0){
			GD.scrollLeft-=GD1.offsetWidth;
		}else{
			GD.scrollLeft++;
		}
	}
	var MyMar=setInterval(Marquee,speed);
	GD.onmouseover=function() {clearInterval(MyMar);}
	GD.onmouseout=function() {MyMar=setInterval(Marquee,speed);}
</script></td>
  </tr>
</table></td>
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
