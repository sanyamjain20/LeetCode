# Write your MySQL query statement below
SELECT visited_on, amount, ROUND(amount/7,2) AS average_amount
FROM(
    SELECT visited_on ,SUM(daily_amount) OVER (
    ORDER BY visited_on
    ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    )amount
    FROM (
        SELECT visited_on, SUM(amount) AS daily_amount
        FROM Customer
        GROUP BY visited_on
    ) t
)x
WHERE visited_on >= DATE_ADD((SELECT MIN(visited_on) FROM Customer),INTERVAL 6 DAY)
ORDER BY visited_on;