#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int get_hug_cnt(string & M, string & F)
{
    return 0;
}

int main() {
    
    int C; // number of cases
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        string  M, F; // members, fans
        scanf("%d", &N);
        cin >> M;
        cin >> F;

        printf("%d\n", get_hug_cnt(M, F));
    }
  
    return 0;
}
