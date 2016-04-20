#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    
    int C; // number of cases
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        int I[500] = {0,};
        int CACHE[101][101] = {0,};
        memset(SEQ, 0, sizeof(SEQ));
        memset(CACHE, -1, sizeof(CACHE));
        scanf("%d", &N);

        for (int n=0; n<N; ++n)
        {
            scanf("%d", &I[n]);
        }

        //dump(B, N);
        
        printf("%d\n", get_result(I, CACHE, N, 0));
   }
  
    return 0;
}
