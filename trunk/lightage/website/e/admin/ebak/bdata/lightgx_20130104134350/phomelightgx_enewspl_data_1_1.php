<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewspl_data_1`;");
E_C("CREATE TABLE `phomelightgx_enewspl_data_1` (
  `plid` int(11) NOT NULL AUTO_INCREMENT,
  `classid` smallint(6) NOT NULL DEFAULT '0',
  `id` int(11) NOT NULL DEFAULT '0',
  `saytext` text NOT NULL,
  PRIMARY KEY (`plid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>