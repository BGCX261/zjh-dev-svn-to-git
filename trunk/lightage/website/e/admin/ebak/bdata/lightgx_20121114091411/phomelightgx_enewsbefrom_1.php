<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsbefrom`;");
E_C("CREATE TABLE `phomelightgx_enewsbefrom` (
  `befromid` smallint(6) NOT NULL auto_increment,
  `sitename` varchar(60) NOT NULL default '',
  `siteurl` varchar(200) NOT NULL default '',
  PRIMARY KEY  (`befromid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>