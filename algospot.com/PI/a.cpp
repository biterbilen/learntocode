#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
        
using namespace std;

const long long LLMIN = numeric_limits<long long>::min();

int get_result(int C[10000],
               char N[10000],
               int n,
               int idx)
{

    // memoization
    int & r = C[idx];
    if (r >= 0) return r;

    // base condition
    // recursion
    
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
