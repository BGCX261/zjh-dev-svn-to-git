<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewstempgroup`;");
E_C("CREATE TABLE `phomelightgx_enewstempgroup` (
  `gid` smallint(6) NOT NULL auto_increment,
  `gname` varchar(60) NOT NULL default '',
  `isdefault` tinyint(1) NOT NULL default '0',
  PRIMARY KEY  (`gid`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewstempgroup` values('1','д╛ходё╟ЕвИ','1');");

@include("../../inc/footer.php");
?>