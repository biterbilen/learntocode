// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/GRADUATION

#include <cstdio>
#include <vector>
#include <algorithm>

#define MAXN 987654321
int N, K, M, L;

std::vector<int> prerequisites[12];
std::vector<int> classes[10];

void PrintSpace(int m) {
  for (int i = 0; i < m; ++i) {
    printf(" ");
  }

}

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

// prerequisites of sbj is done???
bool CanLearn(int sbj, const std::vector<int>& taken) {
  // already learned ???
  if (std::find(taken.begin(), taken.end(), sbj) != taken.end())
    return false;  

  // inspect prerequisites
  for (int i = 0; i < prerequisites[sbj].size(); ++i) {
    int p = prerequisites[sbj][i];
    if (std::find(taken.begin(), taken.end(), p) == taken.end())
      return false;
  }
  return true;
}

//
int GetMinClass(int m, std::vector<int>& taken) {
  // base condition
  if (taken.size() >= K)
    return 0;
  if (m >= M)
    return MAXN;
  PrintSpace(m);
  printf(" %d : ", m);
  PrintVInt(taken);

  // recursion
  int r = MAXN;
  for (int i = 0; i < classes[m].size(); ++i) {
    int sbj = classes[m][i];
    // printf("   %d %d\n", sbj, CanLearn(sbj, taken));
    
    if (CanLearn(sbj, taken) == false)
      continue;
    //
    taken.push_back(sbj);
    r = std::min(r, 1 + GetMinClass(m + 1, taken));
    taken.pop_back();
  }

  return r;
}

int solve() {
  std::vector<int> taken;
  return GetMinClass(0, taken);
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    // init global variables
    for (int i = 0; i < 12; ++i) {
      prerequisites[i].clear();
    }
    for (int i = 0; i < 10; ++i) {
      classes[i].clear();
    }
    
    scanf("%d %d %d %d", &N, &K, &M, &L);

    // input for subjects of N numbers
    for (int i = 0; i < N; ++i) {
      int cnt = 0;
      scanf("%d", &cnt);
      for (int j = 0; j < cnt; ++j) {
        int subject = 0;
        scanf("%d", &subject);
        prerequisites[i].push_back(subject);
      }
    }

    // input for classes of M numbers
    for (int i = 0; i < M; ++i) {
      int cnt = 0;
      scanf("%d", &cnt);
      for (int j = 0; j < cnt; ++j) {
        int subject = 0;
        scanf("%d", &subject);
        classes[i].push_back(subject);
      }
    }

    // solve it
    int r = solve();
    if (r < MAXN)
      printf("%d\n", r);
    else
      printf("IMPOSSIBLE\n");    
  }
  
  return 0;
}
