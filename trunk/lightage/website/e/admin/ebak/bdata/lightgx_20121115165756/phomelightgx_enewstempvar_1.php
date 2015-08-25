<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewstempvar`;");
E_C("CREATE TABLE `phomelightgx_enewstempvar` (
  `varid` smallint(6) NOT NULL auto_increment,
  `myvar` varchar(60) NOT NULL default '',
  `varname` varchar(60) NOT NULL default '',
  `varvalue` mediumtext NOT NULL,
  `classid` smallint(6) NOT NULL default '0',
  `isclose` tinyint(1) NOT NULL default '0',
  `myorder` smallint(6) NOT NULL default '0',
  PRIMARY KEY  (`varid`),
  KEY `classid` (`classid`)
) ENGINE=MyISAM AUTO_INCREMENT=12 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewstempvar` values('1','header','页面头部','<table align=\"center\" width=\"980\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\" background=\"/images/tbbg.jpg\">\r\n  <tr>\r\n    <td width=\"326\" height=\"100\">&nbsp;</td>\r\n    <td width=\"654\" valign=\"top\" style=\"font-size:12px\" >\r\n	<div class=\"aa\" align=\"right\" style=\"padding:10px 60px 0 0\"><a href=\"/\" target=\"_self\">中文版</a>&nbsp;&nbsp;|&nbsp;&nbsp;<a href=\"/home\" target=\"_self\">英文版</a></div>\r\n	\r\n	<ul id=\"MenuBar1\" class=\"MenuBarHorizontal\" style=\"padding-top:25px\">\r\n          <li class=\"menu\">\r\n        	<div class=\"cn\"><a  href=\"/\">网站首页</a></div>\r\n            <div class=\"en\">HOME</div>\r\n          </li>\r\n          <li class=\"menu\">\r\n          	<div class=\"cn\"><a class=\"MenuBarItemSubmenu\" href=\"/gywm\">关于我们</a></div>\r\n            <div class=\"en\">ABOUT US</div>\r\n          </li >\r\n          <li class=\"menu\">\r\n          	 <div class=\"cn\"><a class=\"MenuBarItemSubmenu\" href=\"/zpxs\">作品欣赏</a></div>\r\n             <div class=\"en\">OUR WORKS</div>\r\n          </li>\r\n          <li class=\"menu\">\r\n          	<div class=\"cn\"><a  class=\"MenuBarItemSubmenu\" href=\"/ywfw\">业务范围</a></div>\r\n            <div class=\"en\">SCOPE</div>\r\n         </li>\r\n          <li class=\"menu\">\r\n          	<div class=\"cn\"><a  href=\"/zprc\" class=\"MenuBarItemSubmenu\">招聘人才</a></div>\r\n            <div class=\"en\">RECRUITMENT</div>\r\n          </li>\r\n            <li class=\"menu\">\r\n            	<div class=\"cn\"><a  href=\"/lxwm\">联系我们</a></div>\r\n                <div class=\"en\">CONTACT US</div>\r\n           </li>\r\n      </ul>\r\n	</td>\r\n  </tr>\r\n  <tr>\r\n    <td colspan=\"2\" align=\"center\">[phomeflashpic]1,5,980,300,0,0,0,2,0,0[/phomeflashpic]</td>\r\n  </tr>\r\n</table>','0','0','1');");
E_D("replace into `phomelightgx_enewstempvar` values('8','left','左部变量','<table width=\"210\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\r\n  <tr>\r\n    <td height=\"19\" background=\"/images/index_37.jpg\"></td>\r\n  </tr>\r\n  <tr>\r\n    <td style=\"overflow:hidden\"><ul id=\"menu\">\r\n		<li>\r\n			<a href=\"#\">写实风格</a>\r\n			<ul>[showclasstemp]7,1,0,0[/showclasstemp]</ul>\r\n		</li>\r\n		\r\n		<li><a href=\"/zpxs/2/\" target=\"_self\">卡通风格</a></li>\r\n		<li><a href=\"/zpxs/3/\" target=\"_self\">唯美风格</a></li>\r\n		<li><a href=\"/zpxs/4/\" target=\"_self\">插画</a></li>\r\n		<li>\r\n			<a href=\"#\">漫画</a>\r\n			<ul>[showclasstemp]11,1,0,0[/showclasstemp]</ul>\r\n		</li>\r\n		<li><a href=\"/zpxs/6/\" target=\"_self\">3D模型</a></li>\r\n	</ul></td>\r\n  </tr>\r\n</table>','0','0','0');");
E_D("replace into `phomelightgx_enewstempvar` values('2','footer','页面尾部','<table width=\"980\" height=\"110\" align=\"center\" border=\"0\" cellspacing=\"0\" background=\"/images/dbbg.jpg\" cellpadding=\"0\">\r\n  <tr>\r\n    <td  align=\"center\" height=\"70px\"><div style=\"font-size:12px; color:#FFFFFF; line-height:22px;font-family:Arial, Helvetica, sans-serif\">版权所有 2012-2013 光线时代（北京）数码科技有限公司&nbsp;&nbsp;&nbsp;&nbsp;地址：北京市朝阳区建国路15号院甲1号北岸1292自由创意区B座6层<br />\r\n电话：010-85376281&nbsp;&nbsp;业务合作：lightmaking@163.com&nbsp;&nbsp;人力资源：Light_magic@163.com</div>\r\n</td>\r\n  </tr>\r\n</table>','0','0','0');");
E_D("replace into `phomelightgx_enewstempvar` values('9','top','头部变量（英文）','<table align=\"center\" width=\"980\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\" background=\"/images/tbbg.jpg\">\r\n  <tr>\r\n    <td width=\"326\" height=\"100\">&nbsp;</td>\r\n    <td width=\"654\" valign=\"top\" style=\"font-size:12px\" >\r\n	<div class=\"aa\" align=\"right\" style=\"padding:10px 60px 0 0\"><a href=\"/\" target=\"_self\">中文版</a>&nbsp;&nbsp;|&nbsp;&nbsp;<a href=\"/home\" target=\"_self\">英文版</a></div>\r\n	\r\n	<ul id=\"MenuBar1\" class=\"MenuBarHorizontal\" style=\"padding-top:25px\">\r\n          <li class=\"menu\">\r\n        	<div class=\"cn\"><a  href=\"/home\">HOME</a></div>\r\n            <div class=\"en\">网站首页</div>\r\n          </li>\r\n          <li class=\"menu\">\r\n          	<div class=\"cn\"><a class=\"MenuBarItemSubmenu\" href=\"/ABOUT\">ABOUT US</a></div>\r\n            <div class=\"en\">关于我们</div>\r\n          </li >\r\n          <li class=\"menu\">\r\n          	 <div class=\"cn\"><a class=\"MenuBarItemSubmenu\" href=\"/WORKS\">OUR WORKS</a></div>\r\n             <div class=\"en\">作品欣赏</div>\r\n          </li>\r\n          <li class=\"menu\">\r\n          	<div class=\"cn\"><a  class=\"MenuBarItemSubmenu\" href=\"/SCOPE\">SCOPE</a></div>\r\n            <div class=\"en\">业务范围</div>\r\n         </li>\r\n          <li class=\"menu\">\r\n          	<div class=\"cn\"><a  href=\"/RECRUITMENT\" class=\"MenuBarItemSubmenu\">RECRUITMENT</a></div>\r\n            <div class=\"en\">招聘人才</div>\r\n          </li>\r\n            <li class=\"menu\">\r\n            	<div class=\"cn\"><a  href=\"/CONTACT\">CONTACT US</a></div>\r\n                <div class=\"en\">联系我们</div>\r\n           </li>\r\n      </ul>\r\n	</td>\r\n  </tr>\r\n  <tr>\r\n    <td colspan=\"2\" align=\"center\">[phomeflashpic]1,5,980,300,0,0,0,2,0,0[/phomeflashpic]</td>\r\n  </tr>\r\n</table>','0','0','0');");
E_D("replace into `phomelightgx_enewstempvar` values('3','dtheader','动态页面头部','<!-- 页头 -->\r\n<table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellspacing=\\\\\"0\\\\\" cellpadding=\\\\\"0\\\\\" class=\\\\\"top\\\\\">\r\n<tr>\r\n<td><table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellspacing=\\\\\"0\\\\\" cellpadding=\\\\\"0\\\\\">\r\n<tr>\r\n<td width=\\\\\"63%\\\\\">\r\n<!-- 登录 -->\r\n<script>\r\ndocument.write(\\\\''<script src=\\\\\"[!--news.url--]e/member/login/loginjs.php?t=\\\\''+Math.random()+\\\\''\\\\\"><\\\\''+\\\\''/script>\\\\'');\r\n</script>\r\n</td>\r\n<td align=\\\\\"right\\\\\">\r\n<a onclick=\\\\\"window.external.addFavorite(location.href,document.title)\\\\\" href=\\\\\"#ecms\\\\\">加入收藏</a> | <a onclick=\\\\\"this.style.behavior=\\\\''url(#default#homepage)\\\\'';this.setHomePage(\\\\''[!--news.url--]\\\\'')\\\\\" href=\\\\\"#ecms\\\\\">设为首页</a> | <a href=\\\\\"[!--news.url--]e/member/cp/\\\\\">会员中心</a> | <a href=\\\\\"[!--news.url--]e/DoInfo/\\\\\">我要投稿</a> | <a href=\\\\\"[!--news.url--]e/web/?type=rss2\\\\\" target=\\\\\"_blank\\\\\">RSS<img src=\\\\\"[!--news.url--]skin/default/images/rss.gif\\\\\" border=\\\\\"0\\\\\" hspace=\\\\\"2\\\\\" /></a>\r\n</td>\r\n</tr>\r\n</table></td>\r\n</tr>\r\n</table>\r\n<table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"10\\\\\">\r\n<tr valign=\\\\\"middle\\\\\">\r\n<td width=\\\\\"240\\\\\" align=\\\\\"center\\\\\"><a href=\\\\\"[!--news.url--]\\\\\"><img src=\\\\\"[!--news.url--]skin/default/images/logo.gif\\\\\" width=\\\\\"200\\\\\" height=\\\\\"65\\\\\" border=\\\\\"0\\\\\" /></a></td>\r\n<td align=\\\\\"center\\\\\"><a href=\\\\\"http://www.phome.net/OpenSource/\\\\\" target=\\\\\"_blank\\\\\"><img src=\\\\\"[!--news.url--]skin/default/images/opensource.gif\\\\\" width=\\\\\"100%\\\\\" height=\\\\\"70\\\\\" border=\\\\\"0\\\\\" /></a></td>\r\n</tr>\r\n</table>\r\n<!-- 导航tab选项卡 -->\r\n<table width=\\\\\"920\\\\\" border=\\\\\"0\\\\\" align=\\\\\"center\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"0\\\\\" class=\\\\\"nav\\\\\">\r\n  <tr> \r\n    <td class=\\\\\"nav_global\\\\\"><ul>\r\n        <li class=\\\\\"curr\\\\\" id=\\\\\"tabnav_btn_0\\\\\" onmouseover=\\\\\"tabit(this)\\\\\"><a href=\\\\\"[!--news.url--]\\\\\">首页</a></li>\r\n        <li id=\\\\\"tabnav_btn_1\\\\\" onmouseover=\\\\\"tabit(this)\\\\\"><a href=\\\\\"[!--news.url--]news/\\\\\">新闻中心</a></li>\r\n        <li id=\\\\\"tabnav_btn_2\\\\\" onmouseover=\\\\\"tabit(this)\\\\\"><a href=\\\\\"[!--news.url--]download/\\\\\">下载中心</a></li>\r\n        <li id=\\\\\"tabnav_btn_3\\\\\" onmouseover=\\\\\"tabit(this)\\\\\"><a href=\\\\\"[!--news.url--]movie/\\\\\">影视频道</a></li>\r\n        <li id=\\\\\"tabnav_btn_4\\\\\" onmouseover=\\\\\"tabit(this)\\\\\"><a href=\\\\\"[!--news.url--]shop/\\\\\">网上商城</a></li>\r\n        <li id=\\\\\"tabnav_btn_5\\\\\" onmouseover=\\\\\"tabit(this)\\\\\"><a href=\\\\\"[!--news.url--]flash/\\\\\">FLASH频道</a></li>\r\n        <li id=\\\\\"tabnav_btn_6\\\\\" onmouseover=\\\\\"tabit(this)\\\\\"><a href=\\\\\"[!--news.url--]photo/\\\\\">图片频道</a></li>\r\n        <li id=\\\\\"tabnav_btn_7\\\\\" onmouseover=\\\\\"tabit(this)\\\\\"><a href=\\\\\"[!--news.url--]article/\\\\\">文章中心</a></li>\r\n        <li id=\\\\\"tabnav_btn_8\\\\\" onmouseover=\\\\\"tabit(this)\\\\\"><a href=\\\\\"[!--news.url--]info/\\\\\">分类信息</a></li>\r\n      </ul></td>\r\n  </tr>\r\n</table>','0','0','0');");
E_D("replace into `phomelightgx_enewstempvar` values('4','infoarea','分类信息区域导航','<table width=\\\\\"96%\\\\\" border=\\\\\"0\\\\\" align=\\\\\"center\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"4\\\\\">\r\n	<tr>\r\n		<td width=\\\\\"33%\\\\\"><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=东城区\\\\\">东城区</a></td>\r\n		<td width=\\\\\"33%\\\\\"><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=西城区\\\\\">西城区</a></td>\r\n		<td width=\\\\\"33%\\\\\"><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=通州区\\\\\">通州区</a></td>\r\n	</tr>\r\n	<tr>\r\n		<td><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=崇文区\\\\\">崇文区</a></td>\r\n		<td><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=宣武区\\\\\">宣武区</a></td>\r\n		<td><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=大兴区\\\\\">大兴区</a></td>\r\n	</tr>\r\n	<tr>\r\n		<td><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" /><a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=朝阳区\\\\\">&nbsp;朝阳区</a></td>\r\n		<td><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=海淀区\\\\\">海淀区</a></td>\r\n		<td><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=昌平区\\\\\">昌平区</a></td>\r\n	</tr>\r\n	<tr>\r\n		<td><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=丰台区\\\\\">丰台区</a></td>\r\n		<td><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=石景山区\\\\\">石景山区</a></td>\r\n		<td><img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo.php?classid=[!--self.classid--]&ph=1&myarea=其它\\\\\">其它</a></td>\r\n	</tr>\r\n</table>','0','0','0');");
E_D("replace into `phomelightgx_enewstempvar` values('5','infoclassnav','分类信息分类导航','<table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellpadding=\\\\\"4\\\\\" cellspacing=\\\\\"0\\\\\">\r\n  <tr>\r\n    <td bgcolor=\\\\\"#EEF1F4\\\\\">&nbsp;<img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=10\\\\\"><strong>房屋信息</strong></a></td>\r\n  </tr> \r\n</table>\r\n<table width=\\\\\"96%\\\\\" border=\\\\\"0\\\\\" align=\\\\\"center\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"4\\\\\">\r\n  <tr>\r\n    <td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=11\\\\\">房屋求租</a></td>\r\n    <td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=12\\\\\">房屋出租</a></td>\r\n  		<td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=15\\\\\">办公用房</a></td>\r\n  </tr>\r\n  <tr>\r\n    <td><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=13\\\\\">房屋求购</a></td>\r\n    <td><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=14\\\\\">房屋出售</a></td>\r\n  		<td><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=16\\\\\">旺铺门面</a></td>\r\n  </tr>\r\n</table>\r\n<table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"4\\\\\" bgcolor=\\\\\"#EEF1F4\\\\\">\r\n  <tr>\r\n    <td>&nbsp;<img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=17\\\\\"><strong>跳蚤市场</strong></a></td>\r\n  </tr>\r\n</table>\r\n<table width=\\\\\"96%\\\\\" border=\\\\\"0\\\\\" align=\\\\\"center\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"4\\\\\">\r\n  <tr>\r\n    <td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=18\\\\\">电脑配件</a></td>\r\n    <td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=19\\\\\">电器数码</a></td>\r\n  		<td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=21\\\\\">居家用品</a></td>\r\n  </tr>\r\n  <tr>\r\n    <td><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=20\\\\\">通讯产品</a></td>\r\n    <td><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=21\\\\\"></a></td>\r\n  		<td>&nbsp;</td>\r\n  </tr>\r\n</table>\r\n<table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellpadding=\\\\\"4\\\\\" cellspacing=\\\\\"0\\\\\" bgcolor=\\\\\"#EEF1F4\\\\\">\r\n  <tr>\r\n    <td>&nbsp;<img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=22\\\\\"><strong>同城生活</strong></a></td>\r\n  </tr>\r\n</table>\r\n<table width=\\\\\"96%\\\\\" border=\\\\\"0\\\\\" align=\\\\\"center\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"4\\\\\">\r\n  <tr>\r\n    <td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=23\\\\\">本地新闻</a></td>\r\n    <td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=24\\\\\">购物打折</a></td>\r\n  		<td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=26\\\\\">便民告示</a></td>\r\n  </tr>\r\n  <tr>\r\n    <td><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=25\\\\\">旅游活动</a></td>\r\n    <td>&nbsp;</td>\r\n  		<td>&nbsp;</td>\r\n  </tr>\r\n</table>\r\n<table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellpadding=\\\\\"4\\\\\" cellspacing=\\\\\"0\\\\\" bgcolor=\\\\\"#EEF1F4\\\\\">\r\n  <tr>\r\n    <td>&nbsp;<img src=\\\\\"[!--news.url--]e/data/images/msgnav.gif\\\\\" width=\\\\\"5\\\\\" height=\\\\\"5\\\\\" />&nbsp;<a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=27\\\\\"><strong>求职招聘</strong></a></td>\r\n  </tr>\r\n</table>\r\n<table width=\\\\\"96%\\\\\" border=\\\\\"0\\\\\" align=\\\\\"center\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"4\\\\\">\r\n  <tr>\r\n    <td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=28\\\\\">工程技术</a></td>\r\n    <td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=29\\\\\">财务会计</a></td>\r\n  		<td width=\\\\\"33%\\\\\"><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=31\\\\\">经营管理</a></td>\r\n  </tr>\r\n  <tr>\r\n    <td><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=30\\\\\">餐饮行业</a></td>\r\n    <td><a href=\\\\\"[!--news.url--]e/action/ListInfo/?classid=31\\\\\"></a></td>\r\n  		<td>&nbsp;</td>\r\n  </tr>\r\n</table>','0','0','0');");
E_D("replace into `phomelightgx_enewstempvar` values('7','pl','评论表单','<script>\r\n		  function CheckPl(obj)\r\n		  {\r\n		  if(obj.saytext.value==\\\\\"\\\\\")\r\n		  {\r\n		  alert(\\\\\"您没什么话要说吗？\\\\\");\r\n		  obj.saytext.focus();\r\n		  return false;\r\n		  }\r\n		  return true;\r\n		  }\r\n		  </script><form action=\\\\\"[!--news.url--]e/enews/index.php\\\\\" method=\\\\\"post\\\\\" name=\\\\\"saypl\\\\\" id=\\\\\"saypl\\\\\" onsubmit=\\\\\"return CheckPl(document.saypl)\\\\\">\r\n<table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"0\\\\\" id=\\\\\"plpost\\\\\">\r\n\r\n<tr>\r\n<td><table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"0\\\\\" class=\\\\\"title\\\\\">\r\n<tr>\r\n<td><strong>发表评论</strong></td>\r\n<td align=\\\\\"right\\\\\"><a href=\\\\\"[!--news.url--]e/pl/?classid=[!--classid--]&amp;id=[!--id--]\\\\\">共有<span><script type=\\\\\"text/javascript\\\\\" src=\\\\\"[!--news.url--]e/public/ViewClick/?classid=[!--classid--]&id=[!--id--]&down=2\\\\\"></script></span>条评论</a></td>\r\n</tr>\r\n</table>\r\n<table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellspacing=\\\\\"10\\\\\" cellpadding=\\\\\"0\\\\\">\r\n<tr>\r\n<td><table width=\\\\\"100%\\\\\" border=\\\\\"0\\\\\" cellpadding=\\\\\"0\\\\\" cellspacing=\\\\\"2\\\\\">\r\n<tr>\r\n<td width=\\\\\"56%\\\\\" align=\\\\\"left\\\\\">用户名:\r\n<input name=\\\\\"username\\\\\" type=\\\\\"text\\\\\" class=\\\\\"inputText\\\\\" id=\\\\\"username\\\\\" value=\\\\\"\\\\\" size=\\\\\"16\\\\\" /></td>\r\n<td width=\\\\\"44%\\\\\" align=\\\\\"left\\\\\">密码:\r\n<input name=\\\\\"password\\\\\" type=\\\\\"password\\\\\" class=\\\\\"inputText\\\\\" id=\\\\\"password\\\\\" value=\\\\\"\\\\\" size=\\\\\"16\\\\\" /></td>\r\n</tr>\r\n<tr>\r\n<td align=\\\\\"left\\\\\">验证码:\r\n<input name=\\\\\"key\\\\\" type=\\\\\"text\\\\\" class=\\\\\"inputText\\\\\" size=\\\\\"10\\\\\" />\r\n<img src=\\\\\"[!--news.url--]e/ShowKey/?v=pl\\\\\" align=\\\\\"absmiddle\\\\\" /> </td>\r\n<td align=\\\\\"left\\\\\"><input name=\\\\\"nomember\\\\\" type=\\\\\"checkbox\\\\\" id=\\\\\"nomember\\\\\" value=\\\\\"1\\\\\" checked=\\\\\"checked\\\\\" />\r\n匿名发表</td>\r\n</tr>\r\n</table>\r\n<textarea name=\\\\\"saytext\\\\\" rows=\\\\\"6\\\\\" id=\\\\\"saytext\\\\\"></textarea><input name=\\\\\"imageField\\\\\" type=\\\\\"image\\\\\" src=\\\\\"[!--news.url--]e/data/images/postpl.gif\\\\\"/>\r\n<input name=\\\\\"id\\\\\" type=\\\\\"hidden\\\\\" id=\\\\\"id\\\\\" value=\\\\\"[!--id--]\\\\\" />\r\n<input name=\\\\\"classid\\\\\" type=\\\\\"hidden\\\\\" id=\\\\\"classid\\\\\" value=\\\\\"[!--classid--]\\\\\" />\r\n<input name=\\\\\"enews\\\\\" type=\\\\\"hidden\\\\\" id=\\\\\"enews\\\\\" value=\\\\\"AddPl\\\\\" />\r\n<input name=\\\\\"repid\\\\\" type=\\\\\"hidden\\\\\" id=\\\\\"repid\\\\\" value=\\\\\"0\\\\\" />\r\n<input type=\\\\\"hidden\\\\\" name=\\\\\"ecmsfrom\\\\\" value=\\\\\"[!--titleurl--]\\\\\"></td>\r\n</tr>\r\n</table>\r\n</td>\r\n</tr>\r\n</table></form>','0','0','0');");
E_D("replace into `phomelightgx_enewstempvar` values('10','bottom','底部变量（英文）','<table width=\"980\" height=\"110\" align=\"center\" border=\"0\" cellspacing=\"0\" background=\"/images/dbbg.jpg\" cellpadding=\"0\">\r\n  <tr>\r\n    <td  align=\"center\" height=\"70px\"><div style=\"font-size:12px; color:#FFFFFF; line-height:22px;font-family:Arial, Helvetica, sans-serif\">Copyright&nbsp;&copy;&nbsp;2012-2013 Light Time(beijing)digital technology Ltd Co.&nbsp;&nbsp;&nbsp;&nbsp;Address:No. 15 Jianguo Road, Chaoyang District, Beijing hospital<br />\r\nPhone:010-85376281&nbsp;&nbsp;Business cooperation:lightmaking@163.com&nbsp;&nbsp;Human Resources:Light_magic@163.com</div>\r\n</td>\r\n  </tr>\r\n</table>','0','0','0');");
E_D("replace into `phomelightgx_enewstempvar` values('11','enleft','左部变量（英文）','<table width=\"210\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\r\n  <tr>\r\n    <td height=\"19\" background=\"/images/index_37.jpg\"></td>\r\n  </tr>\r\n  <tr>\r\n    <td style=\"overflow:hidden\"><ul id=\"menu\">\r\n		<li>\r\n			<a href=\"#\">Realistic style</a>\r\n			<ul>[showclasstemp]23,1,0,0[/showclasstemp]</ul>\r\n		</li>\r\n		\r\n		<li><a href=\"/Works/2/\" target=\"_self\">Cartoon style</a></li>\r\n		<li><a href=\"/Works/3/\" target=\"_self\">Aesthetic style</a></li>\r\n		<li><a href=\"/Works/4/\" target=\"_self\">Illustration</a></li>\r\n		<li>\r\n			<a href=\"#\">Cartoon</a>\r\n			<ul>[showclasstemp]27,1,0,0[/showclasstemp]</ul>\r\n		</li>\r\n		<li><a href=\"/Works/6/\" target=\"_self\">3D model</a></li>\r\n	</ul></td>\r\n  </tr>\r\n</table>','0','0','0');");

@include("../../inc/footer.php");
?>