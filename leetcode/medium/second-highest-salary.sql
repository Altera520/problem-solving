# Write your MySQL query statement below


select max(t.salary) as SecondHighestSalary
  from (
      select salary
           , dense_rank() over (order by salary desc) as r
        from employee
       union 
      select null as salary 
           , 2 as r
  ) t
 where t.r = 2


