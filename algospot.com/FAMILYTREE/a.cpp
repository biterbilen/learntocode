// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/FAMILYTREE

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>

#define MAXINT 2147483647
int N, Q;

struct RMQT {
  int m_n;
  std::vector<int> m_range_min;
  explicit RMQT(const std::vector<int>& v) {
    m_n = v.size();
    m_range_min.resize(m_n * 4);
    init(v, 0, m_n-1, 1);
  }
  int init(const std::vector<int>& v, int left, int right, int node) {
    // base condition
    if (left == right)
      return m_range_min[node] = v[left];
    // recursion
    int mid = (left + right) / 2;
    int left_min = init(v, left, mid, node * 2);
    int right_min = init(v, mid + 1, right, node * 2 + 1);
    return m_range_min[node] = std::min(left_min, right_min);
  }
  int query(int left, int right, int node, int node_left, int node_right) {
    // base condition
    if (right < node_left || left > node_right)
      return MAXINT;
    if (left <= node_left && node_right <= right)
      return m_range_min[node];

    // recursion
    int node_mid = (node_left + node_right) / 2;
    return std::min(query(left, right, node*2, node_left, node_mid),
                    query(left, right, node*2+1, node_mid+1, node_right));
  }
  int query(int left, int right) {
    return query(left, right, 1, 0, m_n - 1);
  }
};

void solve(std::vector<int> * h, int from, int to) {
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &Q);
    std::vector<int> H(N, 0);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &H[i]);
    }
    // printf("after rmqt.init\n");
    for (int i = 0; i < Q; ++i) {
      int q0, q1;
      scanf("%d %d", &q0, &q1);
      solve(&H, q0, q1);
    }
  }
  //
  return 0;
}
