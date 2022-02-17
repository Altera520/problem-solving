# Write your MySQL query statement below


select firstName
     , lastName
     , city
     , state
  from Person as t1
  left outer join Address t2
  on t1.personId = t2.personId
