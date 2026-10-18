# Write your MySQL query statement below
-- tough one, neeeded common table expression
WITH daily_sales AS(
    SELECT visited_on, SUM(amount) as amount
    FROM Customer
    GROUP BY visited_on
)

SELECT c.visited_on,
       SUM(c1.amount) AS amount,
        ROUND(SUM(c1.amount)/7,2) AS average_amount
FROM daily_sales c
JOIN daily_sales c1
ON c1.visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
WHERE c.visited_on>=(SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY) FROM daily_sales)
GROUP BY c.visited_on
ORDER BY c.visited_on