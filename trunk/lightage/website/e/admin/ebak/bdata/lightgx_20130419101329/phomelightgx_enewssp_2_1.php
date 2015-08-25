<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewssp_2`;");
E_C("CREATE TABLE `phomelightgx_enewssp_2` (
  `sid` int(11) NOT NULL AUTO_INCREMENT,
  `spid` smallint(6) NOT NULL DEFAULT '0',
  `classid` smallint(6) NOT NULL DEFAULT '0',
  `id` int(11) NOT NULL DEFAULT '0',
  `newstime` int(10) NOT NULL DEFAULT '0',
  PRIMARY KEY (`sid`),
  KEY `spid` (`spid`),
  KEY `newstime` (`newstime`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>