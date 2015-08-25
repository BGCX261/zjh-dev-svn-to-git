SELECT nid, title, body_value
FROM node
JOIN field_data_body
ON node.nid = field_data_body.entity_id
WHERE type = "page"
AND status = 1
ORDER BY created DESC;
