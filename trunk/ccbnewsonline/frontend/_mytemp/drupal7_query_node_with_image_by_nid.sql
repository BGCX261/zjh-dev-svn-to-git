USE drupal;

SELECT
t2.nid,t2.title,t2.body_value,t2.body_summary,t2.field_image_fid,t2.field_image_title,fm.filename,fm.uri,fm.filemime,t2.field_image_width,t2.field_image_height
FROM
(SELECT
t1.nid,t1.title,t1.body_value,t1.body_summary,fi.field_image_fid,fi.field_image_title,fi.field_image_width,fi.field_image_height
FROM
(SELECT n.nid,n.title,f.body_value,f.body_summary
FROM node n
JOIN field_data_body f
ON n.nid = f.entity_id
WHERE
nid = 13 AND (type = 'page' OR type = 'article') AND status = 1
ORDER BY created DESC) t1
LEFT JOIN field_data_field_image fi
ON t1.nid = fi.entity_id) t2
LEFT JOIN file_managed fm
ON t2.field_image_fid = fm.fid
