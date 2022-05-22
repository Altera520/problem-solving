# Write your MySQL query statement below
with tmp as (
    select d.name as department
         , e.name as employee
         , salary
         , dense_rank() over (partition by d.id order by e.salary desc) as idx
      from department as d
      join employee as e
        on d.id = e.departmentId
)
select department
     , employee
     , salary
  from tmp
 where idx <= 3


