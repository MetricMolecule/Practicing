# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT person_name,
    turn, 
    SUM(weight) OVER (ORDER BY turn) AS total_wt
    FROM Queue
) x
WHERE total_wt <= 1000
ORDER BY turn DESC
LIMIT 1