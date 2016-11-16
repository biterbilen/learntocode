/*
Enter your query here.
*/

SELECT C.company_code, C.founder, COUNT(L.lead_manager_code), 
COUNT(S.senior_manager_code), COUNT(M.manager_code), COUNT(E.employee_code)
FROM Company C 
INNER JOIN Lead_Manager L ON C.company_code = L.company_code
INNER JOIN Senior_Manager S ON C.company_code = S.company_code
INNER JOIN Manager M ON C.company_code = M.company_code
INNER JOIN Employee E ON C.company_code = E.company_code
GROUP BY L.lead_manager_code, S.senior_manager_code, M.manager_code, E.employee_code
ORDER BY C.company_code ASC;
