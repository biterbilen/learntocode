#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void dump(int I[], int N)
{
    for (int i=0; i<N; ++i)
        printf("%d ", I[i]);
    printf("\n");
}

int LIS(int I[], int C[], int N, int idx)
{
    // printf("[%d] %d\n", idx, I[idx]);
    
    // base condition
    int & r = C[idx];
    if (r >= 0) return r;

    r = 1;
    // recursion
    for (int n=idx+1; n<N; ++n)
    {
        if (I[idx] < I[n])
        {
            r = max(r, LIS(I, C, N, n) + 1);
        }
    }

    // printf("[%d] %d, %d\n", idx, I[idx], r);

    return r;
}


int get_result(int I[], int C[], int N)
{
    int r = 0;
    for(int i=0; i<N; ++i)
        r = max(r, LIS(I, C, N, i));
    return r;   
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N_1, N_2;
        int INPUT_1[100] = {0,};
        int INPUT_2[100] = {0,};
        int CACHE[100] = {0,};
        memset(CACHE, -1, sizeof(CACHE));
        scanf("%d", &N_1);
        scanf("%d", &N_2);

        for (int n=0; n<N_1; ++n)
            scanf("%d", &INPUT_1[n]);
        for (int n=0; n<N_2; ++n)
            scanf("%d", &INPUT_2[n]);

        // dump(INPUT_1, N_1);
        // dump(INPUT_2, N_2);
        // printf("----------\n");
        
        // printf("%d\n", get_result(INPUT, CACHE, N));
   }
  
    return 0;
}
