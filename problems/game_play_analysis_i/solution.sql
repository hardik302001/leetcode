# Write your MySQL query statement below




# see how beuatiifully group by works and min
# similar logic used in :https://leetcode.com/problems/delete-duplicate-emails/

select player_id , min(event_date) as 'first_login'
from Activity
group by player_id 
