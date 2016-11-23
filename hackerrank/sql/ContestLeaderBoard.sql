SELECT H.hacker_id, H.name, COUNT(C.challenge_id) AS t
FROM Hackers H INNER JOIN Challenges C
ON H.hacker_id = C.hacker_id
GROUP BY H.hacker_id, H.name
HAVING t = 
(SELECT COUNT(C1.challenge_id) AS t1 
    FROM Challenges C1
    GROUP BY C1.hacker_id
    ORDER BY t1 DESC LIMIT 1)
ORDER BY COUNT(C.challenge_id) DESC, H.hacker_id DESC;
