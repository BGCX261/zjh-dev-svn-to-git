<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsclass`;");
E_C("CREATE TABLE `phomelightgx_enewsclass` (
  `classid` smallint(6) NOT NULL auto_increment,
  `bclassid` smallint(6) NOT NULL default '0',
  `classname` varchar(50) NOT NULL default '',
  `sonclass` text NOT NULL,
  `is_zt` tinyint(1) NOT NULL default '0',
  `lencord` smallint(6) NOT NULL default '0',
  `link_num` tinyint(4) NOT NULL default '0',
  `newstempid` smallint(6) NOT NULL default '0',
  `onclick` int(11) NOT NULL default '0',
  `listtempid` smallint(6) NOT NULL default '0',
  `featherclass` text NOT NULL,
  `islast` tinyint(1) NOT NULL default '0',
  `classpath` text NOT NULL,
  `classtype` varchar(10) NOT NULL default '',
  `newspath` varchar(20) NOT NULL default '',
  `filename` tinyint(1) NOT NULL default '0',
  `filetype` varchar(10) NOT NULL default '',
  `openpl` tinyint(1) NOT NULL default '0',
  `openadd` tinyint(1) NOT NULL default '0',
  `newline` int(11) NOT NULL default '0',
  `hotline` int(11) NOT NULL default '0',
  `goodline` int(11) NOT NULL default '0',
  `classurl` varchar(200) NOT NULL default '',
  `groupid` smallint(6) NOT NULL default '0',
  `myorder` smallint(6) NOT NULL default '0',
  `filename_qz` varchar(20) NOT NULL default '',
  `hotplline` tinyint(4) NOT NULL default '0',
  `modid` smallint(6) NOT NULL default '0',
  `checked` tinyint(1) NOT NULL default '0',
  `firstline` tinyint(4) NOT NULL default '0',
  `bname` varchar(50) NOT NULL default '',
  `islist` tinyint(1) NOT NULL default '0',
  `searchtempid` smallint(6) NOT NULL default '0',
  `tid` smallint(6) NOT NULL default '0',
  `tbname` varchar(60) NOT NULL default '',
  `maxnum` int(11) NOT NULL default '0',
  `checkpl` tinyint(1) NOT NULL default '0',
  `down_num` tinyint(4) NOT NULL default '0',
  `online_num` tinyint(4) NOT NULL default '0',
  `listorder` varchar(50) NOT NULL default '',
  `reorder` varchar(50) NOT NULL default '',
  `intro` text NOT NULL,
  `classimg` varchar(255) NOT NULL default '',
  `jstempid` smallint(6) NOT NULL default '0',
  `addinfofen` int(11) NOT NULL default '0',
  `listdt` tinyint(1) NOT NULL default '0',
  `showclass` tinyint(1) NOT NULL default '0',
  `showdt` tinyint(1) NOT NULL default '0',
  `checkqadd` tinyint(1) NOT NULL default '0',
  `qaddlist` tinyint(1) NOT NULL default '0',
  `qaddgroupid` text NOT NULL,
  `qaddshowkey` tinyint(1) NOT NULL default '0',
  `adminqinfo` tinyint(1) NOT NULL default '0',
  `doctime` smallint(6) NOT NULL default '0',
  `classpagekey` varchar(255) NOT NULL default '',
  `dtlisttempid` smallint(6) NOT NULL default '0',
  `classtempid` smallint(6) NOT NULL default '0',
  `nreclass` tinyint(1) NOT NULL default '0',
  `nreinfo` tinyint(1) NOT NULL default '0',
  `nrejs` tinyint(1) NOT NULL default '0',
  `nottobq` tinyint(1) NOT NULL default '0',
  `ipath` varchar(255) NOT NULL default '',
  `addreinfo` tinyint(1) NOT NULL default '0',
  `haddlist` tinyint(4) NOT NULL default '0',
  `sametitle` tinyint(1) NOT NULL default '0',
  `definfovoteid` smallint(6) NOT NULL default '0',
  `wburl` varchar(255) NOT NULL default '',
  `qeditchecked` tinyint(1) NOT NULL default '0',
  `wapstyleid` smallint(6) NOT NULL default '0',
  `repreinfo` tinyint(1) NOT NULL default '0',
  `pltempid` smallint(6) NOT NULL default '0',
  `cgroupid` text NOT NULL,
  `yhid` smallint(6) NOT NULL default '0',
  `wfid` smallint(6) NOT NULL default '0',
  `cgtoinfo` tinyint(1) NOT NULL default '0',
  `bdinfoid` varchar(25) NOT NULL default '',
  PRIMARY KEY  (`classid`),
  KEY `bclassid` (`bclassid`)
) ENGINE=MyISAM AUTO_INCREMENT=33 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsclass` values('1','0','网站首页','','0','25','10','1','0','1','','1','sy','.html','Y-m-d','0','.html','0','0','10','10','10','/','0','0','','10','1','1','10','网站首页','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('2','0','关于我们','','0','25','10','1','0','9','','1','gywm','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','关于我们','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('3','0','作品欣赏','|8|9|10|12|13|14|15|16|','0','6','10','0','0','10','','0','zpxs','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','作品欣赏','1','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('4','0','业务范围','','0','25','10','1','0','9','','1','ywfw','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','业务范围','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('5','0','招聘人才','','0','25','10','1','0','9','','1','zprc','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','招聘人才','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('6','0','联系我们','','0','25','10','1','0','9','','1','lxwm','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','联系我们','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('7','3','写实风格','|14|15|16|','0','6','10','0','0','10','|3|','0','zpxs/1','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','写实风格','1','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('8','3','卡通风格','','0','25','10','10','0','10','|3|','1','zpxs/2','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','卡通风格','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('9','3','唯美风格','','0','25','10','10','0','10','|3|','1','zpxs/3','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','唯美风格','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('10','3','插画','','0','6','10','10','0','10','|3|','1','zpxs/4','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','插画','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('11','3','漫画','|12|','0','6','10','1','0','10','|3|','0','zpxs/5','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','漫画','1','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('12','11','小将岳云','','0','6','10','10','0','10','|3|11|','1','zpxs/5/1','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','小将岳云','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('13','3','3D模型','','0','6','10','10','0','10','|3|','1','zpxs/6','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','3D模型','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('14','7','中国风','','0','25','10','1','0','10','|3|7|','1','zpxs/1/1','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','中国风','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('15','7','欧美风','','0','25','10','1','0','10','|3|7|','1','zpxs/1/2','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','欧美风','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('16','7','场景','','0','6','10','10','0','10','|3|7|','1','zpxs/1/3','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','场景','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('17','0','HOME','','0','25','10','0','0','0','','0','home','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','HOME','2','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('18','0','ABOUT US','','0','25','10','1','0','11','','1','about','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','ABOUT US','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('19','0','OUR WORKS','|24|25|26|28|29|30|31|32|','0','6','10','11','0','12','','0','WORKS','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','OUR WORKS','1','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('20','0','SCOPE','','0','25','10','1','0','11','','1','SCOPE','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','SCOPE','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('21','0','RECRUITMENT','','0','25','10','1','0','11','','1','RECRUITMENT','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','RECRUITMENT','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('22','0','CONTACT US','','0','25','10','1','0','11','','1','CONTACT','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','CONTACT US','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('23','19','Realistic style','|28|29|30|','0','6','10','11','0','12','|19|','0','WORKS/1','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','Realistic style','1','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('24','19','Cartoon style','','0','6','10','11','0','12','|19|','1','WORKS/2','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','Cartoon style','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('25','19','Aesthetic style','','0','6','10','11','0','12','|19|','1','WORKS/3','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','Aesthetic style','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('26','19','Illustration','','0','6','10','11','0','12','|19|','1','WORKS/4','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','Illustration','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('27','19','Cartoon','|32|','0','6','10','11','0','12','|19|','0','WORKS/5','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','Cartoon','1','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('28','23','China Wind','','0','6','10','11','0','12','|19|23|','1','WORKS/1/1','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','China Wind','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('29','23','European and American style','','0','6','10','11','0','12','|19|23|','1','WORKS/1/2','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','European and American style','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('30','23','Scene','','0','6','10','11','0','12','|19|23|','1','WORKS/1/3','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','Scene','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('31','19','3D model','','0','6','10','11','0','12','|19|','1','WORKS/6','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','3D model','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");
E_D("replace into `phomelightgx_enewsclass` values('32','27','Teenager POSTGRADUATE','','0','6','10','11','0','12','|19|27|','1','WORKS/5/1','.html','Y-m-d','0','.html','0','0','10','10','10','','0','0','','10','1','1','10','Teenager POSTGRADUATE','0','0','1','news','0','0','2','2','id DESC','newstime DESC','','','1','0','0','0','0','0','0','','0','0','0','','0','1','0','0','0','0','','1','0','0','0','','0','0','0','0','','0','0','0','');");

@include("../../inc/footer.php");
?>