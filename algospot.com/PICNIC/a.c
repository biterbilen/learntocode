#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void dump(int a[][2])
{
    for (int i=0; i<46; ++i)
    {
        if (a[i][0] == -1 && a[i][1] == -1)
            break;
        printf("%d %d\n", a[i][0], a[i][1]);
    }
    printf("\n");
        
}

// already exist in history ? 
bool touched_already(int a[][2], int p[2])
{
    for (int i=0; i<46; ++i)
    {
        if (a[i][0] == p[0] ||
            a[i][1] == p[0] ||
            a[i][0] == p[1] ||
            a[i][1] == p[1])
            return true;
    }
    return false;
}

int result(int a[][2], int idx, int N, int M)
{
    // base condition
    if (idx >= N/2) return 1;
    if (idx > 0 && touched_already(a, a[idx])) return 0;

    int r = 0;
    // sum
    for (int i=0; i<M; ++i)
    {
        r += result(a, idx+1, N, M);
    }

    return r;
}

int main() {
    
    int C; // number of cases
    int N; // number of students
    int M; // number of pairs
    // order of pairs, first student number, second student number
    int ar_pairs[46][2];

    scanf("%d", &C);
    
    for(int c=0; c<C; ++c)
    {
        memset(ar_pairs, -1, sizeof(ar_pairs));

        scanf("%d", &N);
        scanf("%d", &M);

        for (int i=0; i<M; ++i)
        {
            scanf("%d", &ar_pairs[i][0]);
            scanf("%d", &ar_pairs[i][1]);
        }

        printf("%d\n", result(ar_pairs, 0, N, M));

        // dump
        /* dump(ar_pairs); */        
    }

  
    return 0;
}
