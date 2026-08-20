# Write your MySQL query statement below
SELECT a.id FROM weather as a 
join weather as b
on datediff(a.recordDate ,b.recordDate )=1
where a.temperature>b.temperature;