# Write your MySQL query statement below



-- group by + having
/*
SELECT email as 'Email'
FROM Person
GROUP BY email
HAVING COUNT(email)>1;
*/


-- self join
SELECT DISTINCT(p1.email) as 'Email'
FROM Person as p1 , Person as p2
WHERE p1.email = p2.email AND p1.id<>p2.id
