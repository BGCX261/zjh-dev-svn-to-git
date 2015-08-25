<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsshopdd`;");
E_C("CREATE TABLE `phomelightgx_enewsshopdd` (
  `ddid` bigint(20) NOT NULL AUTO_INCREMENT,
  `ddno` varchar(30) NOT NULL DEFAULT '',
  `ddtime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `userid` int(11) NOT NULL DEFAULT '0',
  `username` varchar(30) NOT NULL DEFAULT '',
  `outproduct` tinyint(1) NOT NULL DEFAULT '0',
  `haveprice` tinyint(1) NOT NULL DEFAULT '0',
  `checked` tinyint(1) NOT NULL DEFAULT '0',
  `truename` varchar(20) NOT NULL DEFAULT '',
  `oicq` varchar(25) NOT NULL DEFAULT '',
  `msn` varchar(120) NOT NULL DEFAULT '',
  `email` varchar(120) NOT NULL DEFAULT '',
  `call` varchar(30) NOT NULL DEFAULT '',
  `phone` varchar(30) NOT NULL DEFAULT '',
  `address` varchar(255) NOT NULL DEFAULT '',
  `zip` varchar(8) NOT NULL DEFAULT '',
  `bz` text NOT NULL,
  `g_truename` varchar(20) NOT NULL DEFAULT '',
  `g_oicq` varchar(25) NOT NULL DEFAULT '',
  `g_msn` varchar(120) NOT NULL DEFAULT '',
  `g_email` varchar(120) NOT NULL DEFAULT '',
  `g_call` varchar(30) NOT NULL DEFAULT '',
  `g_phone` varchar(30) NOT NULL DEFAULT '',
  `g_address` varchar(255) NOT NULL DEFAULT '',
  `g_zip` varchar(8) NOT NULL DEFAULT '',
  `buycar` mediumtext NOT NULL,
  `psid` smallint(6) NOT NULL DEFAULT '0',
  `psname` varchar(60) NOT NULL DEFAULT '',
  `pstotal` float(11,2) NOT NULL DEFAULT '0.00',
  `alltotal` float(11,2) NOT NULL DEFAULT '0.00',
  `payfsid` smallint(6) NOT NULL DEFAULT '0',
  `payfsname` varchar(60) NOT NULL DEFAULT '',
  `payby` tinyint(4) NOT NULL DEFAULT '0',
  `alltotalfen` float(11,2) NOT NULL DEFAULT '0.00',
  `fp` tinyint(1) NOT NULL DEFAULT '0',
  `fptt` varchar(255) NOT NULL DEFAULT '',
  `fptotal` float(11,2) NOT NULL DEFAULT '0.00',
  PRIMARY KEY (`ddid`),
  KEY `ddno` (`ddno`),
  KEY `userid` (`userid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>