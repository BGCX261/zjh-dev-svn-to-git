<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsbqclass`;");
E_C("CREATE TABLE `phomelightgx_enewsbqclass` (
  `classid` smallint(6) NOT NULL auto_increment,
  `classname` varchar(30) NOT NULL default '',
  PRIMARY KEY  (`classid`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsbqclass` values('1','信息调用');");
E_D("replace into `phomelightgx_enewsbqclass` values('2','栏目调用');");
E_D("replace into `phomelightgx_enewsbqclass` values('3','非信息调用');");
E_D("replace into `phomelightgx_enewsbqclass` values('4','其它标签');");

@include("../../inc/footer.php");
?>