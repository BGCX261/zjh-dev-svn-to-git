<?php
@include("../../inc/header.php");

/*
		SoftName : EmpireBak
		Author   : wm_chief
		Copyright: Powered by www.phome.net
*/

E_D("DROP TABLE IF EXISTS `phomelightgx_ecms_news`;");
E_C("CREATE TABLE `phomelightgx_ecms_news` (
  `id` int(11) NOT NULL auto_increment,
  `classid` smallint(6) NOT NULL default '0',
  `onclick` int(11) NOT NULL default '0',
  `newspath` char(20) NOT NULL default '',
  `keyboard` char(160) NOT NULL default '',
  `keyid` char(255) NOT NULL default '',
  `userid` int(11) NOT NULL default '0',
  `username` char(30) NOT NULL default '',
  `ztid` char(255) NOT NULL default '',
  `checked` tinyint(1) NOT NULL default '0',
  `istop` tinyint(1) NOT NULL default '0',
  `truetime` int(10) NOT NULL default '0',
  `ismember` tinyint(1) NOT NULL default '0',
  `dokey` tinyint(1) NOT NULL default '0',
  `userfen` smallint(6) NOT NULL default '0',
  `isgood` tinyint(1) NOT NULL default '0',
  `titlefont` char(20) NOT NULL default '',
  `titleurl` char(200) NOT NULL default '',
  `filename` char(60) NOT NULL default '',
  `groupid` smallint(6) NOT NULL default '0',
  `newstempid` smallint(6) NOT NULL default '0',
  `plnum` int(11) NOT NULL default '0',
  `firsttitle` tinyint(1) NOT NULL default '0',
  `isqf` tinyint(1) NOT NULL default '0',
  `totaldown` int(11) NOT NULL default '0',
  `title` char(200) NOT NULL default '',
  `newstime` int(10) NOT NULL default '0',
  `titlepic` char(200) NOT NULL default '',
  `closepl` tinyint(1) NOT NULL default '0',
  `havehtml` tinyint(1) NOT NULL default '0',
  `lastdotime` int(10) NOT NULL default '0',
  `haveaddfen` tinyint(1) NOT NULL default '0',
  `infopfen` int(11) NOT NULL default '0',
  `infopfennum` int(11) NOT NULL default '0',
  `votenum` int(11) NOT NULL default '0',
  `ftitle` char(120) NOT NULL default '',
  `smalltext` char(255) NOT NULL default '',
  `diggtop` int(11) NOT NULL default '0',
  `stb` char(4) NOT NULL default '',
  `copyids` char(255) NOT NULL default '',
  `ttid` smallint(6) NOT NULL default '0',
  `infotags` char(160) NOT NULL default '',
  `ispic` tinyint(1) NOT NULL default '0',
  `newstext` mediumtext NOT NULL,
  PRIMARY KEY  (`id`),
  KEY `checked` (`checked`),
  KEY `newstime` (`newstime`),
  KEY `truetime` (`truetime`),
  KEY `classid` (`classid`),
  KEY `ttid` (`ttid`)
) ENGINE=MyISAM AUTO_INCREMENT=19 DEFAULT CHARSET=gbk");
E_D("replace into `phomelightgx_ecms_news` values('1','1','0','2012-11-05','','','1','admin','','1','0','1352080230','0','1','0','0','','','1','0','0','0','0','0','0','hd1','1352080201','/d/file/sy/2012-11-05/ad75199ddd759b3d5c3eff02b39bf70f.jpg','0','1','1352080373','0','0','0','0','','646','0','1','','0','','1','<p>646</p>');");
E_D("replace into `phomelightgx_ecms_news` values('2','1','0','2012-11-05','','','1','admin','','1','0','1352080392','0','1','0','0','','','2','0','0','0','0','0','0','hd2','1352080376','/d/file/sy/2012-11-05/7cd97f0740881e226ed946f94f047b80.jpg','0','1','1352080392','0','0','0','0','','646','0','1','','0','','1','<p>646</p>');");
E_D("replace into `phomelightgx_ecms_news` values('3','16','2','2012-11-06','','','1','admin','','1','0','1352166122','0','1','0','0','','','3','0','0','0','0','0','0','盗墓','1352166056','/d/file/zpxs/1/3/2012-11-06/1f03bc0f51c1f4b7665db98de16556d9.jpg','0','1','1352254138','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"盗墓21.jpg\\\\\" width=\\\\\"1125\\\\\" height=\\\\\"1200\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/7cee3a543cd2bb7c395e87609c1ac2bb.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('4','16','1','2012-11-06','','','1','admin','','1','0','1352166170','0','1','0','0','','','4','0','0','0','0','0','0','盗墓笔记','1352166124','/d/file/zpxs/1/3/2012-11-06/0363bbaf551e0fe0dd16c22fe8fdf3e2.jpg','0','1','1352254179','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"盗墓笔记24.jpg\\\\\" width=\\\\\"1024\\\\\" height=\\\\\"768\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/106fd7a8d5a62861cb78aa2abf03a56e.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('5','16','2','2012-11-06','','','1','admin','','1','0','1352168045','0','1','0','0','','','5','0','0','0','0','0','0','盗墓','1352167979','/d/file/zpxs/1/3/2012-11-06/8ab5b392f9985eb812d0889da2c6dc4e.jpg','0','1','1352254212','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"盗墓加长8.jpg\\\\\" width=\\\\\"1200\\\\\" height=\\\\\"686\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/2f4ec45449e06c39f4f388da9d6c3d01.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('6','16','2','2012-11-06','','','1','admin','','1','0','1352170780','0','1','0','0','','','6','0','0','0','0','0','0','洞口色彩','1352170727','/d/file/zpxs/1/3/2012-11-06/07fc4af827a4118296c227e1767a00ab.jpg','0','1','1352254255','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"洞口色彩16.jpg\\\\\" width=\\\\\"1078\\\\\" height=\\\\\"768\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/353655c364bd11f024b7979d80af68cd.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('7','16','3','2012-11-06','','','1','admin','','1','0','1352170813','0','1','0','0','','','7','0','0','0','0','0','0','风雨夜归人','1352170782','/d/file/zpxs/1/3/2012-11-06/e4eb3052df04e4bdc32d89b864416684.jpg','0','1','1352254337','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"风雨夜归人12副本.jpg\\\\\" width=\\\\\"1200\\\\\" height=\\\\\"530\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/fe3c7fe9f2552f858672dd778653f705.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('8','16','2','2012-11-06','','','1','admin','','1','0','1352170847','0','1','0','0','','','8','0','0','0','0','0','0','攻城','1352170815','/d/file/zpxs/1/3/2012-11-06/d07a8771711aa6c22237a471b98332ad.jpg','0','1','1352254388','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"攻城12.jpg\\\\\" width=\\\\\"1300\\\\\" height=\\\\\"501\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/32e061db393a1588d265ffe7aa3841dd.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('9','2','0','2012-11-06','','','1','admin','','1','0','1352192293','0','1','0','0','','','9','0','0','0','0','0','0','关于我们','1352192283','','0','1','1352192293','0','0','0','0','','光线时代（北京）数码科技有限公司是一家具有国际专业水准，致力于用国际专业标准为客户提供游戏设计制作全方位服务的数字技术提供商，领域涵盖游戏研发、概念设计、插画、','0','1','','0','','0','<p style=\\\\\"line-height: 22px; text-indent: 2em; color: #cccccc; font-size: 12px\\\\\">光线时代（北京）数码科技有限公司是一家具有国际专业水准，致力于用国际专业标准为客户提供游戏设计制作全方位服务的数字技术提供商，领域涵盖游戏研发、概念设计、插画、漫画等，为不同行业的客户提供有针对性的产品和服务形式，以满足客户的不同需求。</p>\r\n<p style=\\\\\"line-height: 22px; text-indent: 2em; color: #cccccc; font-size: 12px\\\\\">光线时代（北京）数码科技有限公司的前身光线制作（北京）工作室成立2005年核心人员均有八年以上游戏制作经验，在日韩、欧美、网易、完美、搜狐、等各大知名公司担任过重要职位，都是一线的主力研发人员，具有丰富的策划、程序、美术合作经验，熟悉市场上流行的几大商业引擎，精通引擎跟美术配合的基本规律，能够最大限度发挥引擎的各项功能；精通游戏项目的管理和制作流程，熟悉游戏研发各个环节之间的技术难点和全套解决方案。</p>\r\n<p style=\\\\\"line-height: 22px; text-indent: 2em; color: #cccccc; font-size: 12px\\\\\">我们的服务宗旨是&ldquo;品质、服务、信誉&rdquo;。高端的制作人员低端的收费标准；严谨科学的项目管理流程，完善的质量保证体系；耐心细致的沟通方式，为客户提供高品质的服务是我们的最终目标。</p>');");
E_D("replace into `phomelightgx_ecms_news` values('10','4','0','2012-11-06','','','1','admin','','1','0','1352194518','0','1','0','0','','','10','0','0','0','0','0','0','业务范围','1352194507','','0','1','1352196721','0','0','0','0','','光线时代（北京）数码科技有限公司，具有顶尖的研发技术和丰富的制作经验，用高品质的质量，平和耐心的沟通方式，科学严谨的制作流程，为客户提供满意的项目服务。1、游戏开','0','1','','0','','0','<p style=\\\\\"line-height: 22px; text-indent: 2em; color: #999999; font-size: 12px\\\\\">光线时代（北京）数码科技有限公司，具有顶尖的研发技术和丰富的制作经验，用高品质的质量，平和耐心的沟通方式，科学严谨的制作流程，为客户提供满意的项目服务。</p>\r\n<p style=\\\\\"color: #999999; font-size: 12px; font-weight: bold\\\\\">1、游戏开发定制</p>\r\n<p style=\\\\\"color: #999999; font-size: 12px; font-weight: bold\\\\\">开发类型：</p>\r\n<p style=\\\\\"color: #999999; font-size: 12px\\\\\"><strong>客户端游戏</strong>：3d、2.5d、2d；mmorpg、休闲游戏、ios</p>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\"><strong>网页游戏</strong>：3d、2.5d、2d、横版、rpg等<br />\r\n策划（主策、数值、系统、文案）<br />\r\n程序（主程、引擎、客户端、服务器端、工具）<br />\r\n美术（原画、3d、ui、特效）</p>\r\n<p style=\\\\\"color: #999999; font-size: 12px; font-weight: bold\\\\\">2、美术外包</p>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\"><strong>游戏原画设定</strong>：角色、场景、装备、武器、道具、图标、UI、卡牌、宣传海报等所有游戏原画制作。</p>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\"><strong>游戏3D制作</strong>：角色、场景、装备、武器、道具等所有游戏美术资源的模型、贴图、动作等相关制作。</p>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\"><strong>项目类型</strong>：次世代、3d、2.5d、2d；mmorpg、休闲游戏、ios、网页游戏等</p>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\"><strong>风格类型</strong>：写实、唯美、漫画、Q版等。</p>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\"><strong>其他</strong>：影视、图书、网站等概念设计、宣传画、插画、漫画、封面画等。</p>');");
E_D("replace into `phomelightgx_ecms_news` values('11','5','0','2012-11-06','','','1','admin','','1','0','1352195090','0','1','0','0','','','11','0','0','0','0','0','0','招聘人才','1352195076','','0','1','1352195154','0','0','0','0','','诚邀加入 共创未来发简历时请附上个人美术和电脑手绘作品\r\n简历及作品请投递至：Light_magic@163.com [ 请注明应聘职位 ]\r\n发作品附件不要超过10MB\r\n工作地点：北京市朝阳区','0','1','','0','','0','<h4>诚邀加入 共创未来</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">发简历时请附上个人美术和电脑手绘作品<br />\r\n简历及作品请投递至：Light_magic@163.com [ 请注明应聘职位 ]<br />\r\n发作品附件不要超过10MB<br />\r\n工作地点：北京市朝阳区北岸1292自由创意区B座（传媒大学附近）</p>\r\n<h4>研发2D原画设计师：（1-2名）</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">1、有扎实的美术功底，专业美术院校或相关专业毕业；<br />\r\n2、1年以上游戏原画、插画、漫画制作经验；<br />\r\n3、对各种风格有良好的适应能力和理解力,能根据客户要求设计出高品质的角色或建筑场景，至少精通一种绘画风格；<br />\r\n4、能熟练使用Photoshop或Painter等软件；<br />\r\n5、有团队合作意识； 注意细节，注重品质；认真耐心细致的工作态度；虚心好学，善于总结</p>\r\n<h4>2D原画实习生（1-2名）</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">1、良好的美术基础；<br />\r\n2、 熟练使用photshop或painter等绘图软件；<br />\r\n3、 工作态度认真，端正且有钻研精神与团队精神，对于游戏、插画等美术制作有高度的热诚；<br />\r\n4、 实习期过后表现优秀者正式录用；</p>\r\n<h4>3D美术师（1-2名）</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">1、有扎实的美术功底，专业美术院校或相关专业毕业；<br />\r\n2、1年以上3D美术游戏制作经验，能熟练制作模型和绘制贴图；<br />\r\n3、对各种风格有良好的适应能力和理解力；<br />\r\n4、能熟练使用MAX或MAYA，Photoshop，Zbrush等软件；<br />\r\n5、有团队合作意识； 注意细节，注重品质；认真耐心细致的工作态度；虚心好学，善于总结</p>\r\n<h4>3D美术实习生（1-2名）</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">1、 良好的美术基础；<br />\r\n2、 能熟练使用MAX或MAYA，Photoshop，Zbrush等软件；<br />\r\n3、 工作态度认真，端正且有钻研精神与团队精神，对于游戏美术制作有高度的热诚；<br />\r\n4、 实习期过后表现优秀者正式录用；</p>\r\n<h4 style=\\\\\"line-height: 22px\\\\\">市场推广专员（应届生均可）<br />\r\n岗位职责</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">1、 负责公司业务的市场推广；<br />\r\n2、 负责公司品牌塑造、形象打造、项目推广、市场研究；<br />\r\n3、 负责公司客户联络，客户接待；</p>\r\n<h4>职位要求：</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">1、 英语专业优先；<br />\r\n2、 熟悉网络营销模式，有丰富的论坛和社区活动经验，熟悉如何发帖和管理<br />\r\n3、 对市场有敏锐的洞察力，有较强的市场策划能力<br />\r\n4、 性格活泼外向，沟通能力强，有良好的人际交往能力</p>\r\n<h4 style=\\\\\"line-height: 22px\\\\\">经理助理（应届生均可）<br />\r\n岗位职责</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">1、处理公司日常行政事物，进行招聘、内务、考勤等工作；<br />\r\n2、协助参与经营管理、项目推广、市场研究工作<br />\r\n3、客户联络、客户接待</p>\r\n<h4>职位要求：</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">1、 英语专业优先；<br />\r\n2、 熟悉网络，有丰富的论坛和社区活动经验，熟悉如何发帖和管理<br />\r\n3、 熟练使用办公软件及各种网络即时通讯工具<br />\r\n4、 性格活泼外向，沟通能力强，有良好的人际交往能力</p>\r\n<h4>研发2D原画场景设计师（实习也可）：（1-2名）</h4>\r\n<p style=\\\\\"line-height: 22px; color: #999999; font-size: 12px\\\\\">1、有扎实的美术功底，专业美术院校或相关专业毕业；<br />\r\n2、擅长中国风场景绘制，对中国古代建筑特点有所研究和了解<br />\r\n3、良好的把握空间和运用光影的能力，尤其具有深入细节的能力<br />\r\n4、能熟练使用Photoshop或Painter等软件；<br />\r\n5、有团队合作意识； 注意细节，注重品质；认真耐心细致的工作态度；虚心好学，善于总结</p>');");
E_D("replace into `phomelightgx_ecms_news` values('12','6','0','2012-11-06','','','1','admin','','1','0','1352195907','0','1','0','0','','','12','0','0','0','0','0','0','联系我们','1352195890','','0','1','1352253753','0','0','0','0','','光线时代（北京）数码科技有限公司地址：北京市朝阳区建国路15号院甲1号北岸1292自由创意区B座6层\r\n电话：010-85376281\r\n邮编：100024\r\n业务合作：lightmaking@163.com\r\n人','0','1','','0','','0','<h3>光线时代（北京）数码科技有限公司</h3>\r\n<p style=\\\\\"line-height: 22px; font-size: 12px\\\\\">地址：北京市朝阳区建国路15号院甲1号北岸1292自由创意区B座6层<br />\r\n电话：010-85376281<br />\r\n邮编：100024<br />\r\n业务合作：lightmaking@163.com<br />\r\n人力资源：Light_magic@163.com<br />\r\n工作QQ: 562374011<br />\r\n博客：http://blog.sina.com.cn/guangxianpeixun</p>\r\n<p style=\\\\\"line-height: 22px; font-size: 12px\\\\\"><img alt=\\\\\"image001.jpg\\\\\" width=\\\\\"530\\\\\" height=\\\\\"381\\\\\" src=\\\\\"/d/file/lxwm/2012-11-06/2f64c5228b464a5066cf5f6c6d7aa664.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('13','16','0','2012-11-07','','','1','admin','','1','0','1352251375','0','1','0','0','','','13','0','0','0','0','0','0','黑树林','1352251216','/d/file/zpxs/1/3/2012-11-07/496db5bd9dcb6637d859b4431b530304.jpg','0','1','1352252523','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"黑树林10副本.jpg\\\\\" width=\\\\\"1400\\\\\" height=\\\\\"578\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/5f320457a4d329e76ed638853c4e1009.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('14','16','0','2012-11-07','','','1','admin','','1','0','1352254514','0','1','0','0','','','14','0','0','0','0','0','0','秦岭神树棕色','1352254480','/d/file/zpxs/1/3/2012-11-07/27d5557c52b3db91de11d76d87b8e1d0.jpg','0','1','1352254514','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"秦岭神树棕色3.jpg\\\\\" width=\\\\\"1000\\\\\" height=\\\\\"600\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/c8758e83f41daecba893a814f3ca94bc.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('15','16','0','2012-11-07','','','1','admin','','1','0','1352254592','0','1','0','0','','','15','0','0','0','0','0','0','山城','1352254515','/d/file/zpxs/1/3/2012-11-07/9b4354f93b585200411f340a12d7a6f7.jpg','0','1','1352254592','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"山城9副本.jpg\\\\\" width=\\\\\"1100\\\\\" height=\\\\\"655\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/b31703b978f2cdf1c7088fe917a46ae8.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('16','16','0','2012-11-07','','','1','admin','','1','0','1352255048','0','1','0','0','','','16','0','0','0','0','0','0','雪山','1352254973','/d/file/zpxs/1/3/2012-11-07/b2bc7ae040cfb50394e955b6bfd8ace2.jpg','0','1','1352255048','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"雪山9副本.jpg\\\\\" width=\\\\\"1200\\\\\" height=\\\\\"495\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/555fe1dca5c0600127e8094e42680b4f.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('17','16','0','2012-11-07','','','1','admin','','1','0','1352255100','0','1','0','0','','','17','0','0','0','0','0','0','夜游神','1352255050','/d/file/zpxs/1/3/2012-11-07/bc78cc637fb4e66bd1e95a5de3def0db.jpg','0','1','1352255100','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"夜游神8副本.jpg\\\\\" width=\\\\\"1200\\\\\" height=\\\\\"685\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/15070cd987ad7dfc118a37b051d28e62.jpg\\\\\" /></p>');");
E_D("replace into `phomelightgx_ecms_news` values('18','16','0','2012-11-07','','','1','admin','','1','0','1352255214','0','1','0','0','','','18','0','0','0','0','0','0','正午阳光','1352255102','/d/file/zpxs/1/3/2012-11-07/f0bdd78b7d349edf2ef164caac401590.jpg','0','1','1352255214','0','0','0','0','','','0','1','','0','','1','<p><img alt=\\\\\"正午阳光12副本.jpg\\\\\" width=\\\\\"1200\\\\\" height=\\\\\"513\\\\\" src=\\\\\"/d/file/zpxs/1/3/2012-11-07/304aae7559c46237ba8b39bee66a8792.jpg\\\\\" /></p>');");

@include("../../inc/footer.php");
?>