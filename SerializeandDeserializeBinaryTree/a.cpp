// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/112/design/812/

#include <cstdio>
#include <string>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) :
      val(x), left(NULL), right(NULL);
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};


// 1,2,3,null,null,4,5
    
class Codec {
 public:

  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
        
  }

  TreeNode* _deserialize(const sdt::string& s, int i) {
    // base condition
    if (i >= s.size())
      return NULL;

    TreeNode* r = nullptr;;
    // recursion
    std::size_t f = data.find_first_of(',');
    if (f != sdt::size_t::npos) {
      r = new TreeNode(
    }
    
    return r;
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(std::string data) {
    return _deserialize(data, 0);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
  string s = "1,2,3,null,null,4,5";
  Codec c;
  printf("%s\n", c.serialize(c.deserialize(s)).c_str());

  return 0;
}
