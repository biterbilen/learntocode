#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>
        
using namespace std;



float get_result(float C[][2001], int N, int M, int days, int climbed)
{
    // base condition
    if (days == M + 1)
    {
        if (climbed >= N)
            return 0.75;
        else
            return 0.25;
    }
    
    // memoization
    float & r = C[days][climbed];
    if (r >= 0) return r;

    // recursion
    return r = 0.75 * get_result(C, N, M, days+1, climbed + 1) +
        0.25 * get_result(C, N, M, days+1, climbed + 2);
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N, M;
        float CACHE[1000][2001] = {0,}; // days, climbed
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%d", &N);
        scanf("%d", &M);

        printf("%0.10f\n", get_result(CACHE, N, M, 1, 0));
   }
  
    return 0;
}
