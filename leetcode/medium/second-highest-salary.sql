# Write your MySQL query statement below

with t as (
    select salary
         , dense_rank() over (order by salary desc) as r
      from employee
     union all
    select null as salary 
         , 2 as r
)
select max(t.salary) as SecondHighestSalary
  from t
 where t.r = 2


