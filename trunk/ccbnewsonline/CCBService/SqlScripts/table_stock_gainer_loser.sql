--stock_gainer_tsx
IF OBJECT_ID('dbo.stock_gainer_loser', 'U') IS NOT NULL
  DROP TABLE dbo.stock_gainer_loser
CREATE TABLE stock_gainer_loser
(
smarket VARCHAR(16),
stype VARCHAR(16),
symbol VARCHAR(64),
name VARCHAR(64),
last_trade VARCHAR(8),
last_trade_time VARCHAR(32),
change VARCHAR(8),
change_percent VARCHAR(8),
volume VARCHAR(32)
);
