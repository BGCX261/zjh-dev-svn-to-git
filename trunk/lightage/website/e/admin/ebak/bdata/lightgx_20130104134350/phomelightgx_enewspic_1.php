<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewspic`;");
E_C("CREATE TABLE `phomelightgx_enewspic` (
  `picid` smallint(6) NOT NULL AUTO_INCREMENT,
  `title` varchar(120) NOT NULL DEFAULT '',
  `pic_url` varchar(200) NOT NULL DEFAULT '',
  `url` varchar(200) NOT NULL DEFAULT '',
  `pic_width` varchar(20) NOT NULL DEFAULT '',
  `pic_height` varchar(20) NOT NULL DEFAULT '',
  `open_pic` varchar(20) NOT NULL DEFAULT '',
  `border` tinyint(1) NOT NULL DEFAULT '0',
  `pictext` text NOT NULL,
  `classid` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`picid`),
  KEY `classid` (`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>