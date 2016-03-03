#include <iostream>
#include <string>

using namespace std;

bool is_found_syllable(char board[][6], char word[], int r, int c, int idx)
{
    if (r < 0 || r >= 5) return false;
    if (c < 0 || c >= 5) return false;
    if (word[idx] == 0) return true;

    if (board[r][c] == word[idx])
        return
            is_found_syllable(board, word, r  , c-1, idx+1) ||
            is_found_syllable(board, word, r+1, c-1, idx+1) ||
            is_found_syllable(board, word, r+1, c  , idx+1) ||
            is_found_syllable(board, word, r+1, c+1, idx+1) ||
            is_found_syllable(board, word, r  , c+1, idx+1) ||
            is_found_syllable(board, word, r-1, c+1, idx+1) ||
            is_found_syllable(board, word, r-1, c  , idx+1) ||
            is_found_syllable(board, word, r-1, c-1, idx+1);
                              
    return false;
}

bool is_found_word(char board[][6], char word[])
{
    int r = 2;
    int c = 2;
    int idx = -1;
    
    return
        is_found_syllable(board, word, r  , c-1, idx+1) ||
        is_found_syllable(board, word, r+1, c-1, idx+1) ||
        is_found_syllable(board, word, r+1, c  , idx+1) ||
        is_found_syllable(board, word, r+1, c+1, idx+1) ||
        is_found_syllable(board, word, r  , c+1, idx+1) ||
        is_found_syllable(board, word, r-1, c+1, idx+1) ||
        is_found_syllable(board, word, r-1, c  , idx+1) ||
        is_found_syllable(board, word, r-1, c-1, idx+1);
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

        scanf("%d", &N);
        
        for (int n=0; n<N; ++n)
        {
            char ar_words[10][11] = {0,}; // row, colum
            bool b_found = false;

            scanf("%s", ar_words[n]);
            b_found = is_found_word(ar_board, ar_words[n]);
            
            cout << ar_words[n]
                 << " "
                 << (b_found ? "YES" : "NO")  
                 << endl;
        }       
    }
  
    return 0;
}
