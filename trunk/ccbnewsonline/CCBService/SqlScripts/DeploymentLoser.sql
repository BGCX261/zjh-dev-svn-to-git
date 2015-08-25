--stock_loser_tsx
IF OBJECT_ID('dbo.stock_loser_tsx', 'U') IS NOT NULL
  DROP TABLE dbo.stock_loser_tsx
CREATE TABLE stock_loser_tsx
(
id INT,
symbol VARCHAR(64),
name VARCHAR(64),
last_trade VARCHAR(8),
last_trade_time VARCHAR(32),
change VARCHAR(8),
change_percent VARCHAR(8),
volume VARCHAR(32)
);

--stock_loser_tsx_v
IF OBJECT_ID('dbo.stock_loser_tsx_v', 'U') IS NOT NULL
  DROP TABLE dbo.stock_loser_tsx_v
CREATE TABLE stock_loser_tsx_v
(
id INT,
symbol VARCHAR(64),
name VARCHAR(64),
last_trade VARCHAR(8),
last_trade_time VARCHAR(32),
change VARCHAR(8),
change_percent VARCHAR(8),
volume VARCHAR(32)
);

--stock_loser_us
IF OBJECT_ID('dbo.stock_loser_us', 'U') IS NOT NULL
  DROP TABLE dbo.stock_loser_us
CREATE TABLE stock_loser_us
(
id INT,
symbol VARCHAR(64),
name VARCHAR(64),
last_trade VARCHAR(8),
last_trade_time VARCHAR(32),
change VARCHAR(8),
change_percent VARCHAR(8),
volume VARCHAR(32)
);

--stock_loser_nasdaq
IF OBJECT_ID('dbo.stock_loser_nasdaq', 'U') IS NOT NULL
  DROP TABLE dbo.stock_loser_nasdaq
CREATE TABLE stock_loser_nasdaq
(
id INT,
symbol VARCHAR(64),
name VARCHAR(64),
last_trade VARCHAR(8),
last_trade_time VARCHAR(32),
change VARCHAR(8),
change_percent VARCHAR(8),
volume VARCHAR(32)
);

--stock_loser_amex
IF OBJECT_ID('dbo.stock_loser_amex', 'U') IS NOT NULL
  DROP TABLE dbo.stock_loser_amex
CREATE TABLE stock_loser_amex
(
id INT,
symbol VARCHAR(64),
name VARCHAR(64),
last_trade VARCHAR(8),
last_trade_time VARCHAR(32),
change VARCHAR(8),
change_percent VARCHAR(8),
volume VARCHAR(32)
);

--stock_loser_amex
IF OBJECT_ID('dbo.stock_loser_nyse', 'U') IS NOT NULL
  DROP TABLE dbo.stock_loser_nyse
CREATE TABLE stock_loser_nyse
(
id INT,
symbol VARCHAR(64),
name VARCHAR(64),
last_trade VARCHAR(8),
last_trade_time VARCHAR(32),
change VARCHAR(8),
change_percent VARCHAR(8),
volume VARCHAR(32)
);
