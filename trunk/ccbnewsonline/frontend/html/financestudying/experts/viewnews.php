<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<!-- saved from url=(0118)file:///E:/Carmack/Projects/code.google.carmack-projects/ccbnewsonline/Frontend/html/marketwatch/marketbrief/1209.html -->
<html xmlns="http://www.w3.org/1999/xhtml"><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

<meta http-equiv="X-UA-Compatible" content="IE=7">
<title>加拿大财经 - CCB news online-  加拿大财经门户 加拿大财经 加拿大上市公司资讯 证券外汇市场分析评论</title>
<!-- v-XO39Tn2r7xKnGcyl7J4aW8Qro -->
<meta name="keywords" content="加元,商务旅游,加拿大旅游业">
<link rel="shortcut icon" href="../../../statics/images/favicon.ico">
<meta name="description" content="联邦政府5日发布的数据显示，在澳元持续处于高位的背景下，价值940亿元的旅游业受到一定冲击，其中以海外商务旅行市场受挫最重。相关数据显示，今年第三季度，抵澳的海外商务人士数量下滑3%，而企业商务旅行支出更大幅下跌12%。 ">
<link href="./viewnews/main.css" rel="stylesheet" type="text/css">
<script type="text/javascript" src="./viewnews/jquery.min.js"></script>
<script type="text/javascript" src="./viewnews/jquery.sgallery.js"></script>
<script type="text/javascript" src="./viewnews/search_common.js"></script>
<style type="text/css">
.sub{background:url(./statics/images/btn_01.jpg) no-repeat; width:78px;height:23px;border:0px;}
.ht_top_search{border:#c9c9c9 1px solid; width:215px; border-right:none; height:19px;}
</style>
</head>
<body>
        
<script type="text/javascript">
      document.write('<iframe src="../../../TitalTimeBar.html" allowTransparency="true" rel="nofollow" width="1002" height="40" frameborder="0" scrolling="no"></iframe>')
</script>

<?php

include "../../../php/ccb_drupal.php";
include "../../../php/ccb_news.php";

$conn = ccb_drupal_connect();
$dataPage = ccb_drupal_query_node_by_nid_with_image($_GET['nid'], $conn);
$page = mysql_fetch_array($dataPage);
ccb_drupal_close($conn);

?>

  <div class="top_t">
      <div class="ht_logo"><img alt="加华财经" src="../../../statics/images/logo.jpg"></div>
   <!--<div class="ht_top_r">
      <form action="http://www.acbnewsonline.com.au/index.php" method="get" target="_blank">
				<input type="hidden" name="m" value="search">
				<input type="hidden" name="c" value="index">
				<input type="hidden" name="a" value="init">
                <input type="hidden" name="typeid" value="1" id="typeid">
				<input type="hidden" name="siteid" value="1" id="siteid">
  
	  
    <table width="290" border="0" cellpadding="0" cellspacing="0">
      <tbody><tr>
        <td><input class="ht_top_search" name="q" type="text" value=""></td>
        <td><input name="" type="SUBMIT" class="sub" value="" style="cursor:hand;"></td>
      </tr>
  </tbody></table>

  </form>
  </div>-->
</div> 

<div class="ht_daohang">  
   <div class="ht_menu">
       <ul>
           	<li><a href="./index.html" class="menuxuanzhong"><span class="zw">首页</span><br /><span class="yw">Homepage</span></a></li>
                        <li class="line"></li>
            <li><a href="./html/financialnews.html" ><span class="zw">财经要闻</span><br /><span class="yw">Business News</span></a></li>
                        <li class="line"></li>
            <li><a href="../../marketwatch" ><span class="zw">金融市场</span><br /><span class="yw">Financial Market</span></a></li>
                        <li class="line"></li>
            <li><a href="./html/listedcompanies.html" ><span class="zw">上市公司</span><br /><span class="yw">Market Watch</span></a></li>
                        <li class="line"></li>
            <li><a href="../../businessinvestment" ><span class="zw">项目投资</span><br /><span class="yw">Business Investment</span></a></li>
                        <li class="line"></li>
            <li><a href="./html/bridgetochina.html" ><span class="zw">加中连线</span><br /><span class="yw">bridge to china</span></a></li>
                        <li class="line"></li>
            <li><a href="../../financestudying" ><span class="zw">金融学堂</span><br /><span class="yw">Finance Satuding</span></a></li>
                        <li class="line"></li>
            <li><a href="./bbs/index.asp" ><span class="zw">加华财经论坛</span><br /><span class="yw">CCB Industry Focus</span></a></li>
       </ul>
   </div>
</div>

<link href="./viewnews/show_caijing.css" rel="stylesheet" type="text/css">

<div class="azss_content">
    <div class="left_3">
        <div class="location">加华财经在线：<a href="../../../">首页</a>&nbsp;&nbsp;&gt;&nbsp;&nbsp;<a href="../">金融学堂</a> &gt; <a href="./">名家专栏</a> &gt; 正文</div>
        <div class="tit4"><?php ccb_news_write_page_body_title($page); ?></div>
         <div class="news_tit_sx"><?php ccb_news_write_page_created($page); ?><!--2013-12-07 08:28:38&nbsp;&nbsp; 来源：澳洲网&nbsp;&nbsp; 编辑：Lisa&nbsp;&nbsp; &nbsp;&nbsp; 文章类型：转载--></div>

    

   <div class="summary">
   <?php
		ccb_news_write_image_large_url($page);
		ccb_news_write_page_body_summary($page);
	?>
   </div>
    <div class="news_txt_detail">
 	<span style="font-size: 14px"><span style="font-family: 宋体"><?php ccb_news_write_page_body_value($page); ?></span></span><br>
<div class="content_detail">
</div>
    </div>
    <div id="pages" class="text-c"></div>
   <!--<div class="ht_news_contag"><p style="margin-bottom:10px;"><strong>Tags：</strong><a href="http://www.acbnewsonline.com.au/index.php?m=content&c=tag&catid=19&tag=%E6%BE%B3%E5%85%83" style="padding:0px 5px;">澳元</a><a href="http://www.acbnewsonline.com.au/index.php?m=content&c=tag&catid=19&tag=%E5%95%86%E5%8A%A1%E6%97%85%E6%B8%B8" style="padding:0px 5px;">商务旅游</a><a href="http://www.acbnewsonline.com.au/index.php?m=content&c=tag&catid=19&tag=%E6%BE%B3%E6%B4%B2%E6%97%85%E6%B8%B8%E4%B8%9A" style="padding:0px 5px;">澳洲旅游业</a></p></div> -->

   <!--
    <div class="tit5" style="margin-top:20px;"><span class="tit5_name">相关阅读</span></div>
    <ul class="newslist" style="margin-top:15px;">
        <li class="blue"><a href="TBD">相关阅读_TBD_01</a>&nbsp;&nbsp;[TIME-TBD]</li>
        <li class="blue"><a href="TBD">相关阅读_TBD_02</a>&nbsp;&nbsp;[TIME-TBD]</li>
        <li class="blue"><a href="TBD">相关阅读_TBD_03</a>&nbsp;&nbsp;[TIME-TBD]</li>
        <li class="blue"><a href="TBD">相关阅读_TBD_04</a>&nbsp;&nbsp;[TIME-TBD]</li>
        <li class="blue"><a href="TBD">相关阅读_TBD_05</a>&nbsp;&nbsp;[TIME-TBD]</li>
    </ul>
    <div class="ht_news_zzsm">【郑重声明】TBD</div>



    <div class="ht_news_zz">   <div class="Article-Tool">
          分享到：
		  <img src="./viewnews/weiboicon16.png" style="margin-bottom:-2px;" onclick="postToWb();" class="cu" alt="分享到腾讯微博" title="分享到腾讯微博"><script type="text/javascript">
	function postToWb(){
		var _t = encodeURI(document.title);
		var _url = encodeURIComponent(document.location);
		var _appkey = encodeURI("cba3558104094dbaa4148d8caa436a0b");
		var _pic = encodeURI('');
		var _site = '';
		var _u = 'http://v.t.qq.com/share/share.php?url='+_url+'&appkey='+_appkey+'&site='+_site+'&pic='+_pic+'&title='+_t;
		window.open( _u,'', 'width=700, height=680, top=0, left=0, toolbar=no, menubar=no, scrollbars=no, location=yes, resizable=no, status=no' );
	}
</script>
          <script type="text/javascript">document.write('<a href="http://v.t.sina.com.cn/share/share.php?url='+encodeURIComponent(location.href)+'&appkey=3172366919&title='+encodeURIComponent('澳元居高不下 澳海外商旅支出第三季大跌12%')+'" title="分享到新浪微博" class="t1" target="_blank">&nbsp;</a>');</script><a href="http://v.t.sina.com.cn/share/share.php?url=file%3A%2F%2F%2FE%3A%2FCarmack%2FProjects%2Fcode.google.carmack-projects%2Fccbnewsonline%2FFrontend%2Fhtml%2Fmarketwatch%2Fmarketbrief%2F1209.html&appkey=3172366919&title=%E6%BE%B3%E5%85%83%E5%B1%85%E9%AB%98%E4%B8%8D%E4%B8%8B%20%E6%BE%B3%E6%B5%B7%E5%A4%96%E5%95%86%E6%97%85%E6%94%AF%E5%87%BA%E7%AC%AC%E4%B8%89%E5%AD%A3%E5%A4%A7%E8%B7%8C12%25" title="分享到新浪微博" class="t1" target="_blank">&nbsp;</a><a href="http://v.t.sina.com.cn/share/share.php?url=http%3A%2F%2Fwww.acbnewsonline.com.au%2Fhtml%2F2013%2Faustralianews_1207%2F9319.html&appkey=3172366919&title=%E6%BE%B3%E5%85%83%E5%B1%85%E9%AB%98%E4%B8%8D%E4%B8%8B%20%E6%BE%B3%E6%B5%B7%E5%A4%96%E5%95%86%E6%97%85%E6%94%AF%E5%87%BA%E7%AC%AC%E4%B8%89%E5%AD%A3%E5%A4%A7%E8%B7%8C12%25" title="分享到新浪微博" class="t1" target="_blank">&nbsp;</a>
		  <script type="text/javascript">document.write('<a href="http://www.douban.com/recommend/?url='+encodeURIComponent(location.href)+'&title='+encodeURIComponent('澳元居高不下 澳海外商旅支出第三季大跌12%')+'" title="分享到豆瓣" class="t2" target="_blank">&nbsp;</a>');</script><a href="http://www.douban.com/recommend/?url=file%3A%2F%2F%2FE%3A%2FCarmack%2FProjects%2Fcode.google.carmack-projects%2Fccbnewsonline%2FFrontend%2Fhtml%2Fmarketwatch%2Fmarketbrief%2F1209.html&title=%E6%BE%B3%E5%85%83%E5%B1%85%E9%AB%98%E4%B8%8D%E4%B8%8B%20%E6%BE%B3%E6%B5%B7%E5%A4%96%E5%95%86%E6%97%85%E6%94%AF%E5%87%BA%E7%AC%AC%E4%B8%89%E5%AD%A3%E5%A4%A7%E8%B7%8C12%25" title="分享到豆瓣" class="t2" target="_blank">&nbsp;</a><a href="http://www.douban.com/recommend/?url=http%3A%2F%2Fwww.acbnewsonline.com.au%2Fhtml%2F2013%2Faustralianews_1207%2F9319.html&title=%E6%BE%B3%E5%85%83%E5%B1%85%E9%AB%98%E4%B8%8D%E4%B8%8B%20%E6%BE%B3%E6%B5%B7%E5%A4%96%E5%95%86%E6%97%85%E6%94%AF%E5%87%BA%E7%AC%AC%E4%B8%89%E5%AD%A3%E5%A4%A7%E8%B7%8C12%25" title="分享到豆瓣" class="t2" target="_blank">&nbsp;</a>
		  <script type="text/javascript">document.write('<a href="http://share.renren.com/share/buttonshare.do?link='+encodeURIComponent(location.href)+'&title='+encodeURIComponent('澳元居高不下 澳海外商旅支出第三季大跌12%')+'" title="分享到人人" class="t3" target="_blank">&nbsp;</a>');</script><a href="http://share.renren.com/share/buttonshare.do?link=file%3A%2F%2F%2FE%3A%2FCarmack%2FProjects%2Fcode.google.carmack-projects%2Fccbnewsonline%2FFrontend%2Fhtml%2Fmarketwatch%2Fmarketbrief%2F1209.html&title=%E6%BE%B3%E5%85%83%E5%B1%85%E9%AB%98%E4%B8%8D%E4%B8%8B%20%E6%BE%B3%E6%B5%B7%E5%A4%96%E5%95%86%E6%97%85%E6%94%AF%E5%87%BA%E7%AC%AC%E4%B8%89%E5%AD%A3%E5%A4%A7%E8%B7%8C12%25" title="分享到人人" class="t3" target="_blank">&nbsp;</a><a href="http://share.renren.com/share/buttonshare.do?link=http%3A%2F%2Fwww.acbnewsonline.com.au%2Fhtml%2F2013%2Faustralianews_1207%2F9319.html&title=%E6%BE%B3%E5%85%83%E5%B1%85%E9%AB%98%E4%B8%8D%E4%B8%8B%20%E6%BE%B3%E6%B5%B7%E5%A4%96%E5%95%86%E6%97%85%E6%94%AF%E5%87%BA%E7%AC%AC%E4%B8%89%E5%AD%A3%E5%A4%A7%E8%B7%8C12%25" title="分享到人人" class="t3" target="_blank">&nbsp;</a>
		  <script type="text/javascript">document.write('<a href="http://www.kaixin001.com/repaste/share.php?rtitle='+encodeURIComponent('澳元居高不下 澳海外商旅支出第三季大跌12%')+'&rurl='+encodeURIComponent(location.href)+'&rcontent=" title="分享到开心网" class="t4" target="_blank">&nbsp;</a>');</script><a href="http://www.kaixin001.com/repaste/share.php?rtitle=%E6%BE%B3%E5%85%83%E5%B1%85%E9%AB%98%E4%B8%8D%E4%B8%8B%20%E6%BE%B3%E6%B5%B7%E5%A4%96%E5%95%86%E6%97%85%E6%94%AF%E5%87%BA%E7%AC%AC%E4%B8%89%E5%AD%A3%E5%A4%A7%E8%B7%8C12%25&rurl=file%3A%2F%2F%2FE%3A%2FCarmack%2FProjects%2Fcode.google.carmack-projects%2Fccbnewsonline%2FFrontend%2Fhtml%2Fmarketwatch%2Fmarketbrief%2F1209.html&rcontent=" title="分享到开心网" class="t4" target="_blank">&nbsp;</a><a href="http://www.kaixin001.com/repaste/share.php?rtitle=%E6%BE%B3%E5%85%83%E5%B1%85%E9%AB%98%E4%B8%8D%E4%B8%8B%20%E6%BE%B3%E6%B5%B7%E5%A4%96%E5%95%86%E6%97%85%E6%94%AF%E5%87%BA%E7%AC%AC%E4%B8%89%E5%AD%A3%E5%A4%A7%E8%B7%8C12%25&rurl=http%3A%2F%2Fwww.acbnewsonline.com.au%2Fhtml%2F2013%2Faustralianews_1207%2F9319.html&rcontent=" title="分享到开心网" class="t4" target="_blank">&nbsp;</a>
		  <script type="text/javascript">document.write('<a href="http://sns.qzone.qq.com/cgi-bin/qzshare/cgi_qzshare_onekey?url='+encodeURIComponent(location.href)+'" title="分享到QQ空间" class="t5" target="_blank">&nbsp;</a>');</script><a href="http://sns.qzone.qq.com/cgi-bin/qzshare/cgi_qzshare_onekey?url=file%3A%2F%2F%2FE%3A%2FCarmack%2FProjects%2Fcode.google.carmack-projects%2Fccbnewsonline%2FFrontend%2Fhtml%2Fmarketwatch%2Fmarketbrief%2F1209.html" title="分享到QQ空间" class="t5" target="_blank">&nbsp;</a><a href="http://sns.qzone.qq.com/cgi-bin/qzshare/cgi_qzshare_onekey?url=http%3A%2F%2Fwww.acbnewsonline.com.au%2Fhtml%2F2013%2Faustralianews_1207%2F9319.html" title="分享到QQ空间" class="t5" target="_blank">&nbsp;</a>
      


	  </div>
  </div>
      <div class="ht_news_nexttag"></div>
  <div class="ht_news_next" style="line-height:20px; padding-top:5px;">
    
      阅读上一篇：<a href="http://www.acbnewsonline.com.au/html/2013/australianews_1207/9318.html">悉尼达令港25亿改造工程下周启动</a>
	<br>
	阅读下一篇：<a href="http://www.acbnewsonline.com.au/html/2013/australianews_1209/9325.html">首届澳大利亚乳制品业投资论坛将于2月开幕</a></div>
    -->
    
   
    <div class="tit5" style="margin-top:20px;"></div>
    
    

</div>
   ﻿<div class="ht_ggft">

	<!--
    <div class="tit" style="margin-top:15px;"><span class="tit_more"><a href="javascript:;" onmouseover="wyqihuan(&#39;paihang&#39;,1,2)" class="wytit" id="paihang1">每周</a><span style="padding:0px 5px;">|</span><a href="javascript:;" id="paihang2" onmouseover="wyqihuan(&#39;paihang&#39;,2,2)">每月</a></span><span class="tit_name">热门点击排行</span></div>
        <ul class="newslist" style="margin-top:10px;" id="cpaihang1">
		    <li><a class="blue" href="TBD" target="_blank">TBD_01</a></li>
			<li><a class="blue" href="TBD" target="_blank">TBD_02</a></li>
			<li><a class="blue" href="TBD" target="_blank">TBD_03</a></li>
			<li><a class="blue" href="TBD" target="_blank">TBD_04</a></li>
			<li><a class="blue" href="TBD" target="_blank">TBD_05</a></li>
			<li><a class="blue" href="TBD" target="_blank">TBD_06</a></li>
			<li><a class="blue" href="TBD" target="_blank">TBD_07</a></li>
			<li><a class="blue" href="TBD" target="_blank">TBD_08</a></li>
			<li><a class="blue" href="TBD" target="_blank">TBD_09</a></li>
			<li><a class="blue" href="TBD" target="_blank">TBD_10</a></li>
		</ul>                     
   </div>
   -->
   <script>
function wyqihuan(id,dq,all){
    for(i=1;i<=all;i++){
        $("#"+id+i).removeClass();
        $('#c'+id+i).hide();
    }
    $("#"+id+dq).addClass('wytit');
    $('#c'+id+dq).show();
    //$('#a'+id).attr('href',url);
}
       
   </script>
 
 </div><script type="text/javascript" src="./viewnews/index.php"></script><script type="text/javascript" src="./viewnews/index(1).php"></script><script type="text/javascript" src="./viewnews/index(2).php"></script><script type="text/javascript" src="./viewnews/index(3).php"></script>
 
<script language="javascript" src="./viewnews/35.js"></script><script type="text/javascript" src="./viewnews/index(4).php"></script><script type="text/javascript" src="./viewnews/index(5).php"></script> 
<script language="JavaScript" src="./viewnews/api.php"></script>
<div class="ht_foot">
  
<p class="ht_foot_m">

    <a href="http://www.acbnewsonline.com.au/html/about/aboutus/" class="ma">关于我们</a>(About Us)
    <a href="http://www.acbnewsonline.com.au/html/about/protocol/">使用协议</a>(Conditions of Use)
    <a href="http://www.acbnewsonline.com.au/html/about/partners/">合作伙伴</a>(Partners)
    <a href="http://www.acbnewsonline.com.au/html/about/advertisement/">广告合作</a>(Advertising)
    <a href="http://www.acbnewsonline.com.au/html/about/contactus/">联系我们</a>(Contact us)
    <a href="http://www.acbnewsonline.com.au/html/about/careers/">诚聘英才</a>(Join us)
    <a href="http://www.acbnewsonline.com.au/html/about/helpcenter/">帮助中心</a>(Help)
    <a href="http://www.acbnewsonline.com.au/html/about/callpapers/">征稿启事</a>(Contributions Wanted)
</p>


	声明：除非特别说明,本网站有关股票价格数据均为交易日收盘价格。本网站并不保证相关股票数据的准确性。
<p>
Copyright ccbnewsonline.ca All rights Reserved.<br> <font style="color:#FF8400">本网站原创内容版权归《澳华财经在线》所有，任何单位及个人转载使用时必须注明来源“ACB News 《澳华财经在线》”。</font><br> <!--Tel:(+61)-2-98762180<br/>-->    Email:ccbnews@ccbnewsonline.ca
<script src="./viewnews/h.js" type="text/javascript"></script><script src="./viewnews/h(1).js" type="text/javascript"></script><object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" id="HolmesIcon1386601613" width="20" height="20"><param name="movie" value="http://eiv.baidu.com/hmt/icon/11.swf"><param name="flashvars" value="s=http://tongji.baidu.com/hm-web/welcome/ico?s=43f1efa7e09d452f87128d6d761aa8aa"><param name="allowscriptaccess" value="always"><embed type="application/x-shockwave-flash" name="HolmesIcon1386601613" width="20" height="20" src="http://eiv.baidu.com/hmt/icon/11.swf" flashvars="s=http://tongji.baidu.com/hm-web/welcome/ico?s=43f1efa7e09d452f87128d6d761aa8aa" allowscriptaccess="always"></object><object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" id="HolmesIcon1386600847" width="20" height="20"><param name="movie" value="http://eiv.baidu.com/hmt/icon/11.swf"><param name="flashvars" value="s=http://tongji.baidu.com/hm-web/welcome/ico?s=43f1efa7e09d452f87128d6d761aa8aa"><param name="allowscriptaccess" value="always"><embed type="application/x-shockwave-flash" name="HolmesIcon1386600847" width="20" height="20" src="http://eiv.baidu.com/hmt/icon/11.swf" flashvars="s=http://tongji.baidu.com/hm-web/welcome/ico?s=43f1efa7e09d452f87128d6d761aa8aa" allowscriptaccess="always"></object>
<script src="./viewnews/stat.php" language="JavaScript"></script><script src="./viewnews/core.php" charset="utf-8" type="text/javascript"></script>

</p>
</div>






</body></html>