#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

bool is_match(int C[][101], string & W, string & F, int w, int f)
{
    printf("W:%s F:%s w:%d f:%d\n", W.c_str(), F.c_str(), w, f);

    // retrieve cache
    int & r = C[w][f];
    if (r >= 0) return r;

    // recursion
    // case of '?', character not '*'
    if (w < W.size() && f < F.size() &&
           (W[w] == '?' || W[w] == F[f] ))
    {
        return r = is_match(C, W, F, w+1, f+1);
    } else if (W[w] == '*')
    {
        if ( (f < F.size() && is_match(C, W, F, w, f+1)) ||
             is_match(C, W, F, w+1, f+1))
            return r = true;
    }

    // base condition
    return false;
}

int main() {
    
    int C; // number of cases
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        string W; int N;
        cin >> W;
        scanf("%d", &N);

        for (int n=0; n<N; ++n)
        {
            string F;
            cin >> F; 
            int C[101][101];
            memset(C, -1, sizeof(C));
            if (is_match(C, W, F, 0, 0))
                printf("%s\n", F.c_str());
        }
    }
  
    return 0;
}
