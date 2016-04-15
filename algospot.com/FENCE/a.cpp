#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int get_max_square_size(vector<int> & H, int l, int r)
{
    printf("[%d, %d]\n", l, r);

    // base condition
    if (l >= r) return H[l];

    // recursion
    // get left, right max size
    int max_size = 0;
    int idx_mid  = l + (r-l)/2;
    max_size = get_max_square_size(H, l, idx_mid);
    max_size = max(max_size, get_max_square_size(H, idx_mid+1, r));


    // get middle max size
    int l_inner = idx_mid;
    int r_inner = idx_mid+1;
    int max_size_inner = 0;

    while ( l_inner >= l && r_inner <= r )
    {
        int cnt_inner = r_inner - l_inner + 1;
        
        if (H[l_inner] > H[r_inner])
        {   
            max_size_inner = max(max_size_inner, cnt_inner * H[r_inner]);
            r_inner++;
        }
        else
        {
            max_size_inner = max(max_size_inner, cnt_inner * H[l_inner]);
            l_inner--;
        }
    }
    
    return max(max_size, max_size_inner);
}

// int get_max_square_size(vector<int> & H, int l, int cnt)
// {
//     printf("[%d, %d]\n", l, cnt);
    
//     int max_size = 0; // return value
//     // base condition
//     if (cnt == 1) return H[l];

//     // recursion
//     int idx_mid = l + cnt/2;
//     int cnt_part_1 = cnt % 2 == 0 ? cnt / 2 : cnt / 2 + 1;
//     int cnt_part_2 = cnt/ 2;
//     // get left, right size
//     max_size = get_max_square_size(H, l, cnt_part_1);
//     max_size = max(max_size, get_max_square_size(H, idx_mid+1, cnt_part_2));
 
//     // get middle size
//     int l_inner = idx_mid;
//     int r_inner = idx_mid+1;
//     int max_size_inner = 0;
    
//     while ( l_inner >= l && r_inner <= l+cnt-1 )
//     {
//         int cnt_inner = r_inner - l_inner + 1;
        
//         if (H[l_inner] > H[r_inner])
//         {   
//             max_size_inner = max(max_size_inner, cnt_inner * H[r_inner]);
//             r_inner++;
//         }
//         else
//         {
//             max_size_inner = max(max_size_inner, cnt_inner * H[l_inner]);
//             l_inner--;
//         }
//     }
    
//     return max(max_size, max_size_inner);
// }

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
