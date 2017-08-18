# abstract 

- 완전 탐색 알고리즘으로 문제를 해결할 때 주로 재귀호출을 이용해서 선택지를
  채워가는 형태로 구현한다. 이때 부분 답과 완성된 답의 집합을 search space(탐색공간)
  이라고 한다. 예를 들어 TSP에서 search space의 한 원소는 지금까지 방문한
  정점의 목록과 현재 위치로 구성된다. 
- 완전 탐색을 포함해서 유한한 크기의 탐색공간을 뒤지면서 답을 찾아내는 알고리즘들을
  combinatorial search(조합탐색)이라고 한다.
- combinatorial search는 dynamic programming, backtracking,
  simple pruning, simple heuristic pruning, greedy,
  swapping past paths pruning, mst heuristic pruning,
  partial dynamic programming 등으로 해결 할 수 있다. (예, TSP)
  
# reference

- [artificial intelligence: a modern approach by stuart russel, peter norvig](https://www.amazon.com/Artificial-Intelligence-Approach-Stuart-Russell/dp/1292024208/ref=mt_paperback?_encoding=UTF8&me=)
  - combinatorial search를 잘 설명한 인공지능 교과서이다. java, python소스가 제공된다.
