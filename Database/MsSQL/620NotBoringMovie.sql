-- Leetcode problem 620 -> Not Boring Movies
/* Write your T-SQL query statement below */
SELECT c.*
FROM Cinema c
WHERE id % 2 = 1 AND c.description != 'boring'
ORDER BY c.rating DESC;