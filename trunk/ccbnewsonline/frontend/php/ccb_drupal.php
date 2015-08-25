<?php

function ccb_drupal_connect()
{
	//$connection = mysql_connect("localhost", "myroot", "117Chipwood") or die(mysql_error());
	//$connection = mysql_connect("localhost", "drupal_b", "U#qV4Lj3u2") or die(mysql_error());
	$connection = mysql_connect("localhost", "drupalroot", "117chipwood") or die(mysql_error());
	if (!$connection)
	{
		die('ccb_drupal_connect:Could not connect: '.mysql_error());
	}
	mysql_select_db("drupal_5") or die(mysql_error());
	//mysql_select_db("drupal") or die(mysql_error());
	// Database collation is utf8_general_ci, so call this query
	mysql_query('SET NAMES UTF8', $connection);
	return $connection;
}

function ccb_drupal_close($connection)
{
	mysql_close($connection);
}

// Query pages with specified category and limit
//	*$category - the category specified, such as "030101_SCZS"
//  *$lmt - How many pages queried
function ccb_drupal_query_page_by_category($category, $lmt, $conn)
{
	$sqlQuery = "SELECT
				t2.nid,t2.tid,ttd.name,t2.type,t2.created,t2.title,t2.body_value,t2.body_summary
				FROM
				(SELECT
				t1.nid,t.tid,t1.type,t1.created,t1.title,t1.body_value,t1.body_summary
				FROM
				(SELECT n.nid,n.type,n.title,f.body_value,f.body_summary,n.created
				FROM
				node n INNER JOIN field_data_body f
				ON n.nid = f.entity_id
				WHERE (n.type = 'page' OR n.type = 'article') AND n.status = 1) t1
				LEFT JOIN taxonomy_index t
				ON t1.nid = t.nid) t2
				LEFT JOIN taxonomy_term_data ttd
				ON t2.tid = ttd.tid
				WHERE ttd.name='{00000}'
				ORDER BY t2.created DESC
				LIMIT {11111}";
	$sqlQueryT1 = str_replace("{00000}", $category, $sqlQuery);
	$sqlQueryT2 = str_replace("{11111}", strval($lmt), $sqlQueryT1);
	$data = mysql_query($sqlQueryT2, $conn);// or die(mysql_error());
	if (!$data)
	{
		die('ccb_drupal_query_page_by_category:Invalid query: '.mysql_error());
	}
	return $data;
}

// Query a page by its nid
function ccb_drupal_query_page_by_nid($nid, $conn)
{
	$sqlQuery = "SELECT n.nid,n.title,f.body_value,f.body_summary,n.created
				FROM node n
				JOIN field_data_body f
				ON n.nid = f.entity_id
				WHERE n.nid = {00000} AND (n.type = 'page' OR n.type = 'article') AND n.status = 1";
	$sqlQueryF = str_replace("{00000}", $nid, $sqlQuery);
	$result = mysql_query($sqlQueryF, $conn);
	if (!$result)
	{
		die('ccb_drupal_query_page_by_nid:Invalid query: '.mysql_error());
	}
	return $result;
}

function ccb_drupal_query_node_by_nid_with_image($nid, $conn)
{
	$sqlQuery = "SELECT
t2.nid,t2.title,t2.body_value,t2.body_summary,t2.created,t2.field_image_fid,t2.field_image_title,fm.filename,fm.uri,fm.filemime,t2.field_image_width,t2.field_image_height
FROM
(SELECT
t1.nid,t1.title,t1.body_value,t1.body_summary,t1.created,fi.field_image_fid,fi.field_image_title,fi.field_image_width,fi.field_image_height
FROM
(SELECT n.nid,n.title,f.body_value,f.body_summary,n.created
FROM node n
JOIN field_data_body f
ON n.nid = f.entity_id
WHERE
nid = {00000} AND (type = 'page' OR type = 'article') AND status = 1
ORDER BY created DESC) t1
LEFT JOIN field_data_field_image fi
ON t1.nid = fi.entity_id) t2
LEFT JOIN file_managed fm
ON t2.field_image_fid = fm.fid";
	$sqlQueryF = str_replace("{00000}", $nid, $sqlQuery);
	$result = mysql_query($sqlQueryF, $conn);
	if (!$result)
	{
		die('ccb_drupal_query_node_by_nid_with_image:Invalid query: '.mysql_error());
	}
	return $result;
}

?>
