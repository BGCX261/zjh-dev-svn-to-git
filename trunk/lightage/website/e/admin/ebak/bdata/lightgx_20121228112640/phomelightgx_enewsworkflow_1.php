<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsworkflow`;");
E_C("CREATE TABLE `phomelightgx_enewsworkflow` (
  `wfid` smallint(6) NOT NULL AUTO_INCREMENT,
  `wfname` varchar(60) NOT NULL DEFAULT '',
  `wftext` varchar(255) NOT NULL DEFAULT '',
  `myorder` smallint(6) NOT NULL DEFAULT '0',
  `addtime` int(11) NOT NULL DEFAULT '0',
  `adduser` varchar(30) NOT NULL DEFAULT '',
  PRIMARY KEY (`wfid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>