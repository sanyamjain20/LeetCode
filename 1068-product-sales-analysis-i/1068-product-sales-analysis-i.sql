# Write your MySQL query statement below
SELECT P.product_name , S.year,s.price
FROM Product AS P
JOIN Sales AS S
ON S.product_id =P.product_id ;