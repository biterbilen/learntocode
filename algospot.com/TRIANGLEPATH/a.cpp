#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void dump(int B[][100], int N)
{
    for (int y=0; y<N; ++y)
    {
        for (int x=0; x<N; ++x)
        {
            printf("%d ", B[y][x]);
        }
        printf("\n");
    }
    printf("----------------\n");
}

int get_max_path_cnt(int B[][100], int C[][100], int N, int y, int x)
{
    // printf("[%d][%d] %d\n", y, x, B[y][x]);
    
    // check cache
    int & r = C[y][x];
    if (r >= 0) return r;
    
    // base condition
    if (y >= N) return r = B[y][x]; 

    // recursion
    return r = B[y][x] + max(get_max_path_cnt(B, C, N, y+1, x),
                             get_max_path_cnt(B, C, N, y+1, x+1));
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        int B[100][100];
        int CACHE[100][100];
        memset(CACHE, -1, sizeof(CACHE));
        scanf("%d", &N);

        for (int n=0; n<N; ++n)
        {
            for (int i=0; i<=n; ++i)
            {
                scanf("%d", &B[n][i]);
            }
        }

        //dump(B, N);
        
        printf("%d\n", get_max_path_cnt(B, CACHE, N, 0, 0));
   }
  
    return 0;
}
