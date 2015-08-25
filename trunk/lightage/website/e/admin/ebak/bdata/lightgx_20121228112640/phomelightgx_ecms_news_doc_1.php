<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_ecms_news_doc`;");
E_C("CREATE TABLE `phomelightgx_ecms_news_doc` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `classid` smallint(6) NOT NULL DEFAULT '0',
  `onclick` int(11) NOT NULL DEFAULT '0',
  `newspath` char(20) NOT NULL DEFAULT '',
  `keyboard` char(160) NOT NULL DEFAULT '',
  `keyid` char(255) NOT NULL DEFAULT '',
  `userid` int(11) NOT NULL DEFAULT '0',
  `username` char(30) NOT NULL DEFAULT '',
  `ztid` char(255) NOT NULL DEFAULT '',
  `checked` tinyint(1) NOT NULL DEFAULT '0',
  `istop` tinyint(1) NOT NULL DEFAULT '0',
  `truetime` int(10) NOT NULL DEFAULT '0',
  `ismember` tinyint(1) NOT NULL DEFAULT '0',
  `dokey` tinyint(1) NOT NULL DEFAULT '0',
  `userfen` smallint(6) NOT NULL DEFAULT '0',
  `isgood` tinyint(1) NOT NULL DEFAULT '0',
  `titlefont` char(20) NOT NULL DEFAULT '',
  `titleurl` char(200) NOT NULL DEFAULT '',
  `filename` char(60) NOT NULL DEFAULT '',
  `groupid` smallint(6) NOT NULL DEFAULT '0',
  `newstempid` smallint(6) NOT NULL DEFAULT '0',
  `plnum` int(11) NOT NULL DEFAULT '0',
  `firsttitle` tinyint(1) NOT NULL DEFAULT '0',
  `isqf` tinyint(1) NOT NULL DEFAULT '0',
  `totaldown` int(11) NOT NULL DEFAULT '0',
  `title` char(200) NOT NULL DEFAULT '',
  `newstime` int(10) NOT NULL DEFAULT '0',
  `titlepic` char(200) NOT NULL DEFAULT '',
  `closepl` tinyint(1) NOT NULL DEFAULT '0',
  `havehtml` tinyint(1) NOT NULL DEFAULT '0',
  `lastdotime` int(10) NOT NULL DEFAULT '0',
  `haveaddfen` tinyint(1) NOT NULL DEFAULT '0',
  `infopfen` int(11) NOT NULL DEFAULT '0',
  `infopfennum` int(11) NOT NULL DEFAULT '0',
  `votenum` int(11) NOT NULL DEFAULT '0',
  `ftitle` char(120) NOT NULL DEFAULT '',
  `smalltext` char(255) NOT NULL DEFAULT '',
  `diggtop` int(11) NOT NULL DEFAULT '0',
  `stb` char(4) NOT NULL DEFAULT '',
  `copyids` char(255) NOT NULL DEFAULT '',
  `ttid` smallint(6) NOT NULL DEFAULT '0',
  `infotags` char(160) NOT NULL DEFAULT '',
  `ispic` tinyint(1) NOT NULL DEFAULT '0',
  `newstext` mediumtext NOT NULL,
  PRIMARY KEY (`id`),
  KEY `checked` (`checked`),
  KEY `newstime` (`newstime`),
  KEY `truetime` (`truetime`),
  KEY `classid` (`classid`),
  KEY `ttid` (`ttid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>