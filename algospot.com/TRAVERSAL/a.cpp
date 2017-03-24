// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/TRAVERSAL

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int N;

// make slice vector from a to b of v
std::vector<int> slice(const std::vector<int>& v, int a, int b) {
    return std::vector<int>(v.begin() + a, v.begin() + b);
}

void Solve(const std::vector<int>& p_order, 
  const std::vector<int>& i_order) {
   // base condition
   if (p_order.size() == 0)
       return;

   // recursion
   int root = p_order[0];
   auto it  = std::find(i_order.begin(), i_order.end(), root);
   std::vector<int> sub_p_order = slice();
   std::vector<int> sub_i_order = slice();

   Solve(sub_p_order, sub_i_order);
   Solve(sub_p_order, sub_i_order);
   printf("%d ", root);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        scanf("%d", &N);
        std::vector<int> p_order(N);
        std::vector<int> i_order(N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &p_order[i]);
        for (int i = 0; i < N; ++i)
            scanf("%d", &i_order[i]);
        Solve(p_order, i_order);
    }

    return 0;
}

