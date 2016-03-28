#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void dump(char boards[][20], int H, int W)
{
    printf("=====\n");
    for (int i=0; i<H; ++i)
    {
        for (int j=0; j<W; ++j)
        {
            printf("%c ", boards[i][j]);
        }
        printf("\n");
    }
    printf("=====\n");
}

/* int n; //     */
/* double dist[MAX][MAX]; //               */
/* I I p a t h                  */
/* I I v i s i t e d                  */
/* II currentLength             */
/* II                               . */
/* double shortestPath(vector<int>& path, vector<bool>& visited, */
/* double currentLength) { */
/* II     :                         . */
/* if (path.sizeO = n) */
/* return currentLength + dist[path[0]][path.back()]; */
/* double ret = INF; / /           //                . */
/* for(int next = 0; next < n; ++next) { */
/* if(visited[next]) continue; int here = path.backO; path push_back(next); visited[next] = true; */
/* II                               . double cand = shortestPath(path, visited, currentLength + */
/* ret = min( et, cand); visited[next] = false; path.pop_back(); */
/* } */
/* return ret; */

int shortest_path(int costs[][25], int N,
                  int visits[][25], int path[], int cur_idx,
                  int cur_cost, int todo)
{
    int prv_idx = path[cur_idx-1];

    // base condition
    if (todo >= N)
        return cur_cost + costs[0][
    for (int next=0; next<N, ++next)
    {
        if (visits[prev][next]) continue;
        int here = prev;
        
    }

    // recursion
    int r = INT_MAX;
    
    return r; 
}                 

int main() {
    
    int C; // number of cases
    int N; // number of nodes
    int costs[25][25]; // cost for x, y
    bool visits[25][25];
    int path[25];        // sales man path

    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(costs, -1, sizeof(costs));
        memset(visits, false, sizeof(visits));
        memset(path, -1, sizeof(path));
        
        scanf("%d", &N);

        for (int i=0; i<N; ++i)
        {
            for (int j=0; j<N; ++j)
            {
                scanf("%d", &costs[j][i]);
            }
        }
        /* dump(boards, H, W); */

        printf("%d\n",
               shortest_path(costs, N, visits, path, 0, N*N));
    }
  
    return 0;
}
