<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsuserjs`;");
E_C("CREATE TABLE `phomelightgx_enewsuserjs` (
  `jsid` smallint(6) NOT NULL AUTO_INCREMENT,
  `jsname` varchar(60) NOT NULL DEFAULT '',
  `jssql` text NOT NULL,
  `jstempid` smallint(6) NOT NULL DEFAULT '0',
  `jsfilename` varchar(120) NOT NULL DEFAULT '',
  PRIMARY KEY (`jsid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>