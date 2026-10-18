# Write your MySQL query statement below
SELECT id,
       CASE 
            WHEN s.id%2=1 AND s.id=(SELECT COUNT(*) FROM Seat) THEN
                            student
            WHEN s.id%2=1 THEN(
                            SELECT student 
                            FROM Seat
                            WHERE id=s.id+1)
            ELSE (
                            SELECT student
                            FROM Seat
                            WHERE id=s.id-1)
       END AS student
FROM Seat s
ORDER BY id asc