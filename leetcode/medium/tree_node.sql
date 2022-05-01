select id
     , case 
            when tree.p_id is null then 'Root'
            when t.cnt >= 1 then 'Inner'
            else 'Leaf'
       end as type 
  from tree
  left outer join (
     select p_id
          , count(p_id) as cnt
       from tree
      group by p_id
  ) t
  on tree.id = t.p_id


