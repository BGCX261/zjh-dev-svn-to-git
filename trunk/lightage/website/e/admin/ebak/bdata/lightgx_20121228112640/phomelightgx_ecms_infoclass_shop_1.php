<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_ecms_infoclass_shop`;");
E_C("CREATE TABLE `phomelightgx_ecms_infoclass_shop` (
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
  `zz_productno` text NOT NULL,
  `z_productno` varchar(255) NOT NULL DEFAULT '',
  `qz_productno` text NOT NULL,
  `save_productno` varchar(10) NOT NULL DEFAULT '',
  `zz_pbrand` text NOT NULL,
  `z_pbrand` varchar(255) NOT NULL DEFAULT '',
  `qz_pbrand` text NOT NULL,
  `save_pbrand` varchar(10) NOT NULL DEFAULT '',
  `zz_intro` text NOT NULL,
  `z_intro` varchar(255) NOT NULL DEFAULT '',
  `qz_intro` text NOT NULL,
  `save_intro` varchar(10) NOT NULL DEFAULT '',
  `zz_unit` text NOT NULL,
  `z_unit` varchar(255) NOT NULL DEFAULT '',
  `qz_unit` text NOT NULL,
  `save_unit` varchar(10) NOT NULL DEFAULT '',
  `zz_weight` text NOT NULL,
  `z_weight` varchar(255) NOT NULL DEFAULT '',
  `qz_weight` text NOT NULL,
  `save_weight` varchar(10) NOT NULL DEFAULT '',
  `zz_tprice` text NOT NULL,
  `z_tprice` varchar(255) NOT NULL DEFAULT '',
  `qz_tprice` text NOT NULL,
  `save_tprice` varchar(10) NOT NULL DEFAULT '',
  `zz_price` text NOT NULL,
  `z_price` varchar(255) NOT NULL DEFAULT '',
  `qz_price` text NOT NULL,
  `save_price` varchar(10) NOT NULL DEFAULT '',
  `zz_buyfen` text NOT NULL,
  `z_buyfen` varchar(255) NOT NULL DEFAULT '',
  `qz_buyfen` text NOT NULL,
  `save_buyfen` varchar(10) NOT NULL DEFAULT '',
  `zz_pmaxnum` text NOT NULL,
  `z_pmaxnum` varchar(255) NOT NULL DEFAULT '',
  `qz_pmaxnum` text NOT NULL,
  `save_pmaxnum` varchar(10) NOT NULL DEFAULT '',
  `zz_productpic` text NOT NULL,
  `z_productpic` varchar(255) NOT NULL DEFAULT '',
  `qz_productpic` text NOT NULL,
  `save_productpic` varchar(10) NOT NULL DEFAULT '',
  `zz_newstext` text NOT NULL,
  `z_newstext` varchar(255) NOT NULL DEFAULT '',
  `qz_newstext` text NOT NULL,
  `save_newstext` varchar(10) NOT NULL DEFAULT '',
  KEY `classid` (`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>