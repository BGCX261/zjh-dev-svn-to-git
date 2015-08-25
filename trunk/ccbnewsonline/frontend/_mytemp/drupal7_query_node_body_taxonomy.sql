USE drupal;

SELECT
t2.nid,t2.tid,ttd.name,t2.type,t2.created,t2.title,t2.body_value
FROM
(SELECT
t1.nid,t.tid,t1.type,t1.created,t1.title,t1.body_value
FROM
(SELECT n.nid,n.type,n.title,f.body_value,n.created
FROM
node n INNER JOIN field_data_body f
ON n.nid = f.entity_id
WHERE n.type = 'page' AND n.status = 1) t1
LEFT JOIN taxonomy_index t
ON t1.nid = t.nid) t2
LEFT JOIN taxonomy_term_data ttd
ON t2.tid = ttd.tid
WHERE ttd.name='030101_SCZS'
ORDER BY t2.created DESC
LIMIT 10
