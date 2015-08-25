<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsuseradd`;");
E_C("CREATE TABLE `phomelightgx_enewsuseradd` (
  `userid` int(11) NOT NULL auto_increment,
  `equestion` tinyint(4) NOT NULL default '0',
  `eanswer` varchar(32) NOT NULL default '',
  PRIMARY KEY  (`userid`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsuseradd` values('1','0','');");

@include("../../inc/footer.php");
?>