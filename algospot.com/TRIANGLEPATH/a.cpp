#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int get_max_path_cnt(int B[][100], int C[][100], int N)
{
   return 0;
}

int main() {
    
    int C; // number of cases
    scanf("%d", &C);

    
    for(int c=0; c<C; ++c)
    {
        int N;
        int B[100][100];
        int C[100][100];
        memset(C, -1, sizeof(C));
        scanf("%d", &N);

        for (int n=0; n<N; ++n)
        {
           for (int i=0; i<n; ++i)
           {
              scanf("%d", &B[n][i]);
           }
        }

        printf("%d\n", get_max_path_cnt(B, C, N));
   }
  
    return 0;
}
