#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

int get_white_cnt(char boards[][20], int H, int W)
{
    int r = 0;
    
    for (int i=0; i<H; ++i)
    {
        for (int j=0; j<W; ++j)
        {
            if (boards[i][j] == '.')
                r++;
        }
    }

    return r;
}

int result(char boards[][20], int H, int W, int h, int w, int n_white)
{
    // base condition

    // there is no way 
    if (n_white % 3 != 0)
        return 0;
    // found a way
    if (n_white == 0)
        return 1;
    // exceed dimension without finding a way
    if (h>=H && w>=W)
        return 0;
    //
    char b = boards[h][w];
    if (b == '#' || b == '+') return 0;

    // recursion
    
    
    
    return 0;
}

int main() {
    
    int C; // number of cases
    int H; // height
    int W; // width
    char boards[25][20]; // boards consists of # .

    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        scanf("%d", &H);
        scanf("%d", &W);

        for (int i=0; i<H; ++i)
        {
            scanf("%s", boards[i]);
        }
        /* dump(boards, H, W); */

        printf("%d\n",
               result(boards, H, W, 0, 0,
                      get_white_cnt(boards, H, W)));
    }
  
    return 0;
}
