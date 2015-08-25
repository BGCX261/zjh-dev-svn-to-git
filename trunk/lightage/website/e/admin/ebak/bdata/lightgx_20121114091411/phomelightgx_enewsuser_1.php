<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsuser`;");
E_C("CREATE TABLE `phomelightgx_enewsuser` (
  `userid` int(11) NOT NULL auto_increment,
  `username` varchar(30) NOT NULL default '',
  `password` varchar(32) NOT NULL default '',
  `rnd` varchar(20) NOT NULL default '',
  `adminclass` mediumtext NOT NULL,
  `groupid` smallint(6) NOT NULL default '0',
  `checked` tinyint(1) NOT NULL default '0',
  `styleid` smallint(6) NOT NULL default '0',
  `filelevel` tinyint(1) NOT NULL default '0',
  `salt` varchar(8) NOT NULL default '',
  `loginnum` int(11) NOT NULL default '0',
  `lasttime` int(11) NOT NULL default '0',
  `lastip` varchar(20) NOT NULL default '',
  `truename` varchar(20) NOT NULL default '',
  `email` varchar(120) NOT NULL default '',
  `classid` smallint(6) NOT NULL default '0',
  `pretime` int(11) NOT NULL default '0',
  `preip` varchar(20) NOT NULL default '',
  PRIMARY KEY  (`userid`),
  UNIQUE KEY `username` (`username`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsuser` values('1','admin','c270fa5de028b6c6923d68d1acd8e8d7','BTa79nrFHM3QVwxJJrYs','','1','0','1','0','ct9KN9Pw','12','1352855525','124.254.0.14','','','0','1352792406','124.254.0.14');");

@include("../../inc/footer.php");
?>