# swapping students

select id,
case 
    when s.id%2 = 0 then (select student from seat where id = (s.id-1) )  
    when s.id%2 != 0 and id<(select count(student) from seat) then (select student from seat where id = (s.id+1) )  
    else student
end
as student
from seat as s