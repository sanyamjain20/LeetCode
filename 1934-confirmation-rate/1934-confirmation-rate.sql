SELECT user_id , ROUND(IFNULL(cnt / NULLIF(T, 0), 0), 2) AS confirmation_rate 
FROM (
    SELECT s.user_id ,count(action) AS T , COUNT(
        IF (action = 'confirmed',1,NULL)
        ) as cnt
    FROM Signups as s
    LEFT JOIN Confirmations AS c
    ON s.user_id =c.user_id
    GROUP BY user_id
) AS R;