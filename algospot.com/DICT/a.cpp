//https://algospot.com/judge/problem/read/DICT

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
int N, M; // a개수, b개수
char INPUT[100][21] = {0,}; // 이름

int CACHE[1001][101] = {0,}; // 용량, 서수 : 최대절박도

// return: 절박도
int get_result(int capacity, int idx)
{

}

void make_items_packed(vector<string> & items, int capacity, int idx)
{

}

int main() {
    
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(INPUT, 0, sizeof(INPUT));
        memset(CACHE, -1, sizeof(CACHE));

        scanf("%d", &N);
        scanf("%d", &M);

        printf("%s\n", "");
    }
  
    return 0;
}
