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

void qsort_h(int step, std::vector<int>& v, int l, int r) {
  int i = l, j = r;
  int pv = v[(l+r)/2];

  // for (int k = 0; k < step; ++k)
  //   printf("_");
  // printf("%d %d\n", l, r);
  
  // partition
  while (i <= j) {
    while (v[i] < pv)
      ++i;
    while (v[j] > pv)
      --j;
    if (i <= j)
      std::swap(v[i++], v[j--]);
  }

  if (l < j)
    qsort_h(step+1, v, l, j);
  if (i < r)
    qsort_h(step+1, v, i, r);

}

int part_l(std::vector<int>& v, int l, int r) {
  int pv = v[r];
  int rr = l;

  for (int i = l; i < r; ++i)
    if (v[i] < pv)
      std::swap(v[i], v[rr++]);
  std::swap(v[rr], v[r]);
  
  return rr;
}

void qsort_l(std::vector<int>& v, int l, int r) {
  // base condition
  if (l >= r)
    return;
  // recursion
  int p = part_l(v, l, r);
  qsort_l(v, l, p-1);
  qsort_l(v, p+1, r);
}

int main() {
  std::vector<int> v(10);
  rand_vector(v);
  // std::vector<int> v = {1, 3, 5, 4};
  
  print_vector(v);

  qsort_h(0, v, 0, v.size()-1);
  print_vector(v);

  qsort_l(v, 0, v.size()-1);
  print_vector(v);
  return 0;
}
