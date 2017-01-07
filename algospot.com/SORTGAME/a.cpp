// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/SORTGAME
#include <cstdio>
#include <map>
#include <vector>

int N;

std::map<std::vector<int>, int> BFS;

// make BFS tree for 8 numbers
// 
void BuildBFS() {

  
}

int Solve(const std::vector<int>& v) {

  int n = v.size();
  std::vector<int> fixed(n);

  for (int i = 0; i < n; ++i) {
    int smaller = 0;
    for (int j = 0; j < n; ++i) {
      if (v[j] < v[i])
        ++smaller;
    }
    fixed[i] = smaller;
  }

  return BFS[fixed];
}

int main() {

  int T;
  scanf("%d", &T);

  BuildBFS();

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> v(N);

    for (int i = 0; i < N; ++i) {
      scanf("%d", &v[0]);
    }
    
    printf("%d", Solve(v));    
  }


  return 0;

}


