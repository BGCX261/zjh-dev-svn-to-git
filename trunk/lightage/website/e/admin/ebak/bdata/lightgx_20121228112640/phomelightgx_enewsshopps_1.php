<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsshopps`;");
E_C("CREATE TABLE `phomelightgx_enewsshopps` (
  `pid` int(11) NOT NULL AUTO_INCREMENT,
  `pname` varchar(60) NOT NULL DEFAULT '',
  `price` float(11,2) NOT NULL DEFAULT '0.00',
  `otherprice` text NOT NULL,
  `psay` text NOT NULL,
  PRIMARY KEY (`pid`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsshopps` values('1','�ͻ�����','10.00','','�ͻ�����');");
E_D("replace into `phomelightgx_enewsshopps` values('2','�ؿ�ר�ݣ�EMS��','25.00','','�ؿ�ר�ݣ�EMS��');");
E_D("replace into `phomelightgx_enewsshopps` values('3','��ͨ�ʵ�','5.00','','��ͨ�ʵ�');");
E_D("replace into `phomelightgx_enewsshopps` values('4','�ʾֿ���','12.00','','�ʾֿ���');");

@include("../../inc/footer.php");
?>