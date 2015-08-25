<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewssql`;");
E_C("CREATE TABLE `phomelightgx_enewssql` (
  `id` smallint(6) NOT NULL auto_increment,
  `sqlname` varchar(60) NOT NULL default '',
  `sqltext` text NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>