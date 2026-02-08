-- Leetcode problem 584 -> Find Customer Referee
SELECT c.name
FROM Customer c LEFT JOIN Customer t
ON c.id = t.id
WHERE c.referee_id != 2 OR c.referee_id IS NULL;