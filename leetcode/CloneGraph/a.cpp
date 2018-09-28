/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/clone-graph/description/

#include <cstdio>
#include <vector>
#include <unordered_set>

struct UndirectedGraphNode {
  int label;
  std::vector<UndirectedGraphNode*> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
 public:
  std::unordered_set<std::pair<int, int>> m_set;
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode* u) {
    UndirectedGraphNode* rslt;
    if (u == NULL)
      return rslt;
    m_set.push(u);
    rslt = new UndirectedGraphNode(u->label);
    for (auto v : u->neighbors) {
      if (
    }    
    return rslt;
  }
};


int main() {
  UndirectedGraphNode* u new UndirectedGraphNode(0);
  u->neighbors.push_back(new UndirectedGraphNode(1));
  
  Solution s;
  UndirectedGraphNode* r = s.cloneGraph(u);
  return 0;
}
