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
E_D("replace into `phomelightgx_enewsuser` values('1','admin','c270fa5de028b6c6923d68d1acd8e8d7','85V4CgKry2faG2NJBx4d','','1','0','1','0','ct9KN9Pw','30','1358993581','114.250.69.155','','','0','1358401834','114.250.68.182');");
E_D("replace into `phomelightgx_enewsuser` values('2','lightgx','53388536291f1d410a37def839b52638','g8GfQfDgy2DBGF5NKEDe','|','1','0','2','0','bAhBxXrK','26','1358997003','114.252.171.22','','','0','1358579064','114.245.156.100');");

@include("../../inc/footer.php");
?>