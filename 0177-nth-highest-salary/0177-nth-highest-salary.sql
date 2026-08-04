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
    SET N = N - 1;

    RETURN (
        SELECT IFNULL(
            (
                SELECT DISTINCT Salary
                FROM Employee
                ORDER BY Salary DESC
                LIMIT N, 1
            ),
            NULL
        )
    );
END