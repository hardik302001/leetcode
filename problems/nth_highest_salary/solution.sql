# similar to : https://leetcode.com/problems/second-highest-salary/


CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN

    DECLARE a INT;
    SET a=n-1;
    RETURN (
      select ifnull( (
         select distinct salary
         from Employee
         order by salary desc
         limit 1 offset a),
         null)
    );
END