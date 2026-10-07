# Write your MySQL query statement below
SELECT p.product_id,
       CASE
        WHEN x.new_price IS NULL THEN 10
        ELSE x.new_price
        END AS price
FROM (SELECT DISTINCT product_id FROM Products) p
LEFT JOIN(
    SELECT p1.product_id, p1.new_price
    FROM Products p1
    LEFT JOIN Products p2
    ON p1.product_id=p2.product_id
    AND p2.change_date>p1.change_date
    AND p2.change_date<= '2019-08-16'
    WHERE p1.change_date<= '2019-08-16'
    AND p2.change_date IS NULL
) x
ON p.product_id=x.product_id