#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define INF 99

void dump(int c[])
{
    for (int i=0; i<16; ++i)
    {
        printf("%d ", c[i]); 
    }
    printf("\n");
}

bool is_finished(int c[])
{
    for (int i=0; i<16; ++i)
    {
        if (c[i] != 12)
            return false;
    }
    return true;
}

void push(int switches[][5], int clocks[], int idx)
{
    for (int s=0; s<10; ++s)
    {
        for (int c=0; c<5; ++c)
        {
            if (switches[s][c] >= 0)
            {
                clocks[c] += 3;
                if (clocks[c] == 15)
                    clocks[c] = 3;
            }
        }
    }
}

int get_min_cnt(int switches[][5], int clocks[], int idx)
{

    // base condition
    if (idx >= 16) return is_finished(clocks) ? 0 : INF;
    
    int r = INF;

    // recursion
    for (int n=0; n<4; ++n)
    {
        r = min(r, n + get_min_cnt(switches, clocks, idx+1));
        push(switches, clocks, idx);
    }
    
    return r;
}

int main() {
    
    int C; // number of cases
    int H; // height
    int W; // width
    int switches[10][5] = {{  0,  1,  2, -1, -1},
                          {  3,  7,  9, 11, -1},
                          {  4, 10, 14, 15, -1},
                          {  0,  4,  5,  6,  7},
                          {  6,  7,  8, 10, 12},
                          {  0,  2, 14, 15, -1},
                          {  3, 14, 15, -1, -1},
                          {  4,  5,  7, 14, 15},
                          {  1,  2,  3,  4,  5},
                          {  3,  4,  5,  9, 13}}; //
    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        int clocks[16];

        for (int i=0; i<16; ++i)
        {
            scanf("%d", &clocks[i]);
        }

        /* dump(clocks); */

        printf("%d\n", get_min_cnt(switches, clocks, 0));        

        /* printf("--------------------\n"); */
    }
  
    return 0;
}
