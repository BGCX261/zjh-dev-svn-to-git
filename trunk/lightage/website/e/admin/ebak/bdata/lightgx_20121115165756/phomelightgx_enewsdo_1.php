<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsdo`;");
E_C("CREATE TABLE `phomelightgx_enewsdo` (
  `doid` smallint(6) NOT NULL auto_increment,
  `doname` varchar(60) NOT NULL default '',
  `dotime` smallint(6) NOT NULL default '0',
  `isopen` tinyint(1) NOT NULL default '0',
  `doing` tinyint(4) NOT NULL default '0',
  `classid` text NOT NULL,
  `lasttime` int(11) NOT NULL default '0',
  PRIMARY KEY  (`doid`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsdo` values('1','�Զ�ˢ����ҳ','12','0','0',',','1273215883');");

@include("../../inc/footer.php");
?>