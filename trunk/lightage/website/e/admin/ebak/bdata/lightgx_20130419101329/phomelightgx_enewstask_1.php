<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewstask`;");
E_C("CREATE TABLE `phomelightgx_enewstask` (
  `id` smallint(6) NOT NULL AUTO_INCREMENT,
  `taskname` varchar(60) NOT NULL DEFAULT '',
  `userid` int(11) NOT NULL DEFAULT '0',
  `isopen` tinyint(1) NOT NULL DEFAULT '0',
  `filename` varchar(60) NOT NULL DEFAULT '',
  `lastdo` int(11) NOT NULL DEFAULT '0',
  `doweek` char(1) NOT NULL DEFAULT '0',
  `doday` char(2) NOT NULL DEFAULT '0',
  `dohour` char(2) NOT NULL DEFAULT '0',
  `dominute` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>