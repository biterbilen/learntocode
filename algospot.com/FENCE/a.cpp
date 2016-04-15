#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int get_max_square_size(vector<int> & H, int l, int r)
{
    int max_size = 0; // return value
    // base condition
    if (l >= r) return H[l];

    // recursion
    int idx_mid = r/2;
    // get left, right size
    max_size = get_max_square_size(H, l, idx_mid);
    max_size = max(max_size, get_max_square_size(H, idx_mid+1, r));
 
    // get middle size
    int l_inner = idx_mid;
    int r_inner = idx_mid;
    while ( l_inner >= l && r_inner <= r )
    {
        
    }
    
    return max_size;
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

        printf("%d\n", get_max_square_size(H, 0, H.size()-1));
    }
  
    return 0;
}
