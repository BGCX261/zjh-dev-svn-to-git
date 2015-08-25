<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_ecms_infoclass_flash`;");
E_C("CREATE TABLE `phomelightgx_ecms_infoclass_flash` (
  `classid` int(11) NOT NULL DEFAULT '0',
  `zz_title` text NOT NULL,
  `z_title` varchar(255) NOT NULL DEFAULT '',
  `qz_title` varchar(255) NOT NULL DEFAULT '',
  `save_title` varchar(10) NOT NULL DEFAULT '',
  `zz_titlepic` text NOT NULL,
  `z_titlepic` varchar(255) NOT NULL DEFAULT '',
  `qz_titlepic` varchar(255) NOT NULL DEFAULT '',
  `save_titlepic` varchar(10) NOT NULL DEFAULT '',
  `zz_newstime` text NOT NULL,
  `z_newstime` varchar(255) NOT NULL DEFAULT '',
  `qz_newstime` varchar(255) NOT NULL DEFAULT '',
  `save_newstime` varchar(10) NOT NULL DEFAULT '',
  `zz_flashwriter` text NOT NULL,
  `z_flashwriter` varchar(255) NOT NULL DEFAULT '',
  `qz_flashwriter` text NOT NULL,
  `save_flashwriter` varchar(10) NOT NULL DEFAULT '',
  `zz_email` text NOT NULL,
  `z_email` varchar(255) NOT NULL DEFAULT '',
  `qz_email` text NOT NULL,
  `save_email` varchar(10) NOT NULL DEFAULT '',
  `zz_star` text NOT NULL,
  `z_star` varchar(255) NOT NULL DEFAULT '',
  `qz_star` text NOT NULL,
  `save_star` varchar(10) NOT NULL DEFAULT '',
  `zz_filesize` text NOT NULL,
  `z_filesize` varchar(255) NOT NULL DEFAULT '',
  `qz_filesize` text NOT NULL,
  `save_filesize` varchar(10) NOT NULL DEFAULT '',
  `zz_flashurl` text NOT NULL,
  `z_flashurl` varchar(255) NOT NULL DEFAULT '',
  `qz_flashurl` text NOT NULL,
  `save_flashurl` varchar(10) NOT NULL DEFAULT '',
  `zz_width` text NOT NULL,
  `z_width` varchar(255) NOT NULL DEFAULT '',
  `qz_width` text NOT NULL,
  `save_width` varchar(10) NOT NULL DEFAULT '',
  `zz_height` text NOT NULL,
  `z_height` varchar(255) NOT NULL DEFAULT '',
  `qz_height` text NOT NULL,
  `save_height` varchar(10) NOT NULL DEFAULT '',
  `zz_flashsay` text NOT NULL,
  `z_flashsay` varchar(255) NOT NULL DEFAULT '',
  `qz_flashsay` text NOT NULL,
  `save_flashsay` varchar(10) NOT NULL DEFAULT '',
  KEY `classid` (`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>