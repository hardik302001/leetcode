/*
offset = You can also specify an OFFSET from where to start returning data.

SELECT * FROM artists LIMIT 5 OFFSET [Number of rows to skip];

Say you want to get 5 artists, but not the first five. You want to get rows 3 through 8. You’ll want to add an OFFSET of 2 to skip the first two rows:
*/



# courtesy = sid25

select ifnull((
 select distinct Salary
 from Employee
 order by Salary desc
 limit 1 offset 1),
 null)
as SecondHighestSalary;

-- limit 1 offset 1 = > only one element from second position = 2nd element