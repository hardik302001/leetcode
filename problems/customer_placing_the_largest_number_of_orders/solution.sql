SELECT customer_number
FROM orders
GROUP BY customer_number
HAVING COUNT(order_number) = (
	SELECT COUNT(order_number) as cnt
	FROM orders
	GROUP BY customer_number
	ORDER BY cnt DESC       # to find max count
	LIMIT 1
)