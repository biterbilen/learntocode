//https://algospot.com/judge/problem/read/CANADATRIP

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>

using namespace std;

int N;

// 
int main() {
    
    int T; // number of T
    scanf("%d", &T);
    
    for(int t=0; t<T; ++t)
    {
        scanf("%d", &N);
        vector<pair<double, double> > pos;

        for (int i=0; i<N; ++i)
        {
            double x, y;
            scanf("%lf", &x);
            scanf("%lf", &y);
            pos.push_back(make_pair(x, y));
        }

        precal(pos);

        printf("%0.2lf\n", optimize());
    }

    return 0;
}
