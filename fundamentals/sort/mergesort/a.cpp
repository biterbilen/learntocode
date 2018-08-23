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

void merge(std::vector<int>& v, int l, int m, int r) {
  int i = l, j = m+1, k = l;
  std::vector<int> a(v.size());
  while (i <= m && j <= r) {
    if (v[i] <= v[j])
      a[k++] = a[i++];
    else
      a[k++] = a[j++];
  }
  if (i > m) {
    for (int n = j; n <= r; ++n)
      a[k++] = v[n];
  } else {
    for (int n = i; n <= m; ++n)
      a[k++] = v[n];
  }
  v.swap(a);  
}

void msort(int step, std::vector<int>& v, int l, int r) {
  // base condition
  if (l >= r)
    return;

  // recursion
  int m = (l+r)/2;
  msort(step+1, v, l, m);
  msort(step+1, v, m+1, r);
  merge(v, l, m, r);
}


int main() {
  std::vector<int> v(10);
  rand_vector(v);
  // std::vector<int> v = {1, 3, 5, 4};
  
  print_vector(v);

  msort(0, v, 0, v.size()-1);
  print_vector(v);

  return 0;
}
