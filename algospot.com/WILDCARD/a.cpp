#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_match(string & W, string & F, int w, int f)
{
    printf("W:%s F:%s w:%d f:%d\n", W.c_str(), F.c_str(), w, f);
    
    // base condition
    // if (w >= W.size() && f >= F.size()) return true;
    if (f >= F.size()) return true;
    // recursion
    if (W[w] == '*')
        return is_match(W, F, w, f+1) ||
            is_match(W, F, w+1, f+1);
    else if (W[w] == '?' || W[w] == F[f])
        return is_match(W, F, w+1, f+1);
    
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
            if (is_match(W, F, 0, 0))
                printf("%s\n", F.c_str());
        }

    }
  
    return 0;
}
