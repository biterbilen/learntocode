// Copyright (C) 2018 by iamslash
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

// //    i
// // V: 5 2 6 1
// // M: 1 2 6
// // R:   1 1 0
// class Solution {
//  public:
//   std::vector<int> countSmaller(std::vector<int>& V) {
//     if (V.empty())
//       return {};
//     std::vector<int> M;
//     std::vector<int> rslt(V.size(), 0);
//     for (int i = V.size() - 1; i >= 0; --i) {
//       int n = V[i];
//       auto it = std::lower_bound(M.begin(), M.end(), n);
//       rslt[i] = it - M.begin();
//       M.insert(it, n);
//       printf("i: %d, n: %d, R: %d, M.size: %d\n", i, n, rslt[i], M.size());
//     }
//     return rslt;
//   }
// };

class Solution {
 public:
  void solve(std::vector<int>& indices, int beg, int end,
             std::vector<int>& counts, const std::vector<int>& V) {
    int cnt = end - beg;
    if (cnt > 1) {
      // devide
      int step = cnt / 2;
      int mid = beg + step;
      solve(indices, beg, mid, counts, V);
      solve(indices, mid, end, counts, V);

      // conquer
      std::vector<int> mrgd;
      mrgd.reserve(cnt);
      int idx1 = beg;
      int idx2 = mid;
      int smallcnt = 0;
      while ((idx1 < mid) || (idx2 < end)) {
        int n1 = indices[idx1];
        int n2 = indices[idx2];
        if ((idx2 == end) ||
            ((idx1 < mid) && (V[n1] <= V[n2]))) {
          mrgd.push_back(n1);
          counts[n1] += smallcnt;
          ++idx1;
        } else {
          mrgd.push_back(n2);
          ++smallcnt;
          ++idx2;
        }
      }             
      std::move(mrgd.begin(), mrgd.end(), indices.begin() + beg);
    }
  }
  std::vector<int> countSmaller(std::vector<int>& V) {
    if (V.empty())
      return {};
    int n = V.size();
    std::vector<int> indices(n, 0);
    std::vector<int> counts(n, 0);
    std::iota(indices.begin(), indices.end(), 0);
    solve(indices, 0, n, counts, V);
    return counts;
  }
};


// struct BSTNode{
//     int val;
//     int count;
//     BSTNode * left;
//     BSTNode * right;
//     BSTNode(int x):val(x),count(0),left(NULL),right(NULL){}
// };
// class Solution {
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int> result;
//         vector<int> count ;
        
//         vector<BSTNode *> node_vec;
//         for(int i= nums.size()-1; i >= 0;i--){
//             node_vec.push_back(new BSTNode(nums[i]));
//         }

//         count.push_back(0);
//         for(int i = 1 ; i < node_vec.size();i++){

//             int small_count = 0;
//             BST_insert(node_vec[0],node_vec[i],small_count);
//             count.push_back(small_count);
            
//         }
        
//         for(int i =node_vec.size()-1;i>= 0;i--){

//              delete node_vec[i];
//             result.push_back(count[i]);
           
//         }
        
//         return result;
//     }
// private:
//    void BST_insert(BSTNode *node,BSTNode * insert_node,int & small_count){
//         if(insert_node->val <= node->val){
            
//             node->count++;
//             if(node->left){
//                 BST_insert(node->left,insert_node,small_count);
//             }else{
//                 node->left = insert_node;
//             }
            
            
            
//         }else{
            
//             small_count += node->count+1;
//             if(node->right){
//                 BST_insert(node->right,insert_node,small_count);
                
//             }else{
//                 node->right = insert_node;
//             }
            
//         }
            
            
            
        
//     }
// };

int main() {
  std::vector<int> V = {5, 2, 6, 1};

  Solution sln;
  auto rslt = sln.countSmaller(V);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");

  // std::vector<int> M = {1};
  // auto lit = std::lower_bound(M.begin(), M.end(), 6);
  // auto uit = std::upper_bound(M.begin(), M.end(), 6);
  // printf("begin: %d end: %d e-b: %d lit: %d uit: %d\n",
  //        M.begin(), M.end(), M.end()-M.begin(), lit, uit);
  // printf("*lit: %d, diff: %d\n", *lit, lit-M.begin());
  // printf("*uit: %d, diff: %d\n", *uit, uit-M.begin());
  
  return 0;
}
