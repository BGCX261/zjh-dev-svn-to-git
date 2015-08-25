<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsbuybak`;");
E_C("CREATE TABLE `phomelightgx_enewsbuybak` (
  `username` varchar(30) NOT NULL DEFAULT '',
  `card_no` varchar(255) NOT NULL DEFAULT '',
  `buytime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `cardfen` int(11) NOT NULL DEFAULT '0',
  `money` int(11) NOT NULL DEFAULT '0',
  `userid` int(11) NOT NULL DEFAULT '0',
  `userdate` int(11) NOT NULL DEFAULT '0',
  `type` tinyint(1) NOT NULL DEFAULT '0',
  KEY `userid` (`userid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>