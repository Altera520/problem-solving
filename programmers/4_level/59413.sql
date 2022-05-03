with recursive cte as (
    -- seed
    select 0 as hour
    union all
    -- recursion
    select hour + 1
      from cte
     where hour < 23
)
select hour
     , count(ao.datetime) as count
  from cte
  left outer join animal_outs ao
    on cte.hour = hour(ao.datetime)
 group by cte.hour
