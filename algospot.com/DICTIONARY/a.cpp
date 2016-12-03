// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/DICTIONARY

#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>

int N;

// 알파벳의 각 글자에 대한 인접 행렬 표현 간선 (i, j)는 알파벳 i가
// j보다 앞에 와야 함을 나타낸다.
std::vector<std::vector<int> > adj;

// 주어진 단어들로부터 알파벳 간의 선후 관계 그래프를 생성한다.
void MakeGraph(const std::vector<std::string>& words) {
  adj = std::vector<int> >(26, std::vector<int>(26, 0));
  for (int j = 1; j < words.size(); ++j) {
    int i = j - 1;
    int len = std::min(words[i].size(), words[j].size());
    // words[i]가 words[j]앞에 오는 이유를 찾는다.
    for (int k = 0; k < len; ++k) {
      if (words[i][k] != words[j][k]) {

      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    printf("[%d] before init CACHE\n", t);
    
    // init variables;
    for (int i = 0; i < 101; ++i)
      for (int j = 0; j < 1001; ++j)
        CACHE[i][j] = -1;
    // memset(CACHE, -1, sizeof(int) * sizeof (CACHE));
    // printf(" %d\n", sizeof(CACHE));
    printf("[%d] after init CACHE\n", t);

    scanf("%d", &N);
    scanf("%d", &M);

    TrieNode tn;
    TrieNode* ptn = &tn;

    for (int i = 0; i < M; ++i) {
      char buf[128];
      scanf("%s", buf);
      ptn->Insert(buf, i);
    }
  
    ComputeFailFunc(ptn);
    int nc = 0;
    ComputeTransition(ptn, nc);

    printf("%d\n", Count(N, ptn));
  }
  //
  return 0;
}
