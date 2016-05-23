#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#include <cstddef>

const int INF = 987654321;

using namespace std;

int C;// case
int N, W; // 개수, 용량
char I_NAME[100][20] = {0,}; // 이름
int I_WEIGHT[100] = {0,}; // 무게
int I_NEED[100] = {0,}; // 절박도

int CACHE[1001][101] = {0,}; // 용량, 서수

void dump(int A[], int N)
{
    for (int i=0; i<N; ++i)
        printf("%d ", A[i]);
    printf("\n");
}

void dump(char A[][20], int N)
{
    for (int i=0; i<N; ++i)
        printf("%s ", A[i]);
    printf("\n");
}

// return: 절박도
int get_result(int capacity, int idx)
{
    printf("%d %d\n", capacity, idx);
    
    // base condition
    if (idx >= N) return 0;
    if (capacity <= 0) return 0;

    // memoization
    int & r = CACHE[capacity][idx];
    if (r >= 0) return r;

    // recursion
    // 이번 물건을 삽입한 경우 삽입하지 않은 경우
    r = max(get_result(capacity, idx+1),
            get_result(capacity - I_WEIGHT[idx],
                       idx+1) + I_NEED[idx]);
    
    return r;
}

int main() {
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(I_NAME, 0, sizeof(I_NAME));
        memset(I_WEIGHT, -1, sizeof(I_WEIGHT));
        memset(I_NEED, -1, sizeof(I_NEED));
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%d", &N);
        scanf("%d", &W);

        for(int i=0; i<N; ++i)
        {
            scanf("%s", &I_NAME[N][0]);
            scanf("%d", &I_WEIGHT[N]);
            scanf("%d", &I_NEED[N]);
        }
        // dump(I_NAME, N);
        // dump(I_WEIGHT, N);
        // dump(I_NEED, N);
        
        // printf("%d\n", get_result(W, 0));
    }
  
    return 0;
}
