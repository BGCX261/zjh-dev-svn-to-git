CREATE TABLE stock_summary
(
stype NVARCHAR(32),
field1 NVARCHAR(96),
field2 NVARCHAR(96),
field3 NVARCHAR(96),
field4 NVARCHAR(96),
field5 NVARCHAR(96),
field6 NVARCHAR(96),
field7 NVARCHAR(96),
field8 NVARCHAR(96),
field9 NVARCHAR(96),
field10 NVARCHAR(96),
field11 NVARCHAR(96),
field12 NVARCHAR(96),
);

INSERT INTO stock_summary (field1,field2,field3,field4,field5,field6)
VALUES({1},'{2}','{3}','{4}','{5}','{6}','{7}','{8}')

INSERT INTO stock_summary (stype,field1,field2,field3,field4,field5,field6)
VALUES('tmxmoney','14,205.72','Feb 22, 2014, 11:00 PM EST','-4.65 (-0.03%)','184,286,053','14,253.16','14,205.72')

DELETE FROM stock_summary
