# Write your MySQL query statement below

with gain as (
    select stock_name
         , sum(price) as p
      from stocks
     where operation = 'Sell'
     group by  stock_name
), 
loss as (
    select stock_name
         , sum(price) as p
      from stocks
     where operation = 'Buy'
     group by  stock_name
)
select g.stock_name as stock_name
     , g.p - l.p as capital_gain_loss
  from gain g
  join loss l
    on g.stock_name = l.stock_name
    
