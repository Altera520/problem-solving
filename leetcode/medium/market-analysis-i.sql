# Write your MySQL query statement below

select u.user_id as buyer_id
     , u.join_date
     , ifnull(o.cnt, 0) as orders_in_2019
  from users as u
  left join (
      select buyer_id
           , count(buyer_id) as cnt
        from orders
       where date_format(order_date, '%Y') = '2019'
       group by buyer_id
     ) as o
    on u.user_id = o.buyer_id
