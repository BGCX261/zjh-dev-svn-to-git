<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewslog`;");
E_C("CREATE TABLE `phomelightgx_enewslog` (
  `loginid` int(11) NOT NULL auto_increment,
  `username` varchar(30) NOT NULL default '',
  `logintime` datetime NOT NULL default '0000-00-00 00:00:00',
  `loginip` varchar(20) NOT NULL default '',
  `status` tinyint(1) NOT NULL default '0',
  `password` varchar(30) NOT NULL default '',
  `loginauth` tinyint(1) NOT NULL default '0',
  PRIMARY KEY  (`loginid`)
) ENGINE=MyISAM AUTO_INCREMENT=20 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewslog` values('1','admin','2012-11-02 14:50:39','123.115.8.52','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('2','admin','2012-11-05 09:08:02','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('3','admin','2012-11-05 15:20:15','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('4','admin','2012-11-06 08:05:54','123.115.8.52','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('5','admin','2012-11-06 10:00:38','123.145.85.75','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('6','admin','2012-11-06 10:08:55','123.115.8.52','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('7','admin','2012-11-07 08:03:49','123.115.8.52','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('8','admin','2012-11-07 16:08:04','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('9','admin','2012-11-08 08:27:50','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('10','admin','2012-11-08 14:14:10','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('11','admin','2012-11-13 15:40:06','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('12','admin','2012-11-14 09:12:06','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('13','admin','2012-11-14 15:22:11','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('14','admin','2012-11-14 15:50:48','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('15','admin','2012-11-15 10:08:36','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('16','admin','2012-11-15 14:43:26','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('17','admin','2012-11-15 16:21:50','124.254.0.14','0','ad***3','0');");
E_D("replace into `phomelightgx_enewslog` values('18','admin','2012-11-15 16:22:00','124.254.0.14','0','a***3','0');");
E_D("replace into `phomelightgx_enewslog` values('19','admin','2012-11-15 16:22:09','124.254.0.14','1','','0');");

@include("../../inc/footer.php");
?>