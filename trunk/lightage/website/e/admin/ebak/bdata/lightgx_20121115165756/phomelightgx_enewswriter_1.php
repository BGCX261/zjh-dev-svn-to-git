<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewswriter`;");
E_C("CREATE TABLE `phomelightgx_enewswriter` (
  `wid` smallint(6) NOT NULL auto_increment,
  `writer` varchar(30) NOT NULL default '',
  `email` varchar(120) NOT NULL default '',
  PRIMARY KEY  (`wid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>