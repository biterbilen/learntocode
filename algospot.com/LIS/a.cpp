#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int get_result(int I[500], int C[500], int N, int idx)
{
    // base condition

    // recursion
    
    return 0;
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        int INPUT[500] = {0,};
        int CACHE[500] = {0,};
        memset(INPUT, 0, sizeof(INPUT));
        memset(CACHE, -1, sizeof(CACHE));
        scanf("%d", &N);

        for (int n=0; n<N; ++n)
        {
            scanf("%d", &INPUT[n]);
        }

        //dump(B, N);
        
        printf("%d\n", get_result(INPUT, CACHE, N, 0));
   }
  
    return 0;
}
