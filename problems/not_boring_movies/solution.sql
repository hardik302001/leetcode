# select * from Cinema
# where id&1 and description <> "boring"
# order by rating desc


select * from Cinema
where mod(id , 2) and description NOT LIKE "boring"
order by rating desc