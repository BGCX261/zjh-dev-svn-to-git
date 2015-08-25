<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewssp`;");
E_C("CREATE TABLE `phomelightgx_enewssp` (
  `spid` smallint(6) NOT NULL AUTO_INCREMENT,
  `spname` varchar(30) NOT NULL DEFAULT '',
  `varname` varchar(30) NOT NULL DEFAULT '',
  `sppic` varchar(255) NOT NULL DEFAULT '',
  `spsay` varchar(255) NOT NULL DEFAULT '',
  `sptype` tinyint(1) NOT NULL DEFAULT '0',
  `cid` smallint(6) NOT NULL DEFAULT '0',
  `classid` smallint(6) NOT NULL DEFAULT '0',
  `tempid` smallint(6) NOT NULL DEFAULT '0',
  `maxnum` int(11) NOT NULL DEFAULT '0',
  `sptime` int(10) NOT NULL DEFAULT '0',
  `groupid` text NOT NULL,
  `userclass` text NOT NULL,
  `username` text NOT NULL,
  `isclose` tinyint(1) NOT NULL DEFAULT '0',
  `cladd` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`spid`),
  UNIQUE KEY `varname` (`varname`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>