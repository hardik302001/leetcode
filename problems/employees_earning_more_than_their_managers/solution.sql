# Write your MySQL query statement below



-- self join

SELECT e1.name AS 'Employee'
FROM Employee AS e1 ,  Employee as e2
WHERE e1.salary > e2.salary AND e1.managerId = e2.id