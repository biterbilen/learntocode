// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/SOLONG

#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

const int ALPHABETS = 26;

int N, M;
std::vector<std::pair<int, int>> DICT;
std::vector<std::string> DICTWORDS;
std::vector<int> PRIORITIES;
std::vector<std::string> WORDS;

void print_v_string(const std::vector<std::string>& v) {
  for (auto x : v)
    printf("%s ", x.c_str());
  printf("\n");
}

struct TrieNode {
  TrieNode* children[ALPHABETS];
  int terminal;  // dictword index for terminal node
  int first;  // first recommendation
  TrieNode() : terminal(-1), first(-1) {}
  ~TrieNode() {
    for (int i = 0; i < ALPHABETS; ++i) {
      if (children[i] != NULL)
        delete children[i];
    }
  }
  int to_num(char c) {
    return c - 'A';
  }
  void insert(const char * key, int idx) {
    // base condition
    if (first == -1)
      first = idx;
    if (*key == 0) {
      terminal = idx;
      return;
    }
    // recursion
    int next = to_num(*key);
    if (children[next] == NULL)
      children[next] = new TrieNode();
    children[next]->insert(key + 1, idx);
  }
  TrieNode* find(const char * key) {
    // base condition
    if (*key == 0)
      return this;
    // recursion
    int next = to_num(*key);
    if (children[next] == NULL)
      return this;
    return children[next]->find(key + 1);
  }
  int type(const char * key, int idx) {
    // base condition
    if (*key == 0)
      return 0;
    if (first == idx)
      return 1;
    // recursion
    return 1 + type(key + 1, idx);
  }
};

TrieNode* build_trie() {
  TrieNode* proot = new TrieNode();
  std::sort(DICTWORDS.begin(), DICTWORDS.end());
  for (int i = 0; i < DICTWORDS.size(); ++i) {
    proot->insert(DICTWORDS[i].c_str(), i);
  }
  return proot;
}

int count_keys(TrieNode* proot, const std::string& w, int idx) {
  TrieNode* pnode = proot->find(w.c_str());
  if (pnode == NULL || pnode->terminal == -1)
    return w.size();
  return pnode->type(w.c_str(), idx);
}

int solve() {
  int r = 0;
  TrieNode * proot = build_trie();
  for (int i = 0; i < WORDS.size(); ++i) {
    r += count_keys(proot, WORDS[i], i);
  }
  delete proot;
  return r + WORDS.size() - 1;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &M);
    DICT.clear(); DICT.resize(N);
    DICTWORDS.clear(); DICTWORDS.resize(N);
    PRIORITIES.clear(); PRIORITIES.resize(N);
    WORDS.clear(); WORDS.resize(M);
    for (int i = 0; i < N; ++i) {
      char buf[16];
      int priority;
      scanf("%s %d", buf, &priority);
      DICTWORDS[i] = buf;
      PRIORITIES[i] = priority;
      DICT[i] = std::make_pair(priority, i);
    }
    for (int i = 0; i < M; ++i) {
      char buf[16];
      scanf("%s", buf);
      WORDS[i] = buf;
    }
    // print_v_string(WORDS);
    printf("%d\n", solve());
  }
  return 0;
}
