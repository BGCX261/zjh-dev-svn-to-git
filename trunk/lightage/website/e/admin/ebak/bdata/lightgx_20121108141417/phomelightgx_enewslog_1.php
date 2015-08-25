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
) ENGINE=MyISAM AUTO_INCREMENT=11 DEFAULT CHARSET=gbk");
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

@include("../../inc/footer.php");
?>