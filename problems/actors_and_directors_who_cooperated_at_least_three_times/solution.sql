# https://stackoverflow.com/questions/2421388/using-group-by-on-multiple-columns

/*

Group By X means put all those with the same value for X in the one group.

Group By X, Y means put all those with the same values for both X and Y in the one group.


*/

select actor_id , director_id
from ActorDirector
group by actor_id , director_id
having count(timestamp)>=3