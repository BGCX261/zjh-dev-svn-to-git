<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_ecms_movie_data_1`;");
E_C("CREATE TABLE `phomelightgx_ecms_movie_data_1` (
  `id` int(11) NOT NULL DEFAULT '0',
  `classid` smallint(6) NOT NULL DEFAULT '0',
  `playdk` varchar(30) NOT NULL DEFAULT '',
  `playtime` varchar(20) NOT NULL DEFAULT '',
  `downpath` mediumtext NOT NULL,
  `onlinepath` mediumtext NOT NULL,
  `playerid` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `classid` (`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>