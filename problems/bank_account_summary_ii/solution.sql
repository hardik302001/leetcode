select u.name , SUM(t.amount) as balance
from Users as u
left join Transactions as t
on u.account = t.account
group by u.account
having SUM(t.amount) > 10000
