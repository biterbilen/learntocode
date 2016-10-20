# -*- coding: utf-8 -*-
# Copyright (C) 2016 by iamslash
# > python3 a.py

import sys

CACHE = []
I = 0
J = 0

def cycle_len(n):
    
    
    return 0

if __name__ == "__main__":
    for line in sys.stdin:
        CACHE = [-1] * 1000000
        
        line = line.strip()
        l = line.split(' ')
        I = int(l[0])
        J = int(l[1])

        r = 0
        for n in range(I, J+1):
            r = max(r, cycle_len(n))
            
        print('{} {} {}'.format(I, J, r))
