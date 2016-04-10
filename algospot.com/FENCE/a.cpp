#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int get_max_square_size(vector<int> & H, int l, int r)
{
    return 0;
}

int main() {
    
    int C; // number of cases
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int N;
        vector<int> H;
        scanf("%d", &N);
        for(int n=0; n<N; ++n)
        {
            int h;
            scanf("%d", &h);
            H.push_back(h);
        }

        printf("%d\n", get_max_square_size(H, 0, H.size()));
    }
  
    return 0;
}
