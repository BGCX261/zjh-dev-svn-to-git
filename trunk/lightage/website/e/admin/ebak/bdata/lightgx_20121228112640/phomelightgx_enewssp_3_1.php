<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewssp_3`;");
E_C("CREATE TABLE `phomelightgx_enewssp_3` (
  `sid` int(11) NOT NULL AUTO_INCREMENT,
  `spid` smallint(6) NOT NULL DEFAULT '0',
  `sptext` mediumtext NOT NULL,
  PRIMARY KEY (`sid`),
  UNIQUE KEY `spid` (`spid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>