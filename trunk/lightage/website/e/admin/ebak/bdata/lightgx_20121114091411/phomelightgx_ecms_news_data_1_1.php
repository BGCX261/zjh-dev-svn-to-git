<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_ecms_news_data_1`;");
E_C("CREATE TABLE `phomelightgx_ecms_news_data_1` (
  `id` int(11) NOT NULL default '0',
  `classid` smallint(6) NOT NULL default '0',
  `writer` varchar(30) NOT NULL default '',
  `befrom` varchar(60) NOT NULL default '',
  PRIMARY KEY  (`id`),
  KEY `classid` (`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_ecms_news_data_1` values('1','1','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('2','1','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('3','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('4','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('5','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('6','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('7','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('8','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('9','2','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('10','4','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('11','5','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('12','6','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('13','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('14','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('15','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('16','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('17','16','','');");
E_D("replace into `phomelightgx_ecms_news_data_1` values('18','16','','');");

@include("../../inc/footer.php");
?>