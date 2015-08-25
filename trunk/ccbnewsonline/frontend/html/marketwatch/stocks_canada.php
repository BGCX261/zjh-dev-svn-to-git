<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta http-equiv="X-UA-Compatible" content="IE=7" />
<title>CCB news online-  加华财经门户，加拿大财经 加拿大上市公司资讯 证券外汇市场分析评论</title>
<meta name="keywords" content="加华财经在线 加拿大财经 加拿大上市公司资讯 证券外汇市场分析评论">
<link rel="shortcut icon" href="../statics/images/favicon.ico">
<meta name="description" content="加华财经在线，加拿大财经, 中文网, 加拿大上市公司资讯 证券外汇市场分析评论">
<link href="../../statics/css/main.css" rel="stylesheet" type="text/css" />
<link href="../../statics/css/main_ccb.css" rel="stylesheet" type="text/css" />
<link href="../../statics/css/leftnav.css" rel="stylesheet" type="text/css" />
<script type="text/javascript" src="../statics/js/jquery.min.js"></script>
<script type="text/javascript" src="../statics/js/jquery.sgallery.js"></script>
<script type="text/javascript" src="../statics/js/search_common.js"></script>
<style type="text/css">
    .sub {
        background: url(../../statics/images/btn_01.jpg) no-repeat;
        width: 78px;
        height: 23px;
        border: 0px;
    }

    .ht_top_search {
        border: #c9c9c9 1px solid;
        width: 215px;
        border-right: none;
        height: 19px;
    }
</style>
</head>
<body>
 <script type="text/javascript">
     document.write('<iframe src="../../TitalTimeBar.html" allowTransparency="true" rel="nofollow" width="1002" height="40" frameborder="0" scrolling="no"></iframe>')
</script>

<?php
include "../../php/ccb_drupal.php";
include "../../php/ccb_news.php";

$conn = ccb_drupal_connect();
$dataSCZS = ccb_drupal_query_page_by_category('030101_SCZS', 6, $conn);
$dataCPBD = ccb_drupal_query_page_by_category('030201_CPBD', 6, $conn);
ccb_drupal_close($conn);
?>

<iframe width="1002" scrolling="no" height="2" frameborder="0" rel="nofollow" allowtransparency="true" ></iframe>
 <div class="top_t">
   <div class="ht_logo"><img alt="加华财经" src="../../statics/images/logo.jpg"  style="border:1px solid blue" /></div>
   <div class="ht_top_r">
      <form action="index.php" method="get" target="_blank" >
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
  </div>
</div> 
      
<div class="ht_daohang">
    <div class="ht_menu">
       <ul>
            <li><a href="../../index.html" class="menuxuanzhong"><span class="zw">首页</span><br /><span class="yw">Homepage</span></a></li>
                        <li class="line"></li>
            <li><a href="../../html/financialnews.html" ><span class="zw">财经要闻</span><br /><span class="yw">Business News</span></a></li>
                        <li class="line"></li>
            <li><a href="../../html/marketwatch" ><span class="zw">金融市场</span><br /><span class="yw">Financial Market</span></a></li>
                        <li class="line"></li>
            <li><a href="../../html/listedcompanies.html" ><span class="zw">上市公司</span><br /><span class="yw">Market Watch</span></a></li>
                        <li class="line"></li>
            <li><a href="../../html/BusinessInvestment.html" ><span class="zw">项目投资</span><br /><span class="yw">Business Investment</span></a></li>
                        <li class="line"></li>
            <li><a href="../../html/bridgetochina.html" ><span class="zw">加中连线</span><br /><span class="yw">bridge to china</span></a></li>
                        <li class="line"></li>
            <li><a href="../../html/financestuding.html" ><span class="zw">金融学堂</span><br /><span class="yw">Finance Satuding</span></a></li>
                        <li class="line"></li>
            <li><a href="../../html/ccbindustryfocus.html" ><span class="zw">加华财经论坛</span><br /><span class="yw">CCB Industry Focus</span></a></li>              
       </ul>
   </div>
