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

// // dump functions
// void dump_board(char board[][6])
// {
//     for(int i=0; i<5; ++i)
//         cout << board[i] << endl;
// }

// void dump_words(int C, int N[], char words[][10][10])
// {
//     for(int i=0; i<C; ++i)
//     {
//         for(int j=0; j<N[i]; ++j)
//         {
//             cout << words[i][j] << endl;
//         }
//     }
// }

// void dump_result(int C, int N[], char words[][10][11], bool result[][10])
// {
//     for(int i=0; i<C; ++i)
//     {
//         for(int j=0; j<N[i]; ++j)
//         {
//             cout << words[i][j]
//                  << " "
//                  << (result[i][j] ? "YES" : "NO")  
//                  << endl;
//         }
//     }
// }

bool is_found(char board[][6], char word[])
{
    for (char * p = word; p != '\0'; ++p)
    {
        
    }

    return true;
}

int main() {
    const int CASE_MAX = 50;
    
    char ar_board[5][6]             = {0,}; //
    char ar_board_cache[5][5][6]    = {0,};
    
    int C;
    cin >> C;
    int N;

    for(int c=0; c<C; ++c)
    {
        for (int i=0; i<5; ++i)
            scanf("%s", ar_board[i]);

        // dump_board(ar_board);
        scanf("%d", &N);
        
        for (int n=0; n<N; ++n)
        {
            char ar_words[10][11] = {0,}; // row, colum
            bool b_found = false;

            scanf("%s", ar_words[n]);
            b_found = is_found(ar_board, ar_words[n]);
            
            cout << ar_words[n]
                 << " "
                 << (b_found ? "YES" : "NO")  
                 << endl;
        }       
    }

    // dump_result(C, ar_N, ar_words, ar_found);
  
    return 0;
}
