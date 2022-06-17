# Write your MySQL query statement below

select p.product_id , p.product_name 
from Product as p
left join Sales as s
on p.product_id = s.product_id
GROUP BY p.product_id
HAVING MIN(sale_date) >= '2019-01-01' AND MAX(sale_date) <= '2019-03-31'