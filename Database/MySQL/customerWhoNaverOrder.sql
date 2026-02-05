-- Leetcode problem 183 -> Customers Who Never Order
--Way: 01
SELECT name AS Customers
FROM Customers c
WHERE NOT EXISTS (
    SELECT 1
    FROM Orders o
    WHERE o.customerId = c.id
);

--Way: 02
SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o
    ON c.id = o.customerId
WHERE o.customerId IS NULL;

--Way: 03
SELECT c.name as Customers
FROM Customers c
WHERE id NOT IN (SELECT customerId FROM Orders)