<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_ecms_infotmp_movie`;");
E_C("CREATE TABLE `phomelightgx_ecms_infotmp_movie` (
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
  `movietype` varchar(16) NOT NULL DEFAULT '',
  `company` varchar(200) NOT NULL DEFAULT '',
  `movietime` varchar(20) NOT NULL DEFAULT '',
  `player` varchar(255) NOT NULL DEFAULT '',
  `playadmin` varchar(255) NOT NULL DEFAULT '',
  `filetype` varchar(10) NOT NULL DEFAULT '',
  `filesize` varchar(16) NOT NULL DEFAULT '',
  `star` tinyint(1) NOT NULL DEFAULT '0',
  `playdk` varchar(30) NOT NULL DEFAULT '',
  `playtime` varchar(20) NOT NULL DEFAULT '',
  `moviefen` int(11) NOT NULL DEFAULT '0',
  `downpath` mediumtext NOT NULL,
  `onlinepath` mediumtext NOT NULL,
  `moviesay` text NOT NULL,
  `playerid` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `classid` (`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>