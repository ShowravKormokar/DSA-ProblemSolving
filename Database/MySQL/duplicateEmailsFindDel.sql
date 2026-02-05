-- Leetcode problem 182 -> Duplicate Emails
SELECT email AS Email
FROM Person
GROUP BY email
HAVING COUNT(id)>1;

--Leetcode problem 196 -> Delete Duplicate Emails
--Way: 01
DELETE p
FROM Person p
JOIN Person p2
ON p.email = p2.email
AND p.id > p2.id;

--Way: 02
DELETE FROM Person
WHERE id NOT IN (
    SELECT MIN(id)
    FROM Person
    GROUP BY email
);