</div>

    <div class="gshq_content" style="float:left; width:200px;">
        <div class="gshq_left">
            <ul class="fllist3">
                <li><a class="leftnav_menu_bold" style="font-size: 16px; font-weight: bold">证券市场</a></li>
                <li class="pagexz"><a href="stocks_canada.html">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;加国股市</a></li>
                <li><a href="stocks_us.html">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;美股行情</a></li>
                <li><a href="stocks_europe.html">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;欧洲股市</a></li>
                <li><a href="stocks_asia.html">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;亚洲股市</a></li>
                <li><a style="font-size: 16px; font-weight: bold">期货市场</a></li>
                <li><a href="crude.html">原油</a></li>
                <li><a href="gold.html">黄金</a></li>
                <li><a href="page.html">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;大宗商品</a></li>
                <li><a style="font-size: 16px; font-weight: bold">外汇市场</a></li>
            </ul>
        </div>
    </div>

    <div class="ht_content_market">
        <div style="width:100%; padding:20px 0px;">
            <span style="font-size: 14px">
                <span style="font-family: 宋体">
                    <iframe class="ht_content_market" name=”content_frame” marginwidth=0 marginheight=0 width=100% height=700 src="./stocks_canada_tsx.php" frameborder=0></iframe>
                </span>
            </span>
        </div>        
    </div>

    <div class="ht_shichangzongshu">
        <div class="tit" style="margin-top:7px;"><span class="tit_more"><a href="./marketbrief/index.html">更多>></a></span><span class="tit_name">市场综述</span></div>
        <ul class="newslist" style="margin-top:10px;">
			<?php
				ccb_news_output_list($dataSCZS);				
			?>
        </ul>
    </div>

    <div class="ht_caopanbidu">
        <div class="tit" style="margin-top:7px;"><span class="tit_more"><a href="./marketwatch/stockread/index.html">更多>></a></span><span class="tit_name">操盘必读</span></div>
        <ul class="newslist" style="margin-top:10px;">
			<?php
				ccb_news_output_list($dataCPBD);
			?>
        </ul>
    </div>

    <div class="friendLine" style="margin-bottom:0px;">
        <div class="tit" style="margin-top:7px;"><span class="tit_name"><a href="#">友情链接</a></span></div>
        <div class="jt"><a href="#"><img alt="合作伙伴" src="http://www.acbnewsonline.com.au/statics/images/icon_05.jpg" /></a></div>
        <ul>
            <li><a href="http://www.friendline1.com/" target="_blank"><img src="../../statics/images/friends/friend_0.jpg" alt="网易财经" width="130" height="40" /></a></li>
            <li><a href="http://www.friendline1.com/" target="_blank"><img src="../../statics/images/friends/friend_0.jpg" alt="网易财经" width="130" height="40" /></a></li>
            <li><a href="http://www.friendline1.com/" target="_blank"><img src="../../statics/images/friends/friend_0.jpg" alt="网易财经" width="130" height="40" /></a></li>
            <li><a href="http://www.friendline1.com/" target="_blank"><img src="../../statics/images/friends/friend_0.jpg" alt="网易财经" width="130" height="40" /></a></li>
            <li><a href="http://www.friendline1.com/" target="_blank"><img src="../../statics/images/friends/friend_0.jpg" alt="网易财经" width="130" height="40" /></a></li>
            <li><a href="http://www.friendline1.com/" target="_blank"><img src="../../statics/images/friends/friend_0.jpg" alt="网易财经" width="130" height="40" /></a></li>
            <li><a href="http://www.friendline1.com/" target="_blank"><img src="../../statics/images/friends/friend_0.jpg" alt="网易财经" width="130" height="40" /></a></li>
        </ul>
        <div class="jt"><a href="#"><img alt="合作伙伴" src="http://www.ccbnewsonline.com.au/statics/images/icon_06.jpg" /></a></div>
    </div>

    <div style="margin-bottom:10px;width:1002px;">
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.austrade.gov.au/" title="加拿大投资署" target="_blank">加拿大投资署</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.firb.gov.au/content/default.asp" title="加拿大外商投资审查委员会" target="_blank">加拿大外商投资审查委员会</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.asic.gov.au/asic/asic.nsf" title="加拿大证券投资委员会" target="_blank">加拿大证券投资委员会</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.sydneyaustralia.com/cn/doing-business-in-sydney" title="投资悉尼" target="_blank">投资悉尼</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.trade.nsw.gov.au/" title="西南威尔士贸易投资部" target="_blank">西南威尔士贸易投资部</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.abs.gov.au/" title="加拿大统计局" target="_blank">加拿大统计局</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.australia.com " title="加拿大旅游局" target="_blank">加拿大旅游局</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.rba.gov.au/" title="加拿大联邦储备银行" target="_blank">加拿大联邦储备银行</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.auschinamine.com.au/" title="澳中矿业网" target="_blank">加中矿业网</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.asx.com.au/" title="加拿大证券交易所" target="_blank">加拿大证券交易所</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.ausmine.com/" title="加拿大矿业网" target="_blank">加拿大矿业网</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://australianbusinessforum.com.au/" title="ABF 加拿大商务论坛" target="_blank">ABF 加拿大商务论坛</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://www.cityofsydney.nsw.gov.au/" title="多伦多市政厅" target="_blank">多伦多市政厅</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://sydney.mofcom.gov.cn/" title="中国驻多伦多总领馆商务室" target="_blank">中国驻多伦多总领馆商务室</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://melbourne.mofcom.gov.cn/" title="中国驻渥太华总领馆商务室" target="_blank">中国驻渥太华总领馆商务室</a>
        &nbsp;&nbsp;&nbsp;&nbsp;<a href="http://perth.mofcom.gov.cn/" title="中国温哥华总领馆商务室" target="_blank">中国温哥华总领馆商务室</a>
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
