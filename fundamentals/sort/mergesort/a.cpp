#include <cstdio>
#include <cstdlib>
#include <vector>

void rand_vector(std::vector<int>& v) {
  int n = v.size();
  for (int i = 0; i < n; ++i)
    v[i] = rand() % n;
}

void print_vector(const std::vector<int>& v) {
  for (int a : v)
    printf("%d ", a);
  printf("\n");    
}

//
// l
//       r
//   m
// 1 3 4 5
//         i
//     j
//         k
void merge(int step, std::vector<int>& v, std::vector<int>& w,
           int l, int m, int r) {
  int i = l, j = m+1, k = l;
  while (i <= m && j <= r) {
    if (v[i] <= v[j])
      w[k++] = v[i++];
    else
      w[k++] = v[j++];
  }
  if (i > m) {
    for (int n = j; n <= r; ++n)
      w[k++] = v[n];
  } else {
    for (int n = i; n <= m; ++n)
      w[k++] = v[n];
  }
  std::copy(w.begin()+l, w.begin()+r+1, v.begin()+l);

  // for (int i = 0; i < step; ++i)
  //   printf("=");
  // printf("%d %d | ", l, r);
  // for (int i = l; i <= r; ++i)
  //   printf("%d ", w[i]);
  // printf("\n");
  
}

//         r
//     m
// l
// 1 4 7 0 9
//       i
//         j

//         k
// 0 1 4 7 
void msort(int step, std::vector<int>& v, std::vector<int>& w,
           int l, int r) {
  for (int i = 0; i < step; ++i)
    printf("_");
  printf("%d %d | ", l, r);
  for (int i = l; i <= r; ++i)
    printf("%d ", v[i]);
  printf("\n");

  // base condition
  if (l >= r)
    return;

  // recursion
  int m = (l+r)/2;
  msort(step+1, v, w, l, m);
  msort(step+1, v, w, m+1, r);
  merge(step, v, w, l, m, r);
}


int main() {
  std::vector<int> v(10);
  rand_vector(v);
  // std::vector<int> v = {1, 7, 4, 0, 9};
  
  print_vector(v);

  std::vector<int> w = v;
  msort(0, v, w, 0, v.size()-1);
  print_vector(v);

  return 0;
}
