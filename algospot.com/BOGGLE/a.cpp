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

void dump_board(char board[][5])
{
    for(int i=0; i< 5; ++i)
        cout << board[i] << endl;
}

void dump_words(int C, int N[], char words[][10][10])
{
    for(int i=0; i<C; ++i)
    {
        for(int j=0; j<N[i]; ++j)
        {
            cout << words[i][j] << endl;
        }
    }
}

void dump_result(int C, int N[], char words[][10][10], bool result[])
{
    for(int i=0; i<C; ++i)
    {
        for(int j=0; j<N[i]; ++j)
        {
            cout << words[i][j]
                 << " "
                 << (result[i] ? "YES" : "NO")  
                 << endl;
        }
    }
}

int main() {
    const int CASE_MAX = 50;
    
    char ar_board[5][5]             = {0,}; //
    int ar_N[CASE_MAX]              = {0,};
    char ar_words[CASE_MAX][10][10] = {0,}; // case, row, colum
    bool ar_found[CASE_MAX]         = {0,};

    int C;
    cin >> C;

    int N; // count of words, 1 <= N <= 10
    
    for(int c=0; c<C; ++c)
    {
        for (int i=0; i<5; ++i)
            for (int j=0; j<5; ++j)
                scanf("%c", &ar_board[i][j]); 

        scanf("%d", &ar_N[c]);
        for (int i=0; i<N; ++i)
            scanf("%s", ar_words[c][i]);
    }

    

    // dump result
    dump_result(C, ar_N, ar_words, ar_found);
  
    return 0;
}
