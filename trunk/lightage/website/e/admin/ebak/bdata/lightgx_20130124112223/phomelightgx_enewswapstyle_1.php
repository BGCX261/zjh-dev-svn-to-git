<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewswapstyle`;");
E_C("CREATE TABLE `phomelightgx_enewswapstyle` (
  `styleid` smallint(6) NOT NULL AUTO_INCREMENT,
  `stylename` varchar(60) NOT NULL DEFAULT '',
  `path` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`styleid`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewswapstyle` values('1','新闻模板','1');");
E_D("replace into `phomelightgx_enewswapstyle` values('2','分类信息模板','2');");

@include("../../inc/footer.php");
?>