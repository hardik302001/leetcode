# Note: Full Outer Join is not supported by MySQL so we have to use left and right join with union in the below solution.

select emp.employee_id
from employees as emp left join salaries as sal 
on emp.employee_id = sal.employee_id
where sal.salary is null

UNION

select sal.employee_id
from salaries as sal left join  employees as emp
on emp.employee_id = sal.employee_id
where emp.name is null

order by employee_id



-- use left join + left join by interchanging or use left join + right join