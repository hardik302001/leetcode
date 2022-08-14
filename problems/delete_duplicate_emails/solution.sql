
# self join
# DELETE p1 FROM Person p1, Person p2
# WHERE
#     p1.email = p2.email AND p1.Id > p2.Id
    
# similar logic used in : https://leetcode.com/problems/game-play-analysis-i/



/*


Initially , I did this and got RTE!!

DELETE FROM Person WHERE Id NOT IN 
(SELECT MIN(Id) FROM Person GROUP BY Email);


soln: https://stackoverflow.com/questions/45494/mysql-error-1093-cant-specify-target-table-for-update-in-from-clause

If you can't do

UPDATE table SET a=value WHERE x IN
    (SELECT x FROM table WHERE condition);
because it is the same table, you can trick and do :

UPDATE table SET a=value WHERE x IN
    (SELECT * FROM (SELECT x FROM table WHERE condition) as t)
[update or delete or whatever]
*/


DELETE FROM Person WHERE Id NOT IN
( SELECT * FROM (SELECT MIN(Id) FROM Person GROUP BY Email) as some_alias_table_name_i_dont_give_a_fuck_about);