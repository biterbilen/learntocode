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

int result(char boards[][20], int H, int W)
{
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

        printf("%d\n", result(boards, H, W));
    }
  
    return 0;
}
