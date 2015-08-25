<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsdo`;");
E_C("CREATE TABLE `phomelightgx_enewsdo` (
  `doid` smallint(6) NOT NULL AUTO_INCREMENT,
  `doname` varchar(60) NOT NULL DEFAULT '',
  `dotime` smallint(6) NOT NULL DEFAULT '0',
  `isopen` tinyint(1) NOT NULL DEFAULT '0',
  `doing` tinyint(4) NOT NULL DEFAULT '0',
  `classid` text NOT NULL,
  `lasttime` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`doid`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsdo` values('1','自动刷新首页','12','0','0',',','1273215883');");

@include("../../inc/footer.php");
?>