-- Leetcode problem 627 -> Swap Sex of Employees
UPDATE Salary
SET sex = 
    CASE 
        WHEN sex = 'm'
        THEN 'f'
        WHEN sex = 'f'
        THEN 'm'
    END;