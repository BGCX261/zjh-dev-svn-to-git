<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsuser`;");
E_C("CREATE TABLE `phomelightgx_enewsuser` (
  `userid` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(30) NOT NULL DEFAULT '',
  `password` varchar(32) NOT NULL DEFAULT '',
  `rnd` varchar(20) NOT NULL DEFAULT '',
  `adminclass` mediumtext NOT NULL,
  `groupid` smallint(6) NOT NULL DEFAULT '0',
  `checked` tinyint(1) NOT NULL DEFAULT '0',
  `styleid` smallint(6) NOT NULL DEFAULT '0',
  `filelevel` tinyint(1) NOT NULL DEFAULT '0',
  `salt` varchar(8) NOT NULL DEFAULT '',
  `loginnum` int(11) NOT NULL DEFAULT '0',
  `lasttime` int(11) NOT NULL DEFAULT '0',
  `lastip` varchar(20) NOT NULL DEFAULT '',
  `truename` varchar(20) NOT NULL DEFAULT '',
  `email` varchar(120) NOT NULL DEFAULT '',
  `classid` smallint(6) NOT NULL DEFAULT '0',
  `pretime` int(11) NOT NULL DEFAULT '0',
  `preip` varchar(20) NOT NULL DEFAULT '',
  PRIMARY KEY (`userid`),
  UNIQUE KEY `username` (`username`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsuser` values('1','admin','c270fa5de028b6c6923d68d1acd8e8d7','UBhi6kuS8xnJ4fRySRim','','1','0','1','0','ct9KN9Pw','26','1357278071','106.3.103.170','','','0','1356684796','118.186.58.209');");
E_D("replace into `phomelightgx_enewsuser` values('2','lightgx','53388536291f1d410a37def839b52638','5xAPjc4prQTpyTqq2z89','|','1','0','2','0','bAhBxXrK','13','1357271882','114.252.181.243','','','0','1356754292','61.49.240.144');");

@include("../../inc/footer.php");
?>