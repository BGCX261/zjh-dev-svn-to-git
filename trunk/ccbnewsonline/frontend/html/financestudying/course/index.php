<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta http-equiv="X-UA-Compatible" content="IE=7" />
<title>CCB news online-  加华财经门户，加拿大财经 加拿大上市公司资讯 证券外汇市场分析评论</title>
<!-- v-XO39Tn2r7xKnGcyl7J4aW8Qro -->
<meta name="keywords" content="加华财经在线 加拿大财经 加拿大上市公司资讯 证券外汇市场分析评论">
<link rel="shortcut icon" href="../../../statics/images/favicon.ico">
<meta name="description" content="加华财经在线，加拿大财经, 中文网, 加拿大上市公司资讯 证券外汇市场分析评论">
<link href="../../../statics/css/main.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="../../../statics/js/jquery.min.js"></script>
<script type="text/javascript" src="../../../statics/js/jquery.sgallery.js"></script>
<script type="text/javascript" src="../../../statics/js/search_common.js"></script>
<style type="text/css">
.sub{background:url(../../../statics/images/btn_01.jpg) no-repeat; width:78px;height:23px;border:0px;}
.ht_top_search{border:#c9c9c9 1px solid; width:215px; border-right:none; height:19px;}
</style>
</head>
<body>
  
<script type="text/javascript">document.write('<iframe src="http://www.acbnewsonline.com.au/index.php?m=member&c=index&a=mini&forward='+encodeURIComponent(location.href)+'&siteid=1" allowTransparency="true" rel="nofollow" width="1002" height="47" frameborder="0" scrolling="no"></iframe>')</script>

<?php
include "../../../php/ccb_drupal.php";
include "../../../php/ccb_news.php";

$conn = ccb_drupal_connect();
$dataJRDJT = ccb_drupal_query_page_by_category('070102_JRDJT', 12, $conn);
ccb_drupal_close($conn);
?>

<div class="top_t">
      <div class="ht_logo"><img alt="加华财经" src="../../../statics/images/logo.jpg" /></div>
   <!--<div class="ht_top_r">
      <form action="../../../index.php" method="get" target="_blank" >
				<input type="hidden" name="m" value="search"/>
				<input type="hidden" name="c" value="index"/>
				<input type="hidden" name="a" value="init"/>
			<input type="hidden" name="typeid" value="1" id="typeid"/>
				<input type="hidden" name="siteid" value="1" id="siteid"/>
  
	  
    <table width="290" border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td><input class="ht_top_search" name="q" type="text" value="" /></td>
        <td><input name="" type="SUBMIT"  class="sub" value="" style="cursor:hand;"/></td>
      </tr>
  </table>

  </form>
  </div>-->
</div> 
      

<div class="ht_daohang">
  
   <div class="ht_menu">
       <ul>
           	<li><a href="../../../index.html" class="menuxuanzhong"><span class="zw">首页</span><br /><span class="yw">Homepage</span></a></li>
                        <li class="line"></li>
            <li><a href="../../../html/financialnews.html" ><span class="zw">财经要闻</span><br /><span class="yw">Business News</span></a></li>
                        <li class="line"></li>
            <li><a href="../../../html/marketwatch.html" ><span class="zw">金融市场</span><br /><span class="yw">Financial Market</span></a></li>
                        <li class="line"></li>
            <li><a href="../../../html/listedcompanies.html" ><span class="zw">上市公司</span><br /><span class="yw">Market Watch</span></a></li>
                        <li class="line"></li>
            <li><a href="../../../html/BusinessInvestment.html" ><span class="zw">项目投资</span><br /><span class="yw">Business Investment</span></a></li>
                        <li class="line"></li>
            <li><a href="../../../html/bridgetochina.html" ><span class="zw">加中连线</span><br /><span class="yw">bridge to china</span></a></li>
                        <li class="line"></li>
            <li><a href="../../../html/financestuding.html" ><span class="zw">金融学堂</span><br /><span class="yw">Finance Satuding</span></a></li>
                        <li class="line"></li>
            <li><a href="../../../html/ccbindustryfocus.html" ><span class="zw">加华财经论坛</span><br /><span class="yw">CCB Industry Focus</span></a></li>
       </ul>
    </div>
</div>
<div class="azss_content">
<div class="left_3">
    <div class="location">加华财经在线：<a href="/">首页</a>&nbsp;&nbsp;>&nbsp;&nbsp;<a href="../">金融学堂</a> > <a href="./">金融大讲堂</a> > </div>
    <div class="tit2"><div class="tit2_name">加国财经</div></div>
	
    <ul class="newslist_01">
		<?php
			ccb_news_output_brief_list($dataJRDJT);
		?>
   </ul>

   <!--
   <div class="page"><a class="a1">1668条</a> <a href="/html/financialnews/australianews/index.html" class="a1">上一页</a> <span>1</span> <a href="/html/financialnews/australianews/2.html">2</a> <a href="/html/financialnews/australianews/3.html">3</a> <a href="/html/financialnews/australianews/4.html">4</a> <a href="/html/financialnews/australianews/5.html">5</a> <a href="/html/financialnews/australianews/6.html">6</a> <a href="/html/financialnews/australianews/7.html">7</a> <a href="/html/financialnews/australianews/8.html">8</a> <a href="/html/financialnews/australianews/9.html">9</a> <a href="/html/financialnews/australianews/10.html">10</a> ..<a href="/html/financialnews/australianews/139.html">139</a> <a href="/html/financialnews/australianews/2.html" class="a1">下一页</a></div>
   -->

</div>
  <!--﻿<div class="ht_ggft">
       <div class="tit" style="margin-top:10px;"><span class="tit_more"><a href="http://www.acbnewsonline.com.au/html/financialnews/financialviewpoint/">更多&gt;&gt;</a></span><span class="tit_name">财经观点</span></div>
        <div class="left_list">
           
   <div class="jysbg_list">
       <a href="http://www.acbnewsonline.com.au/html/2013/financialviewpoint_0915/338.html"><img alt="常兴国" src="http://www.acbnewsonline.com.au/uploadfile/2013/0915/thumb_75_75_20130915024714368.jpg" width="75" height="75" /></a><span class="name"><a href="http://www.acbnewsonline.com.au/html/2013/financialviewpoint_0915/338.html">常兴国</a> <br /></span>
             
             <ul class="newslist" style="float:left;">
                                  <li><a href="http://www.acbnewsonline.com.au/html/2012/financial_viewpoint_1030/8501.html">中国企业境外矿业投资案例分析</a></li>
                                  <li><a href="http://www.acbnewsonline.com.au/html/2013/financial_viewpoint_0826/8500.html">2013一季度中国企业境外矿业...</a></li>
                              </ul>
                      </div>
           
   <div class="jysbg_list">
       <a href="http://www.acbnewsonline.com.au/html/2013/financialviewpoint_0124/314.html"><img alt="钟默（Dr Mona Chung）" src="http://www.acbnewsonline.com.au/uploadfile/2013/0124/thumb_75_75_20130124043706964.jpg" width="75" height="75" /></a><span class="name"><a href="http://www.acbnewsonline.com.au/html/2013/financialviewpoint_0124/314.html">钟默（Dr Mona Chung）</a> <br /></span>
             
             <ul class="newslist" style="float:left;">
                              </ul>
                      </div>
           
   <div class="jysbg_list">
       <a href="http://www.acbnewsonline.com.au/html/2012/financialviewpoint_1030/302.html"><img alt="赵广彬 G.Bin Zhao" src="http://www.acbnewsonline.com.au/uploadfile/2012/1030/thumb_75_75_20121030050800455.jpg" width="75" height="75" /></a><span class="name"><a href="http://www.acbnewsonline.com.au/html/2012/financialviewpoint_1030/302.html">赵广彬 G.Bin Zhao</a> <br /></span>
             
             <ul class="newslist" style="float:left;">
                                  <li><a href="http://www.acbnewsonline.com.au/html/2013/financial_viewpoint_0531/7095.html">中国经济或面临 “转型危机”</a></li>
                                  <li><a href="http://www.acbnewsonline.com.au/html/2013/financial_viewpoint_0513/6911.html">搜狐私有化志在必得？</a></li>
                              </ul>
                      </div>
           
   <div class="jysbg_list">
       <a href="http://www.acbnewsonline.com.au/html/2012/financialviewpoint_1022/300.html"><img alt="Chris Weston" src="http://www.acbnewsonline.com.au/uploadfile/2012/1022/thumb_75_75_20121022030849962.jpg" width="75" height="75" /></a><span class="name"><a href="http://www.acbnewsonline.com.au/html/2012/financialviewpoint_1022/300.html">Chris Weston</a> <br /></span>
             
             <ul class="newslist" style="float:left;">
                                  <li><a href="http://www.acbnewsonline.com.au/html/2012/financial_viewpoint_1022/4014.html">澳多元经济仍将受益中国发展</a></li>
                              </ul>
                      </div>
           
   <div class="jysbg_list">
       <a href="http://www.acbnewsonline.com.au/html/2012/financialviewpoint_0814/287.html"><img alt="钮文新" src="http://www.acbnewsonline.com.au/uploadfile/2012/0814/thumb_75_75_20120814030904276.jpg" width="75" height="75" /></a><span class="name"><a href="http://www.acbnewsonline.com.au/html/2012/financialviewpoint_0814/287.html">钮文新</a> <br /></span>
             
             <ul class="newslist" style="float:left;">
                                  <li><a href="http://www.acbnewsonline.com.au/html/2012/financial_viewpoint_0814/2805.html">救经济没什么可犹豫</a></li>
                              </ul>
                      </div>
           </div>
             
        


      <div class="tit" style="margin-top:15px;"><span class="tit_more"><a href="http://www.acbnewsonline.com.au/html/financialnews/chinanews/">更多&gt;&gt;</a></span><span class="tit_name">中国新闻</span></div>
                  <ul class="newslist" style="margin-top:10px;">          <li><a href="http://www.acbnewsonline.com.au/html/2013/chinanews_1203/9268.html">中国上海自贸区放开个人境外投资</a></li>
                                       <li><a href="http://www.acbnewsonline.com.au/html/2013/chinanews_0930/8647.html">上海自贸区挂牌 中国改革开放迎来“新试验”</a></li>
                                       <li><a href="http://www.acbnewsonline.com.au/html/2013/chinanews_0923/8580.html">中国9月汇丰制造业PMI预览值51.2 创6个月最高</a></li>
                                       <li><a href="http://www.acbnewsonline.com.au/html/2013/chinanews_0910/8440.html">周小川：优先股能发挥独特作用</a></li>
                                       <li><a href="http://www.acbnewsonline.com.au/html/2013/chinanews_0904/8381.html">收评：沪指震荡涨0.21% 自贸区概念走强</a></li>
                                       <li><a href="http://www.acbnewsonline.com.au/html/2013/chinanews_0904/8379.html">8月中国非制造业经济运行稳定 实体经济增长</a></li>
                            <ul class="tuijian_list">
          <li>
          <a href="http://www.acbnewsonline.com.au/html/2013/chinanews_0827/8273.html"><img alt="中国统计局：中国经济出现更明显企稳迹象" src="http://www.acbnewsonline.com.au/uploadfile/2013/0828/thumb_75_75_20130828102203242.jpg" width="75" height="75" /></a>
            <div style="padding-top:10px;">
                <span class="name"><a href="http://www.acbnewsonline.com.au/html/2013/chinanews_0827/8273.html">中国统计局：中国经济出现更...</a><br /></span>
                中国国家统计局新闻发言人盛来运昨日受邀在外交部举行...            </div>
          </li>
      </ul>
                                   <li><a href="http://www.acbnewsonline.com.au/html/2013/chinanews_0824/8248.html">中国国务院批准设立上海自贸区 9月底或挂牌</a></li>
                              </ul>
                    

                       

                <div class="tit" style="margin-top:15px;"><span class="tit_more"><a href="http://www.acbnewsonline.com.au/html/financialnews/globalnews/">更多&gt;&gt;</a></span><span class="tit_name">全球新闻</span></div>
                  <ul class="newslist" style="margin-top:10px;">          <li><a href="http://www.acbnewsonline.com.au/html/2013/globalnews_1017/8832.html">美国两党就提高债务上限和重开政府达成协议</a></li>
              
                             <li><a href="http://www.acbnewsonline.com.au/html/2013/globalnews_1001/8670.html">奥巴马预算法案未获通过 美国政府正式关闭</a></li>
              
                             <li><a href="http://www.acbnewsonline.com.au/html/2013/globalnews_0919/8541.html">美联储决定保持每月850亿美元购债额度</a></li>
              
                             <li><a href="http://www.acbnewsonline.com.au/html/2013/globalnews_0907/8414.html">美非农就业不及预期 或影响退市计划</a></li>
              
                             <li><a href="http://www.acbnewsonline.com.au/html/2013/globalnews_0905/8382.html">G20峰会5日圣彼得堡开幕 拯救全球经济</a></li>
              
                             <li><a href="http://www.acbnewsonline.com.au/html/2013/globalnews_0904/8380.html">印尼财长批评美联储QE退出计划缺乏透明度</a></li>
              
                             <li><a href="http://www.acbnewsonline.com.au/html/2013/globalnews_0827/8274.html">欧美正“满血复活”新兴市场秋意渐浓</a></li>
              
                             <li><a href="http://www.acbnewsonline.com.au/html/2013/globalnews_0824/8247.html">亚洲经济不会重蹈九七覆辙</a></li>
              
                    </ul>
                              

         
      
          <div class="tit" style="margin-top:10px;"><span class="tit_more"><a href="http://www.acbnewsonline.com.au/html/financialnews/newscomments/">更多&gt;&gt;</a></span><span class="tit_name">新闻评论</span></div>
                  <ul class="newslist" style="margin-top:10px;">
           
           <li><span class="blue1">评</span>&nbsp;&nbsp;<a href="http://www.acbnewsonline.com.au/html/2013/newscomments_1104/9017.html">WUBS：美国政府关停事件的实际影响</a></li>
                       
           <li><span class="blue1">评</span>&nbsp;&nbsp;<a href="http://www.acbnewsonline.com.au/html/2013/newscomments_0830/8325.html">常兴国：中国企业境外投资模式渐变：回...</a></li>
                       
           <li><span class="blue1">评</span>&nbsp;&nbsp;<a href="http://www.acbnewsonline.com.au/html/2013/newscomments_0827/8281.html">常兴国：中国矿企视野渐宽 境外勘查模...</a></li>
                       
           <li><span class="blue1">评</span>&nbsp;&nbsp;<a href="http://www.acbnewsonline.com.au/html/2013/newscomments_0826/8269.html">常兴国：一季度中国企业境外矿业投资概览</a></li>
                       
           <li><span class="blue1">评</span>&nbsp;&nbsp;<a href="http://www.acbnewsonline.com.au/html/2013/newscomments_0817/8168.html">牛丽贤：2012版JORC规范之新意</a></li>
                       
           <li><span class="blue1">评</span>&nbsp;&nbsp;<a href="http://www.acbnewsonline.com.au/html/2013/newscomments_0710/7628.html">皮海洲：中国股民只有&ldquo;哭&rdquo;命  有种...</a></li>
                       
           <li><span class="blue1">评</span>&nbsp;&nbsp;<a href="http://www.acbnewsonline.com.au/html/2013/newscomments_0528/7062.html">陈浩庭：债务困扰多 中国经济需把脉　　</a></li>
                                    </ul>
                            

              
        
              
       
   </div>
  -->
  </div>







<div class="banner">
<script language="javascript" src="http://www.acbnewsonline.com.au/caches/poster_js/28.js"></script>



</div>

    <div class="ht_foot">
        <p class="ht_foot_m">
            <a href="../html/about/aboutus.htm" class="ma">关于我们</a>(About Us)
            <a href="http://www.ccbnewsonline.ca/html/about/protocol/">使用协议</a>(Conditions of Use)
            <a href="http://www.ccbnewsonline.ca/html/about/partners/">合作伙伴</a>(Partners)
            <a href="http://www.ccbnewsonline.ca/html/about/advertisement/">广告合作</a>(Advertising)
            <a href="http://www.ccbnewsonline.ca/html/about/contactus/">联系我们</a>(Contact us)
            <a href="http://www.ccbnewsonline.ca/html/about/careers/">诚聘英才</a>(Join us)
            <a href="http://www.ccbnewsonline.ca/html/about/helpcenter/">帮助中心</a>(Help)
            <a href="http://www.ccbnewsonline.ca/html/about/callpapers/">征稿启事</a>(Contributions Wanted)
        </p>
        声明：除非特别说明,本网站有关股票价格数据均为交易日收盘价格。本网站并不保证相关股票数据的准确性。
        <p>
            Copyright ccbnewsonline.ca All rights Reserved.<br /> <font style="color:#FF8400">本网站原创内容版权归《加华财经在线》所有，任何单位及个人转载使用时必须注明来源“CCB News 《加华财经在线》”。</font><br /> <!--Tel:(+1)-2-98762180<br/>-->    Email:ccbnews@ccbnewsonline.ca
            <script type="text/javascript">
                // 百度统计
                /*
                var _bdhmProtocol = (("https:" == document.location.protocol) ? " https://" : " http://");
                document.write(unescape("%3Cscript src='" + _bdhmProtocol + "hm.baidu.com/h.js%3F43f1efa7e09d452f87128d6d761aa8aa' type='text/javascript'%3E%3C/script%3E"));
                */
            </script>
        </p>
    </div>

</body>
</html>



