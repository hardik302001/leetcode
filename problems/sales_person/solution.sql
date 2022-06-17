# the names of all the salespersons who did not have any orders related to the company with the name "RED".

select s.name from 
SalesPerson as s
WHERE s.sales_id NOT IN
(select o.sales_id from Orders as o
INNER JOIN Company as c
on c.com_id = o.com_id
where c.name = 'RED'
)


