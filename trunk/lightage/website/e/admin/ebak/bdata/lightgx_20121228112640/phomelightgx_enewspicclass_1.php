<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewspicclass`;");
E_C("CREATE TABLE `phomelightgx_enewspicclass` (
  `classid` smallint(6) NOT NULL AUTO_INCREMENT,
  `classname` varchar(60) NOT NULL DEFAULT '',
  PRIMARY KEY (`classid`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewspicclass` values('1','默认图片信息类别');");

@include("../../inc/footer.php");
?>