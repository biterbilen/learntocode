// Copyright (C) 2018 by iamslash

// https://www.hackerrank.com/challenges/kingdom-division/problem

#include <cstdio>
#include <vector>
#include <map>

int N;
const int MOD = 1000000007;
std::vector<std::vector<int>> adj;
int64_t CACHE[100005][2][2];

int64_t solve(int node, int parent, int idx, int color, int ally, int lv) {
  for (int i = 0; i < lv; ++i) {
    printf("-");
  }
  printf("%2d %2d %2d %2d %2d\n", node+1, parent+1, idx, color, ally);
  // base condition
  if (idx == adj[node].size())
    return ally;
  int child = adj[node][idx];
  if (child == parent)
    return solve(node, parent, idx+1, color, ally, lv+1);
  int64_t& r = CACHE[child][color][ally];
  if (r != -1)
    return r;
  // recursion
  r = (solve(child, node, 0, color, 1, lv+1) *
       solve(node, parent, idx+1, color, 1, lv+1)) % MOD;
  r += (solve(child, node, 0, 1-color, 0, lv+1) *
        solve(node, parent, idx+1, color, ally, lv+1)) % MOD;
  return r;
}

int main() {
  scanf("%d", &N);
  adj.resize(N);

  for (int i = 0; i < N; ++i) {
    CACHE[i][0][0] = CACHE[i][0][1] = CACHE[i][1][0] = CACHE[i][1][1] = -1;
        
  }
  
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;
    --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int64_t cnt = (2 * solve(0, 0, 0, 0, 0, 0)) % MOD;
  printf("%lld\n", cnt);

  return 0;
}
