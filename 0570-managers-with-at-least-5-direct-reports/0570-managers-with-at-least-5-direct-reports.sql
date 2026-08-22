# Write your MySQL query statement below
WITH cnt_rpt AS ( 
    SELECT managerId , COUNT(managerId) as cnt
    FROM Employee
    GROUP BY managerId
)
SELECT name FROM Employee
WHERE id IN(
    SELECT managerId 
    FROM cnt_rpt
    where cnt >=5 
);