--Leetcode problem 511 -> Game Play Analysis I
SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;

--Leetcode problem 512 -> Game Play Analysis II
--The task is to find the fraction of players who logged in again the day after their first login.
SELECT ROUND(
    COUNT(DISTINCT a.player_id) / COUNT(DISTINCT b.player_id), 2
) AS fraction
FROM Activity a
JOIN (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) b
ON a.player_id = b.player_id
AND DATEDIFF(day, b.first_login, a.event_date) = 1;

--Leetcode problem 534 -> Game Play Analysis III
-- The task is to find the first login device for each player from the Activity table.
SELECT a.player_id, a.device_id
FROM Activity a
JOIN (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) b
ON a.player_id = b.player_id
AND a.event_date = b.first_login;

--Leetcode problem 550 -> Game Play Analysis IV
--  The task is to calculate the fraction of players who logged in on two consecutive days.
SELECT ROUND(
    COUNT(DISTINCT a.player_id) * 1.0 / COUNT(DISTINCT b.player_id), 2
) AS fraction
FROM Activity a
JOIN Activity b
  ON a.player_id = b.player_id
 AND DATEDIFF(day, b.event_date, a.event_date) = 1;