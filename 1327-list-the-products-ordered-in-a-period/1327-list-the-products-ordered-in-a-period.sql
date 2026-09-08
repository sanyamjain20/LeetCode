# Write your MySQL query statement below  
SELECT product_name , SUM(unit) AS unit
FROM Products p
JOIN Orders o
ON o.product_id = p.product_id 
WHERE DATE_FORMAT(order_date, '%m-%Y') LIKE '02-2020'
GROUP BY o.product_id 
HAVING SUM(unit)>=100;