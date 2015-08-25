<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewscard`;");
E_C("CREATE TABLE `phomelightgx_enewscard` (
  `cardid` int(11) NOT NULL AUTO_INCREMENT,
  `card_no` varchar(30) NOT NULL DEFAULT '',
  `password` varchar(20) NOT NULL DEFAULT '',
  `money` int(11) NOT NULL DEFAULT '0',
  `cardfen` int(11) NOT NULL DEFAULT '0',
  `endtime` date NOT NULL DEFAULT '0000-00-00',
  `cardtime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `carddate` int(11) NOT NULL DEFAULT '0',
  `cdgroupid` smallint(6) NOT NULL DEFAULT '0',
  `cdzgroupid` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`cardid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>