USE drupal;

SELECT
t4.nid,t4.tid,t4.name,t4.type,t4.created,t4.title,t4.body_value,t4.field_image_fid,t4.field_image_title,fm.filename,fm.uri,fm.filemime,t4.field_image_width,t4.field_image_height
FROM
(SELECT
t3.nid,t3.tid,t3.name,t3.type,t3.created,t3.title,t3.body_value,fi.field_image_fid,fi.field_image_title,fi.field_image_width,fi.field_image_height
FROM
(SELECT
t2.nid,t2.tid,ttd.name,t2.type,t2.created,t2.title,t2.body_value
FROM
(SELECT
t1.nid,t.tid,t1.type,t1.created,t1.title,t1.body_value
FROM
(SELECT n.nid,n.type,n.title,f.body_value,n.created
FROM
node n INNER JOIN field_data_body f
ON n.nid = f.entity_id
WHERE (n.type = 'page' OR n.type = 'article') AND n.status = 1) t1
LEFT JOIN taxonomy_index t
ON t1.nid = t.nid) t2
LEFT JOIN taxonomy_term_data ttd
ON t2.tid = ttd.tid
WHERE ttd.name='030101_SCZS'
ORDER BY t2.created DESC
LIMIT 10) t3
LEFT JOIN field_data_field_image fi
ON t3.nid = fi.entity_id) t4
LEFT JOIN file_managed fm
ON t4.field_image_fid = fm.fid
