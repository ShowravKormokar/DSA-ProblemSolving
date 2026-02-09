-- Leetcode problem 596 -> Classes With at Least 5 Students
SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(class) >=5;