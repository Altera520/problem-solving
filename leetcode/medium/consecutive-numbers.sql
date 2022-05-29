with cte as (
    select num
      from (
        select num
             , lead(id, 1) over (partition by num order by id) - id as seq1
             , lead(id, 2) over (partition by num order by id) - id as seq2
          from Logs
      ) t
     where 1 = 1
       and seq1 = 1
       and seq2 = 2
)
select num as ConsecutiveNums
  from cte
 group by num
