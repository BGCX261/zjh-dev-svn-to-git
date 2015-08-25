<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewstagsdata`;");
E_C("CREATE TABLE `phomelightgx_enewstagsdata` (
  `tid` int(11) NOT NULL AUTO_INCREMENT,
  `tagid` int(11) NOT NULL DEFAULT '0',
  `classid` smallint(6) NOT NULL DEFAULT '0',
  `id` int(11) NOT NULL DEFAULT '0',
  `newstime` int(10) NOT NULL DEFAULT '0',
  `mid` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`tid`),
  KEY `tagid` (`tagid`),
  KEY `classid` (`classid`),
  KEY `id` (`id`),
  KEY `newstime` (`newstime`),
  KEY `mid` (`mid`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>