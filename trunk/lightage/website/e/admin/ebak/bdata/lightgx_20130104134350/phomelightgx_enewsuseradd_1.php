<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsuseradd`;");
E_C("CREATE TABLE `phomelightgx_enewsuseradd` (
  `userid` int(11) NOT NULL AUTO_INCREMENT,
  `equestion` tinyint(4) NOT NULL DEFAULT '0',
  `eanswer` varchar(32) NOT NULL DEFAULT '',
  PRIMARY KEY (`userid`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsuseradd` values('1','0','');");
E_D("replace into `phomelightgx_enewsuseradd` values('2','0','');");

@include("../../inc/footer.php");
?>