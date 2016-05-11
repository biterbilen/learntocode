#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
        
using namespace std;

const int INF = numeric_limits<int>::max();

int get_lv(int beg, int end)
{
    return 0;    
}

int get_result(int C[10000],
               char N[10000],
               int n,
               int idx)
{
    // base condition
    if (idx == n) return 0;
 
    // memoization
    int & r = C[idx];
    if (r >= 0) return r;

    // recursion
    r = INF;
    for(int i=3; i<6; ++i)
    {
        if (idx + i <= n)
            r = min(r, get_result(C, N, n, idx + i) + get_lv(idx, idx + i - 1));
    }
    
    return r;   
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        char INPUT[10000] = {0,};
        int CACHE[10000] = {0,};
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%s", INPUT);
        
        //printf("%s\n", INPUT);
        printf("%d\n", get_result(CACHE, INPUT, N, 0));
        
   }
  
    return 0;
}
