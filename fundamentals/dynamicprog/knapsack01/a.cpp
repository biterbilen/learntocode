// Copyright (C) 2018 by iamslash


int solve(const int[] w, const int[] v, int c, int n) {
  // base condition
  if (n < 0 || c == 0)
    return 0;
  // recursion
  if (w[n] > c)
    return solve(w, v, c, n-1);
  return std::max(v[n-1] + solve(w, v, c-[n-1], n-1),
                  solve(w, v, c, n-1);
}

int main() {
  int V[] = {60, 100, 120};
  int W[] = {10, 20, 30};
  int C   = 50;
  int N   = 3;

  printf("%d\n", solve(W, V, C, N-1));  
  return 0;
}
