/*
Enter your query here.
*/

SELECT DISTINCT H.hacker_id, H.name /*, C.challenge_id, D.score, S.score */
FROM HACKERS H 
INNER JOIN Submissions S
INNER JOIN Challenges C
INNER JOIN Difficulty D
ON H.hacker_id = S.hacker_id
AND S.challenge_id = C.challenge_id
AND C.difficulty_level = D.difficulty_level
WHERE S.score >= D.score
ORDER BY H.hacker_id ASC;
