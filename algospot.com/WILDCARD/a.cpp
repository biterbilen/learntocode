#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_match(char W[], char F[])
{
    return false;
}

int main() {
    
    int C; // number of cases
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        scanf("%d", &N);
        char W[100];
        scanf("%s", W);

        for (int n=0; n<N; ++n)
        {
            char F[100];
            scanf("%s", F);
            if (is_match(W, F))
                printf("%s\n", F);
        }

    }
  
    return 0;
}
