<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewslinkclass`;");
E_C("CREATE TABLE `phomelightgx_enewslinkclass` (
  `classid` smallint(6) NOT NULL auto_increment,
  `classname` varchar(30) NOT NULL default '',
  PRIMARY KEY  (`classid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>