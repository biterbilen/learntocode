// Copyright (C) 2017 by iamslash

// Towers of Hanoi: In the classic problem of the Towers of Hanoi, you
// have 3 towers and N disks of different sizes which can slide onto
// any tower.The puzzle starts with disks sorted in ascending order of
// size from top to bottom (Le., each disk sits on top of an even
// larger one). You have the following constraints:
//
// (1) Only one disk can be moved at a time.
// (2) A disk is slid off the top of one tower onto another tower.
// (3) A disk cannot be placed on top of a smaller disk.
//
// Write a program to move the disks from the first tower to the last
// using Stacks.

#include <cstdio>
#include <vector>
#include <stack>

int N;
std::stack<int> TOWERS[3];

void solve(int n, int from, int to, int by) {
  // for (int i = n; i < N; ++i)
  //   printf(" ");
  // printf("%d %d %d %d\n", n, from, to, by);
  // base condition
  if (n == 0)
    return;
  // recursion
  solve(n - 1, from, by, to);
  int e = TOWERS[from].top();
  TOWERS[from].pop();
  TOWERS[to].push(e);
  for (int i = n; i < N; ++i)
    printf(" ");
  printf("[%d] => [%d], %d\n", from, to, e);
  solve(n - 1, by, from, to);
}

void print_towers() {
  for (int i = 0; i < 3; ++i) {
    printf("[%d] : ", i);
    while (TOWERS[i].size() > 0) {
      printf("%d ", TOWERS[i].top());
      TOWERS[i].pop();
    }
    printf("\n");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
  }
  for (int i = 0; i < N; ++i) {
    TOWERS[0].push(i);
  }
  solve(N, 0, 2, 1);
  print_towers();
  return 0;
}

