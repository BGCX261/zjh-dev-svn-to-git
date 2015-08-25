USE drupal;

SELECT n.nid, n.title, f.body_value
FROM node n
JOIN field_data_body f
ON n.nid = f.entity_id
WHERE
nid = 10 AND type = "page" AND status = 1
ORDER BY created DESC;
