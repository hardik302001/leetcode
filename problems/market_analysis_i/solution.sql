/*
In the first case, you take from A, then join with B when there's a matching id and a logId, else leave details null.

In the second, you take from A, then join with B when there's a matching id, else leave details null, and then you keep only rows from A where there's a B match that has a logId -- eliminating rows from A in the process, and de facto turning it into an inner join.

*/


/*
1. we need all users , so we will do left join.
2. we do 2 condition on left join , 
3. group by user_id


*/


select user_id as buyer_id , join_date , ifnull(count(order_date) , 0) as orders_in_2019
from Users as u
left join Orders as o
on ( u.user_id = o.buyer_id and year(o.order_date) = '2019')
group by user_id
