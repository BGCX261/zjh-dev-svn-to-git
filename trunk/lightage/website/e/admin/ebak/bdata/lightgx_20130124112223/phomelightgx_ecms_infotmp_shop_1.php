<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_ecms_infotmp_shop`;");
E_C("CREATE TABLE `phomelightgx_ecms_infotmp_shop` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `classid` int(11) NOT NULL DEFAULT '0',
  `oldurl` varchar(255) NOT NULL DEFAULT '',
  `checked` tinyint(1) NOT NULL DEFAULT '0',
  `tmptime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `title` varchar(200) NOT NULL DEFAULT '',
  `newstime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `username` varchar(30) NOT NULL DEFAULT '',
  `userid` int(11) NOT NULL DEFAULT '0',
  `truetime` int(11) NOT NULL DEFAULT '0',
  `keyboard` varchar(255) NOT NULL DEFAULT '',
  `titlepic` varchar(200) NOT NULL DEFAULT '',
  `productno` varchar(30) NOT NULL DEFAULT '',
  `pbrand` varchar(30) NOT NULL DEFAULT '',
  `intro` text NOT NULL,
  `unit` varchar(16) NOT NULL DEFAULT '',
  `weight` varchar(20) NOT NULL DEFAULT '',
  `tprice` float(11,2) NOT NULL DEFAULT '0.00',
  `price` float(11,2) NOT NULL DEFAULT '0.00',
  `buyfen` int(11) NOT NULL DEFAULT '0',
  `pmaxnum` int(11) NOT NULL DEFAULT '0',
  `productpic` varchar(255) NOT NULL DEFAULT '',
  `newstext` mediumtext NOT NULL,
  PRIMARY KEY (`id`),
  KEY `classid` (`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>