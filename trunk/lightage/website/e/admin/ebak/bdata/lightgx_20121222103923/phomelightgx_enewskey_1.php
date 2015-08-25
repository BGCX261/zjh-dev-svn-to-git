<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewskey`;");
E_C("CREATE TABLE `phomelightgx_enewskey` (
  `keyid` smallint(6) NOT NULL AUTO_INCREMENT,
  `keyname` varchar(60) NOT NULL DEFAULT '',
  `keyurl` varchar(200) NOT NULL DEFAULT '',
  PRIMARY KEY (`keyid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>