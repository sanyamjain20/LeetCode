# Write your MySQL query statement below
SELECT person_name
FROM Queue AS s
JOIN (
    SELECT turn , SUM(weight) OVER (ORDER BY turn) AS weight_sum
    FROM Queue 
)t
ON s.turn =t.turn 
WHERE weight_sum<=1000
ORDER BY s.turn DESC
LIMIT 1;