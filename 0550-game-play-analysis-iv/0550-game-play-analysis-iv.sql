# Write your MySQL query statement below
WITH d AS (
    SELECT player_id AS pd,MIN(event_date ) AS fd
    FROM Activity
    GROUP BY player_id
)
SELECT ROUND(
    COUNT(DISTINCT player_id)/
    (SELECT COUNT(DISTINCT player_id) FROM Activity),
    2
) AS fraction 
FROM Activity 
JOIN d
ON event_date = DATE_ADD(d.fd, INTERVAL 1 DAY) && player_id =pd ;
