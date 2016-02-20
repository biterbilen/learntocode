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

float get_avg_cost(int v[], int idx_first, int idx_last)
{
    float f_sum = 0;
    for (int n=idx_first; n<idx_last; ++n)
    {
        f_sum += v[n];
    }
    return f_sum / (idx_last - idx_first);
}


int main(){
    
    float ar_min_avg_costs[1000] = {0,};
    int ar_costs[1000] = {0,};
    //int ar_days[1000] = {0,};

    int C;
    cin >> C;

    int N; // 6
    int L; // 3

    for(int n=0; n<C; ++n)
    {
         scanf("%d", &N);
         scanf("%d", &L);
         for (int y=0; y<N; ++y)
             scanf("%d", &ar_costs[y]); 

         //
        float f_min_avg = numeric_limits<float>::max();

        for (int i=0; i<N-L+1; ++i)
        {
            for (int j=i+L; j<N+1; ++j)
            {
                //cout << i << ' ' << j << endl;
                float f = get_avg_cost(ar_costs, i, j);
                //cout << i << ' ' << j << ' ' << f << endl;
                if (f < f_min_avg)
                    f_min_avg = f;
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
