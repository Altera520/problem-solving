CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select max(t.salary)
        from (
            select salary
                 , dense_rank() over (order by salary desc) as r
              from employee
             union all
            select null as salary
                 , N as r
        ) t
       where t.r = N
      
  );
END
