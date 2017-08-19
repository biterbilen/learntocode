# Abstract

- MST(minimum spanning tree)를 구하는 알고리즘이다.
- spanning tree는 graph의 모든 vertex를 연결한 tree이다.
  tree이기 때문에 cycle은 없다.
- graph의 spanning tree는 여러개 일 수 있다.

# Keyword

```cpp
vector<pair<int, int> > adj[],
prim, totalcost, vector<pair<int, int> > mst,
vector<bool> added, vector<int> min_weight, vector<int> parent

```

# Idea

- MST에 포함된 녀석들의 이웃들중 아직 MST에 포함되지 않은 정점까지의
  거리가 가장 최소인 녀석을 찾아서 MST에 포함한다. MST는 비어 있고
  최초 시작점은 그 정점까지 거리가 0이니까 무조건 포함이다.

# Time Complexity

- O(|V|^2+|E|)
- dense graph인 경우 |E| = |V|^2이다. 따라서 시간 복잡도는 O(|V|^2)가 될 수
  있다. kruskal algorithm은 O(|E|lg|E|)이기 때문에
  prim algorithm이 dense graph의 경우 더욱 효율적일 수 있다.
  
# Space Complexity

- O(1)

# Reference

- [prim algorithm in 2 minutes at youtube](https://www.youtube.com/watch?v=cplfcGZmX7I)
- [Greedy Algorithms | Set 5 (Prim’s Minimum Spanning Tree (MST))](http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/)
