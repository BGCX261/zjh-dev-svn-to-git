<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewssearchall_load`;");
E_C("CREATE TABLE `phomelightgx_enewssearchall_load` (
  `lid` smallint(6) NOT NULL AUTO_INCREMENT,
  `tbname` varchar(60) NOT NULL DEFAULT '',
  `titlefield` varchar(30) NOT NULL DEFAULT '',
  `infotextfield` varchar(30) NOT NULL DEFAULT '',
  `smalltextfield` varchar(30) NOT NULL DEFAULT '',
  `loadnum` smallint(6) NOT NULL DEFAULT '0',
  `lasttime` int(11) NOT NULL DEFAULT '0',
  `lastid` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`lid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>