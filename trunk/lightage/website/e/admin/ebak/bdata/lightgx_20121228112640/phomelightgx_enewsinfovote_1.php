<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsinfovote`;");
E_C("CREATE TABLE `phomelightgx_enewsinfovote` (
  `id` int(11) NOT NULL DEFAULT '0',
  `classid` smallint(6) NOT NULL DEFAULT '0',
  `title` varchar(120) NOT NULL DEFAULT '',
  `voteip` mediumtext NOT NULL,
  `votetext` text NOT NULL,
  `voteclass` tinyint(1) NOT NULL DEFAULT '0',
  `doip` tinyint(1) NOT NULL DEFAULT '0',
  `dotime` date NOT NULL DEFAULT '0000-00-00',
  `tempid` smallint(6) NOT NULL DEFAULT '0',
  `width` int(11) NOT NULL DEFAULT '0',
  `height` int(11) NOT NULL DEFAULT '0',
  `diyotherlink` tinyint(1) NOT NULL DEFAULT '0',
  `infouptime` int(10) NOT NULL DEFAULT '0',
  `infodowntime` int(10) NOT NULL DEFAULT '0',
  KEY `id` (`id`,`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>