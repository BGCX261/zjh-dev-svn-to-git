<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsbuygroup`;");
E_C("CREATE TABLE `phomelightgx_enewsbuygroup` (
  `id` smallint(6) NOT NULL AUTO_INCREMENT,
  `gname` varchar(255) NOT NULL DEFAULT '',
  `gmoney` int(11) NOT NULL DEFAULT '0',
  `gfen` int(11) NOT NULL DEFAULT '0',
  `gdate` int(11) NOT NULL DEFAULT '0',
  `ggroupid` smallint(6) NOT NULL DEFAULT '0',
  `gzgroupid` smallint(6) NOT NULL DEFAULT '0',
  `buygroupid` smallint(6) NOT NULL DEFAULT '0',
  `gsay` text NOT NULL,
  `myorder` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=gbk");

@include("../../inc/footer.php");
?>