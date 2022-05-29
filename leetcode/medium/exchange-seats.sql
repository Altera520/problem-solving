# Write your MySQL query statement below

with p as (
        select id
             , ifnull(lead(student) over (order by id), student) as student
          from Seat
     ),
     n as (
         select id 
              , ifnull(lag(student) over (order by id), student) as student
           from Seat
     )
select *
  from (
      select id
           , student
        from p
       where id % 2 = 1
      union all 
      select id
           , student
        from n
       where id % 2 = 0
  ) t
order by id
