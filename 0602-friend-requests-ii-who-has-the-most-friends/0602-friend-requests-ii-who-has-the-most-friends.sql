# Write your MySQL query statement below
SELECT id ,num
FROM(
    SELECT id ,COUNT(*)num
    FROM(
        SELECT requester_id AS id
        FROM RequestAccepted 
        UNION ALL
        SELECT accepter_id  AS id
        FROM RequestAccepted 
    )t
    GROUP BY id
)s
ORDER BY num DESC
LIMIT 1;