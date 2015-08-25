<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_enewsfile`;");
E_C("CREATE TABLE `phomelightgx_enewsfile` (
  `fileid` int(11) NOT NULL AUTO_INCREMENT,
  `filename` varchar(60) NOT NULL DEFAULT '',
  `filesize` int(11) NOT NULL DEFAULT '0',
  `path` varchar(20) NOT NULL DEFAULT '',
  `adduser` varchar(30) NOT NULL DEFAULT '',
  `filetime` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `classid` smallint(6) NOT NULL DEFAULT '0',
  `no` varchar(60) NOT NULL DEFAULT '',
  `type` tinyint(4) NOT NULL DEFAULT '0',
  `onclick` int(11) NOT NULL DEFAULT '0',
  `id` bigint(20) NOT NULL DEFAULT '0',
  `cjid` bigint(20) NOT NULL DEFAULT '0',
  `fpath` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`fileid`),
  KEY `id` (`id`),
  KEY `type` (`type`),
  KEY `classid` (`classid`)
) ENGINE=MyISAM AUTO_INCREMENT=38 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_enewsfile` values('2','ad75199ddd759b3d5c3eff02b39bf70f.jpg','239500','2012-11-05','admin','2012-11-05 09:52:47','1','1.jpg','1','0','1','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('3','7cd97f0740881e226ed946f94f047b80.jpg','108275','2012-11-05','admin','2012-11-05 09:53:05','1','2.jpg','1','0','2','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('4','1f03bc0f51c1f4b7665db98de16556d9.jpg','98074','2012-11-06','admin','2012-11-06 09:41:13','16','盗墓-t.jpg','1','0','3','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('5','93e3d98beab1831a51f1fb13cfdec56d.jpg','294699','2012-11-06','admin','2012-11-06 09:41:56','16','盗墓21.jpg','1','0','3','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('6','0363bbaf551e0fe0dd16c22fe8fdf3e2.jpg','86325','2012-11-06','admin','2012-11-06 09:42:30','16','盗墓笔记-t.jpg','1','0','4','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('7','25fd7c7a2a81f3e99ea2cf9664738ecf.jpg','251177','2012-11-06','admin','2012-11-06 09:42:43','16','盗墓笔记24.jpg','1','0','4','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('8','8ab5b392f9985eb812d0889da2c6dc4e.jpg','54786','2012-11-06','admin','2012-11-06 10:13:10','16','盗墓加长-t.jpg','1','0','5','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('9','5938888c0b2c4e25de23725e17249448.jpg','142715','2012-11-06','admin','2012-11-06 10:13:29','16','盗墓加长8.jpg','1','0','5','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('10','07fc4af827a4118296c227e1767a00ab.jpg','80623','2012-11-06','admin','2012-11-06 10:59:11','16','洞口色彩-t.jpg','1','0','6','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('11','4beff731232c208341ac814464cc7360.jpg','250485','2012-11-06','admin','2012-11-06 10:59:34','16','洞口色彩16.jpg','1','0','6','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('12','e4eb3052df04e4bdc32d89b864416684.jpg','52270','2012-11-06','admin','2012-11-06 10:59:56','16','风雨夜归人-t.jpg','1','0','7','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('13','e85971b3b76c52b877cb383d676c80b7.jpg','142438','2012-11-06','admin','2012-11-06 11:00:08','16','风雨夜归人12副本.jpg','1','0','7','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('14','d07a8771711aa6c22237a471b98332ad.jpg','51458','2012-11-06','admin','2012-11-06 11:00:28','16','攻城-t.jpg','1','0','8','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('15','6587354abd33a99519c523e7ea583818.jpg','131686','2012-11-06','admin','2012-11-06 11:00:41','16','攻城12.jpg','1','0','8','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('16','2f64c5228b464a5066cf5f6c6d7aa664.jpg','150937','2012-11-06','admin','2012-11-06 17:59:08','6','image001.jpg','1','0','12','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('17','496db5bd9dcb6637d859b4431b530304.jpg','506171','2012-11-07','admin','2012-11-07 09:22:13','16','黑树林-t.jpg','1','0','13','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('18','5f320457a4d329e76ed638853c4e1009.jpg','749788','2012-11-07','admin','2012-11-07 09:22:45','16','黑树林10副本.jpg','1','0','13','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('19','7cee3a543cd2bb7c395e87609c1ac2bb.jpg','225023','2012-11-07','admin','2012-11-07 10:08:47','16','盗墓21.jpg','1','0','3','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('20','106fd7a8d5a62861cb78aa2abf03a56e.jpg','178300','2012-11-07','admin','2012-11-07 10:09:33','16','盗墓笔记24.jpg','1','0','4','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('21','2f4ec45449e06c39f4f388da9d6c3d01.jpg','136632','2012-11-07','admin','2012-11-07 10:10:03','16','盗墓加长8.jpg','1','0','5','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('22','353655c364bd11f024b7979d80af68cd.jpg','215017','2012-11-07','admin','2012-11-07 10:10:34','16','洞口色彩16.jpg','1','0','6','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('23','fe3c7fe9f2552f858672dd778653f705.jpg','527084','2012-11-07','admin','2012-11-07 10:12:01','16','风雨夜归人12副本.jpg','1','0','7','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('24','32e061db393a1588d265ffe7aa3841dd.jpg','418951','2012-11-07','admin','2012-11-07 10:13:02','16','攻城12.jpg','1','0','8','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('25','27d5557c52b3db91de11d76d87b8e1d0.jpg','61884','2012-11-07','admin','2012-11-07 10:14:49','16','秦岭神树棕色-t.jpg','1','0','14','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('26','c8758e83f41daecba893a814f3ca94bc.jpg','116763','2012-11-07','admin','2012-11-07 10:15:07','16','秦岭神树棕色3.jpg','1','0','14','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('27','9b4354f93b585200411f340a12d7a6f7.jpg','92566','2012-11-07','admin','2012-11-07 10:15:57','16','山城-t.jpg','1','0','15','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('28','b31703b978f2cdf1c7088fe917a46ae8.jpg','849638','2012-11-07','admin','2012-11-07 10:16:22','16','山城9副本.jpg','1','0','15','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('29','b2bc7ae040cfb50394e955b6bfd8ace2.jpg','60203','2012-11-07','admin','2012-11-07 10:23:44','16','雪山-t.jpg','1','0','16','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('30','555fe1dca5c0600127e8094e42680b4f.jpg','435089','2012-11-07','admin','2012-11-07 10:24:00','16','雪山9副本.jpg','1','0','16','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('31','bc78cc637fb4e66bd1e95a5de3def0db.jpg','48271','2012-11-07','admin','2012-11-07 10:24:46','16','夜游神-t.jpg','1','0','17','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('32','15070cd987ad7dfc118a37b051d28e62.jpg','50180','2012-11-07','admin','2012-11-07 10:24:56','16','夜游神8副本.jpg','1','0','17','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('34','f0bdd78b7d349edf2ef164caac401590.jpg','70846','2012-11-07','admin','2012-11-07 10:26:21','16','正午阳光-t.jpg','1','0','18','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('35','304aae7559c46237ba8b39bee66a8792.jpg','737960','2012-11-07','admin','2012-11-07 10:26:44','16','正午阳光12副本.jpg','1','0','18','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('36','fa0e1135a3ec2d9c240a0991a3111ca2.jpg','87469','2012-11-14','admin','2012-11-14 15:52:08','2','Image1.jpg','1','0','9','0','0');");
E_D("replace into `phomelightgx_enewsfile` values('37','951dd0cc1ec8a43fc65f3358d71d8b33.jpg','143195','2012-11-15','admin','2012-11-15 16:46:01','2','拼图3.jpg','1','0','9','0','0');");

@include("../../inc/footer.php");
?>