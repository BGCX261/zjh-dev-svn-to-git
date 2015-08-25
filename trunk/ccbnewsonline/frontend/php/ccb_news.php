<?php

function ccb_news_output_list($data)
{
	// Sample:
	//	Print "<li><span style='float:right'></span><a href='www.sohu.com'>BHP：大宗商品价格短期仍存下行压力</a></li>";
	while($info = mysql_fetch_array($data))
	{
		Print "<li><span style='float:right'></span><a href='marketbrief/viewnews.php?nid=".$info['nid']."'>".$info['title']."</a></li>";
	} 
}

function ccb_news_output_list_v1($data)
{
	// Sample:
	//	Print "<li><span style='float:right'></span><a href='www.sohu.com'>BHP：大宗商品价格短期仍存下行压力</a></li>";
	while($info = mysql_fetch_array($data))
	{
		Print "<li><span style='float:right'></span><a href='viewnews.php?nid=".$info['nid']."'>".$info['title']."</a></li>";
	} 
}

// Write news with a specified folder
function ccb_news_output_list_v2($data, $relativeFolder)
{
	while($info = mysql_fetch_array($data))
	{
		Print "<li><span style='float:right'></span><a href='".$relativeFolder."/viewnews.php?nid=".$info['nid']."'>".$info['title']."</a></li>";
	} 
}

function ccb_news_output_brief_list($data)
{
	while($info = mysql_fetch_array($data))
	{
		Print "<li>";
		Print "	 <span><a href='viewnews.php?nid=".$info['nid']."' title='".$info['title']."' target='_blank' class='blue_16b' style='' >".$info['title']."</a></span><span style='float:right;'>".date("Y-m-d", $info['created'])."</span><br/>";
		Print "  <span class='gray_12n'>".$info['body_summary']."</span>";
		Print "</li>";
	}
}

// Replace all \r\n to <p></p>
function ccb_news_nl2p($string, $line_breaks = true, $xml = true)
{
	$string = str_replace(array('<p>', '</p>', '<br>', '<br />'), '', $string);

	// It is conceivable that people might still want single line-breaks
	// without breaking into a new paragraph.
	if ($line_breaks == true)
		return '<p>'.preg_replace(array("/([\n]{2,})/i", "/([^>])\n([^<])/i"), array("</p>\n<p>", '$1<br'.($xml == true ? ' /' : '').'>$2'), trim($string)).'</p>';
	else 
		return '<p>'.preg_replace(
		array("/([\n]{2,})/i", "/([\r\n]{3,})/i","/([^>])\n([^<])/i"),
		array("</p>\n<p>", "</p>\n<p>", '$1<br'.($xml == true ? ' /' : '').'>$2'),

    trim($string)).'</p>'; 
}

function ccb_news_write_image_large_url($data)
{
	if(isset($data['filename']))
		Print "<img src='/drupal/sites/default/files/styles/large/public/field/image/".$data['filename']."'/><br/>";
}

function ccb_news_write_page_body_value($data)
{
	if(isset($data['body_value']))
		Print nl2br($data['body_value']);
}

function ccb_news_write_page_body_summary($data)
{
	if(isset($data['body_summary']))
		Print nl2br($data['body_summary']);
}

function ccb_news_write_page_body_title($data)
{
	if(isset($data['title']))
		Print $data['title'];
}

function ccb_news_write_page_created($data)
{
	if(isset($data['created']))
		Print date("Y-m-d H:i", $data['created']);
}

function ccb_news_write_page_created_v2($data)
{
	Print date("Y-m-d H:i", $data);
}

?>
