# Write your MySQL query statement below


# subquery

# SELECT name as 'Customers' FROM Customers WHERE id NOT IN (SELECT customerId from Orders ) 




# left join

select name as 'Customers'
from Customers
left join Orders
on Customers.id = Orders.customerId
where (Orders.id) IS NULL    -- always use IS with NULL ,  = NULL wont work here