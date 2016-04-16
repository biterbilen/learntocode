#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// // 두 긴 정수의 곱을 반환한다. 
// vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
//     int an = a.size(), bn = b.size();
//     // a 가 b 보다 짧을 경우 둘을 바꾼다
//     if(an < bn) return karatsuba(b, a);
//     // 기저 사례: a 나 b 가 비어 있는 경우
//     if(an == 0 || bn == 0) return vector<int>();
//     // 기저 사례: a 가 비교적 짧은 경우 O(n^2) 곱셈으로 변경한다.
//     if(an <= 50) return multiply(a, b);

//     int half = an / 2;
//     // a 와 b 를 밑에서 half 자리와 나머지로 분리한다
//     vector<int> a0(a.begin(), a.begin() + half);
//     vector<int> a1(a.begin() + half, a.end());
//     vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
//     vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
//     // z2 = a1 * b1
//     vector<int> z2 = karatsuba(a1, b1);
//     // z0 = a0 * b0
//     vector<int> z0 = karatsuba(a0, b0);
//     // a0 = a0 + a1; b0 = b0 + b1
//     addTo(a0, a1, 0); addTo(b0, b1, 0);
//     // z1 = (a0 * b0) - z0 - z2;
//     vector<int> z1 = karatsuba(a0, b0);
//     subFrom(z1, z0);
//     subFrom(z1, z2);
//     // ret = z0 + z1 * 10^half + z2 * 10^(half*2)
//     vector<int> ret;
//     addTo(ret, z0, 0); 
//     addTo(ret, z1, half);
//     addTo(ret, z2, half + half);
//     return ret;
// }

int get_hug_cnt(string & M, string & F)
{
    int r = 0;
    
    for(int i=0; i<=F.size()-M.size(); ++i)
    {
        for(int j=0; j<M.size(); ++j)
        {
            string s = F.substr(i, M.size());
            if (M.at(j) == 'M' && s.at(j) == 'M')
                break;
            if (j == M.size()-1)
                r++;
        }
    }
    
    return r;
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
