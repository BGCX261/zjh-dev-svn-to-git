<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsgfenip`;");
E_C("CREATE TABLE `phomelightgx_enewsgfenip` (
  `ip` varchar(20) NOT NULL DEFAULT '',
  `addtime` int(11) NOT NULL DEFAULT '0',
  UNIQUE KEY `ip` (`ip`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>