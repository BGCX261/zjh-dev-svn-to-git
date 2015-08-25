<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewslog`;");
E_C("CREATE TABLE `phomelightgx_enewslog` (
  `loginid` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(30) NOT NULL DEFAULT '',
  `logintime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `loginip` varchar(20) NOT NULL DEFAULT '',
  `status` tinyint(1) NOT NULL DEFAULT '0',
  `password` varchar(30) NOT NULL DEFAULT '',
  `loginauth` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`loginid`)
) ENGINE=MyISAM AUTO_INCREMENT=60 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewslog` values('1','admin','2012-11-02 14:50:39','123.115.8.52','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('2','admin','2012-11-05 09:08:02','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('3','admin','2012-11-05 15:20:15','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('4','admin','2012-11-06 08:05:54','123.115.8.52','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('5','admin','2012-11-06 10:00:38','123.145.85.75','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('6','admin','2012-11-06 10:08:55','123.115.8.52','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('7','admin','2012-11-07 08:03:49','123.115.8.52','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('8','admin','2012-11-07 16:08:04','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('9','admin','2012-11-08 08:27:50','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('10','admin','2012-11-08 14:14:10','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('11','admin','2012-11-13 15:40:06','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('12','admin','2012-11-14 09:12:06','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('13','admin','2012-11-14 15:22:11','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('14','admin','2012-11-14 15:50:48','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('15','admin','2012-11-15 10:08:36','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('16','admin','2012-11-15 14:43:26','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('17','admin','2012-11-15 16:21:50','124.254.0.14','0','ad***3','0');");
E_D("replace into `phomelightgx_enewslog` values('18','admin','2012-11-15 16:22:00','124.254.0.14','0','a***3','0');");
E_D("replace into `phomelightgx_enewslog` values('19','admin','2012-11-15 16:22:09','124.254.0.14','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('20','admin','2012-11-16 10:42:28','118.186.58.160','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('21','admin','2012-11-19 08:46:09','123.117.3.180','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('22','admin','2012-11-20 13:47:25','114.112.45.188','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('23','admin','2012-12-05 09:47:14','106.3.103.173','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('24','admin','2012-12-05 14:24:57','106.3.103.173','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('25','admin','2012-12-22 10:26:43','118.186.58.209','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('26','lightgx','2012-12-22 10:46:53','114.245.162.111','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('27','lightgx','2012-12-22 10:48:44','114.245.162.111','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('28','lightgx','2012-12-22 10:53:11','114.245.162.111','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('29','lightgx','2012-12-27 21:02:27','114.245.170.145','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('30','lightgx','2012-12-27 21:21:45','114.245.170.145','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('31','lightgx','2012-12-28 10:20:23','114.252.163.204','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('32','lightgx','2012-12-28 11:18:48','114.252.163.204','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('33','admin','2012-12-28 11:23:39','118.186.58.209','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('34','lightgx','2012-12-28 13:39:55','114.252.163.204','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('35','lightgx','2012-12-28 16:46:50','114.252.163.204','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('36','admin','2012-12-28 16:53:16','118.186.58.209','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('37','lightgx','2012-12-29 09:20:01','61.49.240.144','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('38','lightgx','2012-12-29 09:59:24','61.49.240.144','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('39','lightgx','2012-12-29 12:11:32','61.49.240.144','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('40','lightgx','2013-01-04 11:58:02','114.252.181.243','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('41','admin','2013-01-04 13:41:11','106.3.103.170','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('42','lightgx','2013-01-07 09:42:45','114.245.168.202','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('43','admin','2013-01-07 11:11:22','118.186.58.245','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('44','lightgx','2013-01-07 11:14:26','114.245.168.202','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('45','lightgx','2013-01-07 11:29:31','114.245.168.202','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('46','lightgx','2013-01-08 11:40:55','222.130.222.152','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('47','lightgx','2013-01-09 10:44:00','114.252.167.213','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('48','lightgx','2013-01-12 14:45:25','114.252.162.96','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('49','lightgx','2013-01-14 09:57:36','222.130.219.212','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('50','admin','2013-01-15 11:04:45','114.250.68.182','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('51','admin','2013-01-17 13:50:34','114.250.68.182','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('52','lightgx','2013-01-19 10:34:33','114.245.156.100','0','li***3','0');");
E_D("replace into `phomelightgx_enewslog` values('53','lightgx','2013-01-19 10:34:46','114.245.156.100','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('54','lightgx','2013-01-19 10:47:35','114.245.156.100','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('55','lightgx','2013-01-19 14:44:32','114.245.156.100','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('56','lightgx','2013-01-19 14:50:54','114.245.156.100','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('57','lightgx','2013-01-19 15:04:24','114.245.156.100','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('58','admin','2013-01-24 10:13:02','114.250.69.155','1','','0');");
E_D("replace into `phomelightgx_enewslog` values('59','lightgx','2013-01-24 11:10:03','114.252.171.22','1','','0');");

@include("../../inc/footer.php");
?>