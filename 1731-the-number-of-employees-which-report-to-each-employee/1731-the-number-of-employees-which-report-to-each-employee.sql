# Write your MySQL query statement below
SELECT s.employee_id ,s.name, COUNT(t.reports_to) AS reports_count ,ROUND(AVG(t.age)) AS average_age 
FROM Employees as s
JOIN Employees as t
ON t.reports_to = s.employee_id 
GROUP BY s.employee_id , s.name 
ORDER BY s.employee_id;