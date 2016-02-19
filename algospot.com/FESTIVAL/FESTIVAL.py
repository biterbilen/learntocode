from __future__ import division
import sys

n_case_cnt = int(raw_input().strip())

for n_case in range(n_case_cnt):

    str_data_1          = raw_input().strip()
    l_data_1            = map((lambda x: int(x)), str_data_1.split(' '))
    n_reserved_day      = l_data_1[0]
    n_team_cnt          = l_data_1[1]

    str_data_2          = raw_input().strip()
    l_costs             = map((lambda x: int(x)), str_data_2.split(' '))
    
    l_r = []
    n_sum = 0
    n_combination_cnt = len(l_costs) - n_team_cnt + 1
    for n_idx in range(n_combination_cnt):
        l = l_costs[n_idx:n_idx+n_team_cnt]
        f = sum(l) / float(len(l))
        l_r.append(f)
        #print(l, f)

    #print(l_r)
    print(min(l_r))
    #print("%.11f"%min(l_r))
