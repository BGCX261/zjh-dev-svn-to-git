<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewstagsclass`;");
E_C("CREATE TABLE `phomelightgx_enewstagsclass` (
  `classid` smallint(6) NOT NULL AUTO_INCREMENT,
  `classname` varchar(60) NOT NULL DEFAULT '',
  PRIMARY KEY (`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>