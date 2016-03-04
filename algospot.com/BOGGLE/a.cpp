#include <iostream>
#include <cstring>

char g_board[5][6]     = {0,};  //
char g_cache[11][5][5] = {0,};
char g_word[11]        = {0,}; // row, colum

using namespace std;

bool is_found_syllable(int r, int c, int idx)
{
    if (g_word[idx] == 0) return true;
    if (r < 0 || r >= 5) return false;
    if (c < 0 || c >= 5) return false;

    char& elem = g_cache[idx][r][c];
    
    if (elem != -1) return elem;
    if (g_board[r][c] != g_word[idx]) return elem = false;
    
    return elem =
        is_found_syllable(  r, c-1, idx+1) ||
        is_found_syllable(r+1, c-1, idx+1) ||
        is_found_syllable(r+1, c  , idx+1) ||
        is_found_syllable(r+1, c+1, idx+1) ||
        is_found_syllable(r  , c+1, idx+1) ||
        is_found_syllable(r-1, c+1, idx+1) ||
        is_found_syllable(r-1, c  , idx+1) ||
        is_found_syllable(r-1, c-1, idx+1);
}

bool is_found_word()
{
    int r = 2;
    int c = 2;
    int idx = -1;

    for (int r=0; r<5; ++r)
        for (int c=0; c<5; ++c)
        {
            if (is_found_syllable(r, c, 0))
                return true;
        }
    return false;
}

int main() {
    
    int C;
    cin >> C;
    int N;

    for(int c=0; c<C; ++c)
    {
        memset(g_board, 0, sizeof(g_board));
           
        for (int i=0; i<5; ++i)
            scanf("%s", g_board[i]);

        scanf("%d", &N);
        
        for (int n=0; n<N; ++n)
        {
            memset(g_word, 0, sizeof(g_word));
            memset(g_cache, -1, sizeof(g_cache));
            
            scanf("%s", g_word);
            
            cout << g_word
                 << " "
                 << (is_found_word() ? "YES" : "NO")  
                 << endl;
        }       
    }
  
    return 0;
}
