CREATE TABLE stock_tsx
(
id INT,
symbol VARCHAR(64),
name VARCHAR(64),
last_trade VARCHAR(8),
last_trade_time VARCHAR(16),
change VARCHAR(8),
change_percent VARCHAR(8),
volume VARCHAR(32)
);

INSERT INTO stock_tsx
(id,symbol,name,last_trade,last_trade_time,change,change_percent,volume)
VALUES
(1,'DWI.TO','DRAGONWAVE INC.','2.00','3:59PM EST','0.26','14.94','556,431')

DELETE FROM stock_tsx WHERE id > 0 AND id < 200
