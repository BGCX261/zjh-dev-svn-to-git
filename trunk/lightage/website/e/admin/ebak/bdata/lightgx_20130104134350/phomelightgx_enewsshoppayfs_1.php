<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsshoppayfs`;");
E_C("CREATE TABLE `phomelightgx_enewsshoppayfs` (
  `payid` smallint(6) NOT NULL AUTO_INCREMENT,
  `payname` varchar(60) NOT NULL DEFAULT '',
  `payurl` varchar(255) NOT NULL DEFAULT '',
  `paysay` text NOT NULL,
  `userpay` tinyint(1) NOT NULL DEFAULT '0',
  `userfen` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`payid`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsshoppayfs` values('1','�������','','��������ַ:******','0','0');");
E_D("replace into `phomelightgx_enewsshoppayfs` values('2','����ת��','','����ת���ʺ�:******','0','0');");
E_D("replace into `phomelightgx_enewsshoppayfs` values('3','����֧��','/e/payapi/ShopPay.php?paytype=alipay','<p>����֧��</p>','0','0');");
E_D("replace into `phomelightgx_enewsshoppayfs` values('4','Ԥ����֧��','','Ԥ����֧��','1','0');");
E_D("replace into `phomelightgx_enewsshoppayfs` values('5','��������(�������տ�)','','��������(�������տ�)˵��','0','0');");
E_D("replace into `phomelightgx_enewsshoppayfs` values('6','��������','','��������','0','1');");

@include("../../inc/footer.php");
?>