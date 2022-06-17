SELECT id,
       SUM(if(month = 'Jan', revenue, null)) AS Jan_Revenue,
       SUM(if(month = 'Feb', revenue, null)) AS Feb_Revenue,
       SUM(if(month = 'Mar', revenue, null)) AS Mar_Revenue,
       SUM(if(month = 'Apr', revenue, null)) AS Apr_Revenue,
       SUM(if(month = 'May', revenue, null)) AS May_Revenue,
       SUM(if(month = 'Jun', revenue, null)) AS Jun_Revenue,
       SUM(if(month = 'Jul', revenue, null)) AS Jul_Revenue,
       SUM(if(month = 'Aug', revenue, null)) AS Aug_Revenue,
       SUM(if(month = 'Sep', revenue, null)) AS Sep_Revenue,
       SUM(if(month = 'Oct', revenue, null)) AS Oct_Revenue,
       SUM(if(month = 'Nov', revenue, null)) AS Nov_Revenue,
       SUM(if(month = 'Dec', revenue, null)) AS Dec_Revenue
FROM Department
GROUP BY id

/*
IF()

IF(condition, if_true, if_false)
condition - If month is equal to the respective column (for Jan_revenue column it should be month = 'Jan')
if_true= return all the list of values with respect to the individual id, afterwards we will sum all the values in the next step.
if_false - Just return NULL id there is no revenure with respect to that ID and the month.

SUM()

We sum all the values of respective id per month and then return it in the front of that id in the respective month column.
SUM(will sum all the values under the conidtion in this bracket)

Why I have used Group By and SUM?

For same id, month value can be repeated. Sum function will add all those to display in single row as group by id is used ((not month).

*/