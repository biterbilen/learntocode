#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>      
#include <iomanip>
#include <string>
#include <vector>
#include <functional>
#include <limits>

//...

using namespace std;

int main(){
    char ar_board[5][5]       = {0,}; // 
    char ar_words[50][10][10] = {0,}; // case, row, colum
    bool ar_result[50]        = {0,};

    int C;
    cin >> C;

    int N; // count of words, 1 <= N <= 10
    
    for(int n=0; n<C; ++n)
    {
        for (int i=0; i<5; ++i)
            for (int j=0; j<5; ++j)
                scanf("%d", &ar_board[i][j]); 

        scanf("%d", &N);

        
        
        //
        double f_min_avg = numeric_limits<double>::max();
        
        for (int i=0; i<N-L+1; ++i)
        {
            //
            double f_sum = 0;
            int j       = 0;
            
            // sum costs with team members - 1 
            for (j=i; j<i+L-1; ++j)
                f_sum += ar_costs[j];
            
            // sum costs with extended team members
            for (int k=i+L-1; k<N; ++k)
            {
                
                f_sum += ar_costs[k];
                
                int n_len   = k-i+1;
                double f_avg = f_sum / n_len;
                
                //cout << i << ' ' << j << endl;
                //cout << i << ' ' << j << ' ' << k << ' ' << n_len << endl;
                
                if (f_avg < f_min_avg)
                    f_min_avg = f_avg;
            }
        }

        ar_min_avg_costs[n] = f_min_avg;
    }

    for (int n=0; n<C; ++n)
    {
        cout << fixed << setprecision( 11 ) << ar_min_avg_costs[n] << endl;
    }

  
    return 0;
}
