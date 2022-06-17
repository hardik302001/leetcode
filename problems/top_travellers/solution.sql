select u.name , sum(ifnull(r.distance , 0))  as travelled_distance
from Users as u
left join Rides as r  -- left join bcz we need all riders
on u.id = r.user_id
group by user_id
order by travelled_distance desc , name asc