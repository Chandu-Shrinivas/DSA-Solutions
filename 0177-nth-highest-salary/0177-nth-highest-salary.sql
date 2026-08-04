-- CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
-- BEGIN
--     RETURN (
--         SELECT DISTINCT salary
--         FROM (
--             SELECT salary,
--                    DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
--             FROM Employee
--         ) AS T
--         WHERE rnk = N
--     );
-- END
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
 set n = n -1 ;
  RETURN (
      # Write your MySQL query statement below.
        select distinct salary 
        from Employee
        order by salary desc
        limit 1 offset n
  );
END