CREATE TABLE stock_summary
(
stype VARCHAR(16),
field1 VARCHAR(64),
field2 VARCHAR(64),
field3 VARCHAR(64),
field4 VARCHAR(64),
field5 VARCHAR(64),
field6 VARCHAR(64),
field7 VARCHAR(64),
field8 VARCHAR(64),
field9 VARCHAR(64),
field10 VARCHAR(64),
field11 VARCHAR(64),
field12 VARCHAR(64),
);

INSERT INTO stock_summary (field1,field2,field3,field4,field5,field6)
VALUES({1},'{2}','{3}','{4}','{5}','{6}','{7}','{8}')

INSERT INTO stock_summary (stype,field1,field2,field3,field4,field5,field6)
VALUES('tmxmoney','14,205.72','Feb 22, 2014, 11:00 PM EST','-4.65 (-0.03%)','184,286,053','14,253.16','14,205.72')

DELETE FROM stock_summary