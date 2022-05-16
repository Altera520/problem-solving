with recursive cte as (
    select 9 as hour
    union all
    select hour + 1
      from cte
     where hour <= 18
)
select cte.hour
     , t.cnt
  from cte
 left join (
    select hour(datetime) as hour
         , count(*) as cnt
      from animal_outs
     group by hour(datetime)
 ) t
 on cte.hour = t.hour

    
