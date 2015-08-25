<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewssql`;");
E_C("CREATE TABLE `phomelightgx_enewssql` (
  `id` smallint(6) NOT NULL AUTO_INCREMENT,
  `sqlname` varchar(60) NOT NULL DEFAULT '',
  `sqltext` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>