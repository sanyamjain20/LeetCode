# Write your MySQL query statement below
SELECT (
    CASE
    WHEN id = COUNT(id) OVER() AND id%2<>0 THEN id
    WHEN id%2<>0 THEN id+1
    ELSE id-1
    END
) AS id , student
FROM Seat
ORDER BY id;