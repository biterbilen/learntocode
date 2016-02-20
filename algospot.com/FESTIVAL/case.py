import sys
import random

C = 1
N = 7
L = 3

if __name__ == '__main__':
    #print(sys.argv)

    if len(sys.argv) != 4:
        print('usage) case.py C N L')
        print('example) case.py 1 6 3')
        sys.exit()
        C = int(sys.argv[1])
        N = int(sys.argv[2]) 
        L = int(sys.argv[3]) 

    for i in xrange(C):

        N = random.randrange(1, 1001)
        L = random.randrange(1, N+1)

        print(i+1)
        print(" ".join([str(x) for x in [N, L]]))
        print(" ".join([str(x%3+1) for x in xrange(N)]))
