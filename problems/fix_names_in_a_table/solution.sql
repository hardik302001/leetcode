# https://leetcode.com/problems/fix-names-in-a-table/discuss/2092345/Optimal-Solution-With-Explanation

SELECT user_id, 
CONCAT(UCASE(LEFT(name, 1)), LCASE(SUBSTRING(name, 2, LENGTH(name)))) as name
FROM Users
ORDER BY user_id;