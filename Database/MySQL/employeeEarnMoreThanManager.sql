-- Leetcode problem 181 -> Employees Earning More Than Their Managers (Database -> MySQL -> Easy)
SELECT e.name AS Employee
FROM Employee e
JOIN Employee m
ON e.managerId = m.id
Where e.salary > m.salary;

-- Pass