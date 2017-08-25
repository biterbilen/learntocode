# Abstract

- 프로그래밍 훈련을 위해 유용한 문제들을 체계적으로 분류해서 정리해 본다.

# Contents

* [materials](#materials)
* [online judges](#online-judges)
* [references](#references)
* [datatype range](#datatype-range)
* [algorithm proof](#algorithm-proof)
* [algorithm analysis](#algorithm-analysis)
* [NP Completeness](#NP-Completeness)
* [problems](#problems)
  * [Bitmask](#bitmask)
  * [Partial Sum](#partial-sum)
  * [Partial Min](#partial-min)
  * [Disjoint Set](#disjoint-set)
  * [List](#list)
  * [Stack](#stack)
  * [Queue](#queue)
  * [Deque](#deque)
  * [Map (Hash)](#map-(hash))
  * [String](#string)
  * [Tree](#tree)
  * [Segment Tree](#segment-tree)
  * [Graph](#graph)
  * [Network Flow](#network-flow)
  * [Min Cost Max Flow](#min-cost-max-flow)
  * [Sort](#sort)
  * [Search](#search)
  * [Numerical Analysis](#numerical-analysis)
  * [Number Theory](#number-theory)
  * [Computational Geometry](#computational-geometry)
  * [Recursion](#recursion)
  * [Brute Force](#brute-force)
  * [Divide And Conquor](#divide-and-conquor)
  * [Binary Search](#binary-search)
  * [Exhaustive Search](#exhaustive-search)
  * [Dynamic Programming](#dynamic-programming)
  * [Dynamic Programming Technique](#dynamic-programming-technique)
  * [Greedy](#greedy)
  * [Combinatorial Search](#combinatorial-search)
  * [Optimization Problems To Decision Problems](#optimization-problems-to-decision-problems)
  * [Algorithm Game](#algorithm-game)

# materials

- 알 | [알고리즘문제해결전략](http://book.algospot.com/)
- 백 | [백준온라인강좌](https://code.plus/courses/1)
- I | [interactive coding challenges](https://github.com/donnemartin/interactive-coding-challenges)
- C | [cracking the coding interview](https://www.amazon.com/Cracking-Coding-Interview-Programming-Questions/dp/0984782850/ref=zg_bs_132570011_1?_encoding=UTF8&psc=1&refRID=3XW52MQJXCEJEWNTYJQ4)
- G | [geeksforgeeks](http://www.geeksforgeeks.org/)
  - [Top 10 algorithms in Interview Questions](http://www.geeksforgeeks.org/top-10-algorithms-in-interview-questions/)
- [elements of programming interviews in c++](https://www.amazon.com/Elements-Programming-Interviews-Insiders-Guide/dp/1479274836)
- [Coding Interview Questions](https://www.amazon.com/Coding-Interview-Questions-Narasimha-Karumanchi-ebook/dp/B01MTCOXPV/ref=sr_1_2?s=books&ie=UTF8&qid=1500287754&sr=1-2&keywords=coding+interview+questions)
- [Programming Interviews Exposed](https://www.amazon.com/Programming-Interviews-Exposed-Secrets-Landing-ebook/dp/B008SGNJOW/ref=pd_cp_351_2?_encoding=UTF8&psc=1&refRID=A7HZWTE0YTRTEPZ9RZXM)
- [programming challenges](https://www.amazon.com/Programming-Challenges-Contest-Training-Computer-ebook/dp/B008AFF2ZU/ref=sr_1_1?ie=UTF8&qid=1500287669&sr=8-1&keywords=programming+challenges)
- [programming pearls](https://www.amazon.com/Programming-Pearls-2nd-Jon-Bentley/dp/0201657880/ref=sr_1_1?s=books&ie=UTF8&qid=1473590537&sr=1-1&keywords=programming+pearls)
- [Dynamic Programming for Coding Interviews: A Bottom-Up approach to problem solving](https://www.amazon.com/Dynamic-Programming-Coding-Interviews-Bottom-Up-ebook/dp/B01N4P93O7/ref=sr_1_1?ie=UTF8&qid=1500344454&sr=8-1&keywords=dynamic+programming+for+coding+interviews)

# online judges

- [leetcode](https://leetcode.com/)
- [geekforgeeks practice](http://www.practice.geeksforgeeks.org/)
- [hackerrank](https://www.hackerrank.com/)
- [백준온라인](https://www.acmicpc.net/)
- [알고스팟](https://algospot.com/)
- [codeforces](http://codeforces.com/)
- [topcoder](https://arena.topcoder.com)
- [programming-challnges](http://www.programming-challenges.com/)

# references

## video

- [백준온라인강좌](https://code.plus/courses/1)
  - 유료이긴하지만 다양한 문제풀이 강좌가 있다.
- [c++로 배우는 알고리즘 동영상](https://www.youtube.com/watch?v=mzM3S5FtKuw&list=PLl5LpJCoD2mCIRn0Fkt8z07EK320ZmHgY)
- [Sedgewick Algorithms I](https://www.youtube.com/user/algorithmscourses/playlists?shelf_id=2&view=50&sort=dd)
- [Sedgewick Algorithms II](https://www.youtube.com/user/algorithmscourses/playlists?flow=list&shelf_id=3&view=50)
- [michael sambol short videos](https://www.youtube.com/channel/UCzDJwLWoYCUQowF_nG3m5OQ)
- [Curtis Lassam short videos](https://www.youtube.com/watch?v=r4r1DZcx1cM&list=PLmVb1OknmNJuC5POdcDv5oCS7_OUkDgpj&index=22)
  - trie, bloom filters, Endainness, scrum
- [mycodeschool @ youtube](https://www.youtube.com/user/mycodeschool/featured)

## Book

- [알고리즘문제해결전략](http://book.algospot.com/)
- [c로 배우는 알고리즘](http://www.yes24.com/24/goods/18005?scode=032&OzSrank=1)
- [Algorithms 4th Edition by Robert Sedgewick and Kevin Wayne](http://algs4.cs.princeton.edu/home/)
- [The Algorithm Design Manual 2nd Edition by Steven S Skiena](http://www.amazon.com/Algorithm-Design-Manual-Steven-Skiena/dp/1848000693/ref=sr_1_1?s=books&ie=UTF8&qid=1460283355&sr=1-1&keywords=the+algorithm+design+manual)
- [Data Structures and Algorithm Analysis in C 2nd Edition by Mark A. Weiss ](https://users.cs.fiu.edu/~weiss/)
- [Introduction to Algorithms, 3rd Edition (MIT Press)](http://www.amazon.com/Introduction-Algorithms-3rd-MIT-Press/dp/0262033844/ref=sr_1_1?s=books&ie=UTF8&qid=1460283565&sr=1-1&keywords=introduction+to+algorithms)

# tools

- [codeshare](https://codeshare.io/)
- [coding.sh](http://coding.sh/)
- [pramp](https://www.pramp.com/)

# datatype range

| Type      | Typical Bit Width | Typical Range                   |
| :-------- | :-----------------| :-----------------------------: |
| char      | 1byte             | -128 to 127                     |
| unsigned char      | 1byte             | 0 to 255                     |
| short int | 2byte             | -32,768 to 32,767               |
| unsigned short int | 2byte             | 0 to 65,535               |
| int       | 4byte             | -2,147,483,648 to 2,147,483,647                        |
| unsigned int       | 4byte             | 0 to 4,294,967,295                        |
| long long | 8byte             | –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 |
| unsigned long long | 8byte             | 0 ~ 18,446,744,073,709,551,615 |
| float | 4byte             | -3.4E +/- 38 ~ 3.4E +/- 38 (7 digits) |
| double | 8byte             | -1.7E +/- 308 ~ 1.7E +/- 308 (15 digits) |

# algorithm proof

- Mathmatical Induction
- Proof by Contradiction
- Direct Proof
- Contrapositive Proof
- Existence Proof
- Proof by Counter Example
- if and only if proof

# algorithm analysis

- The RAM Model of Computation
- The asymptotic analysis of worst-case complexity
- notations
  - f(n) = O(g(n)) means c · g(n) is an upper bound on f (n). Thus there exists some constant c such that f (n) is always ≤ c · g(n), for large enough n (i.e. , n ≥ n0 for some constant n0).
  - f(n) = Ω(g(n)) means c · g(n) is a lower bound on f(n). Thus there exists some constant c such that f(n) is always ≥ c · g(n), for all n ≥ n0.
  - f(n) = Θ(g(n)) means c1 · g(n) is an upper bound on f(n) and c2 · g(n) is a lower bound on f(n), for all n ≥ n0. Thus there exist constants c1 and c2 such that f (n) ≤ c1 · g(n) and f (n) ≥ c2 · g(n). This means that g(n) provides a nice, tight bound on f(n).
  - ![Graphic examples of the Θ, O, and Ω notations.](https://raw.githubusercontent.com/iamslash/dsalgorithm/master/_img/Graphic%20examples%20of%20the%20%CE%98%2C%20O%2C%20and%20%E2%84%A6%20notations.jpeg)
  - ![Algorithm Graphs](https://raw.githubusercontent.com/iamslash/dsalgorithm/master/_img/alg_graph.jpeg)


# NP Completeness

- P
  - P means the existence of an algorithm for the task that runs in polynomial time.
- NP
  - set of decision problems for which any yes instance has some 'proof' that verifies the problem to be yes in polynomial step
- NP Hard
  - A decision problem H is NP-hard when for every problem L in NP,
 there is a polynomial-time reduction from L to H
- NP Complete
  - A decision problem C is NP-complete if:
    - C is in NP, and
    - Every problem in NP is reducible to C in polynomial time.

# Problems

## Bitmask
  - [알](fundamentals/bitmask/bitmaskset/) | [bitmask set](doc/bitmask_set.md)
  - [알](fundamentals/bitmask/sieveoferatosthenes/) | [sieve of eratosthenes](doc/bitmask_sieve_of_eratosthenes.md)
  - [알](fundamentals/bitmask/15puzzle/) | [15 puzzle](doc/bitmask_15_puzzle.md)
  - [알](fundamentals/bitmask/priorityqueue/) | [priority queue with O(1)](doc/bitmask_priority_queue.md)
  - [알](fundamentals/bitmask/maximalstableset/) | [maximal stable set★](doc/bitmask_maximal_stable_set.md)
  - [알](algospot.com/GRADUATION/) | [GRADUATION](https://algospot.com/judge/problem/read/GRADUATION)
  - 알 | [Bit Twiddling Hacks](http://graphics.stanford.edu/~seander/bithacks.html)

## [Partial Sum](doc/partial_sum.md)
  - 백 | [구간 합 구하기 4](https://www.acmicpc.net/problem/11659)
  - 백 | [나머지 합](https://www.acmicpc.net/problem/10986)
  - 백 | [구간 합 구하기 5](https://www.acmicpc.net/problem/11660)
  - 백 | [구간 합 구하기](https://www.acmicpc.net/problem/2042)
  - 백 | [구간 합 구하기 2](https://www.acmicpc.net/problem/10999)
  - 백 | [스위치](https://www.acmicpc.net/problem/1395)
  - 백 | [구간 합 구하기](https://www.acmicpc.net/problem/2042)
  - 백 | [구간 합 구하기 3](https://www.acmicpc.net/problem/11658)
  - [알](fundamentals/partialsum/partialsum/) | [partial sum, range sum](doc/partial_sum_range_sum.md)
  - [알](fundamentals/partialsum/variance/) | [variance](doc/partial_sum_variance.md)
  - [알](fundamentals/partialsum/gridsum/) | [grid sum](doc/partial_sum_grid_sum.md)
  - [알](fundamentals/partialsum/rangewhichisclosetozero/) | [range which is close to zero](doc/partial_sum_range_which_is_close_to_zero.md)
  - [알](algospot.com/CHRISTMAS/) | [CHRISTMAS](https://algospot.com/judge/problem/read/CHRISTMAS)

## [Partial Min](doc/partial_min.md)
  - 백 | [최소값과 최대값](https://www.acmicpc.net/problem/2357)
  - 백 | [최소값 찾기](https://www.acmicpc.net/problem/11003)

## Disjoint Set
  - [알](fundamentals/disjointset/unionfind/) | [union-find (merge-find)](doc/disjointset_unionfind.md)

## List
  - 알 | dynamic array
  - 알 | singly linked list
  - 알 | doubly linked list
  - 알 | [JOSEPHUS](https://algospot.com/judge/problem/read/JOSEPHUS)
  - 알 | [Dancing Links](https://arxiv.org/abs/cs/0011047)

## Stack 
  - 알 | [FENCE](http://algospot.com/judge/problem/read/FENCE)
  - 알 | [BRACKETS2](http://algospot.com/judge/problem/read/BRACKETS2)
  - G | [Longest valid Parentheses](http://www.practice.geeksforgeeks.org/problem-page.php?pid=1247)
  - G | [Maximum of minimum for every window size](http://www.practice.geeksforgeeks.org/problem-page.php?pid=170)

## Queue
  - 알 | [JOSEPHUS](https://algospot.com/judge/problem/read/JOSEPHUS)
  - 알 | [ITES](http://algospot.com/judge/problem/read/ITES)
    - online algorithm
    - offline algorithm

## Deque
  - G | [Level order traversal in spiral form](http://www.practice.geeksforgeeks.org/problem-page.php?pid=700201)

## Map (Hash)
  - 알 | seperate chaining
  - 알 | linear probing (open addressing)
  - 알 | quadratic probing
  - 알 | double hashing
  - 알 | consistent hashing
  - 알 | [A Simple Fraction](http://www.practice.geeksforgeeks.org/problem-page.php?pid=514)

## String
  - 백 | [KMP는 왜 KMP일까?]()
  - 백 | [찾기]()
  - 백 | [광고]()
  - 백 | [Cubeditor]()
  - 백 | [Boggle]()
  - 백 | [전화번호 목록]()
  - 백 | [문자열 집합 판별]()
  - 백 | [돌연변이]()
  - 백 | [접미사 배열]()
  - 백 | [접미사 배열 2]()
  - 백 | [접미사 배열 1]()
  - 백 | [서로 다른 부분 문자열의 개수]()
  - 백 | [서로 다른 부분 문자열의 개수 2]()
  - 백 | [Suffix Array]()
  - 백 | [Cubeditor]()
  - 백 | [공통 부분 문자열]()
  - 백 | [Hidden Password]()
  - 백 | [가장 긴 팰린드롬 부분 문자열]()
  - 알 | search with naive algorithm
  - 알 | search with kmp algorithm★
    - needle, haystack, begin, matched, pi[]
    - O(|N| + |H|)
  - 알 | [NAMING](http://algospot.com/judge/problem/read/NAMING)
  - 알 | [PALINDROMIZE](http://algospot.com/judge/problem/read/PALINDROMIZE)
  - 알 | [JAEHASAFE](http://algospot.com/judge/problem/read/JAEHASAFE)
  - 알 | suffix array★
    - [Manber, Udi; Myers, Gene (1990). Suffix arrays: a new method for on-line string searches](http://webglimpse.net/pubs/suffix.pdf)
  - 알 | get suffix array using naive algorithm
    - O(N^2lgN)
  - 알 | get suffix array using manber myers algorithm
    - sa[], group[], t
    - O(N(lgN)^2)
  - 알 | suffix array search
  - 알 | circular string
  - 알 | the number of different substrings
  - 알 | [HABIT](http://algospot.com/judge/problem/read/HABIT)
  - 알 | Boyer Moore algorithm
    - [Boyer, Robert S.; Moore, J Strother (October 1977). "A Fast String Searching Algorithm."](https://www.cs.utexas.edu/users/moore/publications/fstrpos.pdf)
  - 알 | [Kasai, T. et al., "Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its Applications"](http://alumni.cs.ucr.edu/~rakthant/cs234/01_KLAAP_Linear%20time%20LCP.PDF)
    - O(|N| + lg|H|)
  - 알 | [Rabin-Karp algorithm](https://en.wikipedia.org/wiki/Rabin%E2%80%93Karp_algorithm)
  - 알 | suffix
  - 알 | Aho–Corasick algorithm
    - children, fail, terminal, output, insert, compute_fail_func, search

## [Tree](doc/tree.md)
  - 백 | [트리 순회]()
  - 백 | [트리의 부모 찾기]()
  - 백 | [트리의 지름]()
  - 백 | [트리의 지름]()
  - 백 | [LCA]()
  - 백 | [정점들의 거리]()
  - 백 | [LCA 2]()
  - 백 | [도로 네트워크]()
  - 백 | [LCA 2]()
  - 알 | terms and definitions
    - node, edge
    - parent, child, sibling
    - ancestor, descendant
    - root, leaf
    - depth, height
  - 알 | [TRAVERSAL](http://algospot.com/judge/problem/read/TRAVERSAL)
  - 알 | [FORTRESS](http://algospot.com/judge/problem/read/FORTRESS)
  - 알 | binary search tree
  - 알 | red black tree (balanced binary search tree)
  - 알 | AVL tree (balanced binary search tree)
  - 알 | treap
    - insert, split, erase, merge
  - 알 | get kth element
  - 알 | get count of elements which are lesser than X
  - 알 | [NERD2](http://algospot.com/judge/problem/read/NERD2)
  - 알 | [INSERTION](http://algospot.com/judge/problem/read/INSERTION)
  - 알 | priority queue with heap
    - push_heap, pop_heap
  - 알 | [RUNNINGMEDIAN](http://algospot.com/judge/problem/read/RUNNINGMEDIAN)
  - 알 | rmq (range minimum query) with segment tree
  - 알 | get two smallest in a range
  - 알 | get the maximum frequency of occurrence in the range of ordered sequences
  - 알 | [MORDOR](http://algospot.com/judge/problem/read/MORDOR)
  - 알 | [FAMILYTREE](http://algospot.com/judge/problem/read/FAMILYTREE)
  - 알 | fenwick tree (binary indexed tree)
  - 알 | [MEASURETIME](http://algospot.com/judge/problem/read/MEASURETIME)★
  - 알 | union-find (merge-find)
    - union rank optimization
    - pass compression optimization
  - 알 | check the connectivity of a graph
  - 알 | track the largest set
  - 알 | [EDITORWARS](http://algospot.com/judge/problem/read/EDITORWARS)
  - 알 | trie [video](https://www.youtube.com/watch?v=aiy-uY8OB8g) [pdf](https://raw.githubusercontent.com/iamslash/dsalgorithm/master/_pdf/trie.pdf) 
    - TrieNode, children, terminal, insert, find
    - a tree whose key is a character for searching strings
    - use too much memory
  - 알 | triple array trie
    - use less memory than trie
  - 알 | suffix trie
    - a trie which saves suffix array but uses too much memeory.
  - 알 | suffix tree
    - a tree which saves suffix array and uses less memory. but time complexity of simple algorithm is O(N^2). suffix array is better.
  - 알 | radix tree (patricia tree)
    - compress trie like suffix tree.
  - 알 | [SOLONG](http://algospot.com/judge/problem/read/SOLONG)
  - 알 | Aho–Corasick algorithm★
    - children, fail, terminal, insert, fail, output, compute_fail, search
  - 알 | [NH](http://algospot.com/judge/problem/read/NH)

## Segment Tree
  - 백 | [히스토그램에서 가장 큰 직사각형]()
  - 백 | [가장 긴 증가하는 부분 수열 2]()
  - 백 | [가장 긴 증가하는 부분 수열 3]()
  - 백 | [굉장한 학생]()
  - 백 | [터보소트]()
  - 백 | [영화 수집]()
  - 백 | [공장]()
  - 백 | [나무 심기]()
  - 백 | [라운드 로빈 스케줄러]()
  - 백 | [불만 정렬]()
  - 백 | [음주 코딩]()
  - 백 | [사탕상자]()
  - 백 | [중앙값 측정]()
  - 백 | [순열]()
  - 백 | [조세퍼스 문제 2]()

## [Graph](doc/graph.md)
  - 백 | [DFS와 BFS]()
  - 백 | [연결 요소의 개수]()
  - 백 | [이분 그래프]()
  - 백 | [순열 사이클]()
  - 백 | [반복수열]()
  - 백 | [텀 프로젝트]()
  - 백 | [단지번호붙이기]()
  - 백 | [섬의 개수]()
  - 백 | [미로 탐색]()
  - 백 | [토마토]()
  - 백 | [다리 만들기]()
  - 백 | [줄 세우기]()
  - 백 | [문제집]()
  - 백 | [작업]()
  - 백 | [게임 개발]()
  - 백 | [임계경로]()
  - 백 | [네트워크 연결]()
  - 백 | [최소 스패닝 트리]()
  - 백 | [타임머신]()
  - 백 | [웜홀]()
  - 백 | [최소비용 구하기]()
  - 백 | [최소비용 구하기 2]()
  - 백 | [특정한 최단 경로]()
  - 백 | [최단경로]()
  - 백 | [경로 찾기]()
  - 백 | [플로이드]()
  - 백 | [플로이드 2]()
  - 백 | [케빈 베이컨의 6단계 법칙]()
  - 백 | [궁금한 민호]()
  - 백 | [운동]()
  - 백 | [타임머신]()
  - 백 | [오일러 회로]()
  - 백 | [Strongly Connected Component]()
  - 백 | [단절점]()
  - 백 | [단절선]()
  - 백 | [동치 증명]()
  - 백 | [도시 계획]()
  - 백 | [ATM]()
  - 백 | [교통 체계]()
  - 백 | [2-SAT - 1]()
  - 백 | [2-SAT - 2]()
  - 백 | [2-SAT - 3]()
  - 백 | [2-SAT - 4]()
  - 백 | [가위바위보]()
  - 백 | [사랑과 전쟁]()
  - 백 | [완벽한 선거!]()
  - 백 | [타워 디펜스]()
  - 알 | [terms and definitions](doc/graph_terms_and_definitions.md)
    - vertex, edge, directed graph, undirected graph, weighted graph, multi graph, simple graph
    - unrooted tree, bipartite graph, DAG (directed asyclick graph), simple path
    - cycle, circuit, adjacency list, adjacency matrix , sparse graph, dense graph, implicit graph
  - 알 | dfs (depth first search)
    - adj, visited, dfs, dfs_all
  - 알 | finding out two vertices are connected
    - dfs(u) and find out whether v is visited.
  - 알 | counting the number of components 
    - count the number of dfs in dfs_all.
  - 알 | [topological sort](doc/graph_topological_sort.md)
    - adj, visited, dfs, dfs_topological_sort, order
  - 알 | [DICTIONARY](http://algospot.com/judge/problem/read/DICTIONARY)
  - 알 | [eulerian circuit](doc/graph_eulerian_circuit.md)
    - adj, circuit, dfs_get_eulerian_circuit
  - 알 | [eulerian trail](doc/graph_eulerian_trail.md)
    - adj, trail, dfs_get_eulerian_circuit, dfs_get_eulerian_trail
  - 알 | [WORDCHAIN](http://algospot.com/judge/problem/read/WORDCHAIN)
  - 알 | [dfs spanning tree](doc/graph_dfs_spanning_tree.md)
    - tree edge, forward edge, back edge, cross edge
    - adj, discovered, finished, counter, dfs_spanning_tree
  - 알 | [proof of topological sort](doc/graph_proof_of_topological_srt.md)★
  - 알 | [check the cycle](doc/graph_check_the_cycle.md)
  - 알 | [cut vertex (articulation point)](doc/graph_cut_vertex.md)
    - biconnected components
    - adj, discovered, is_cut_vertex, counter, dfs_find_cut_vertex
  - 알 | [bridge](doc/graph_bridge.md)
    - adj, discovered, bridge, counter, dfs_find_bridge
  - 알 | [tarjan's algorithm](doc/graph_tarjan_algorithm.md)
    - scc (strongly connected components)
    - condensation
    - adj, scc_id, discovered, finished, stck, scc_counter, vertex_counter, dfs_scc, tarjan_scc
  - 알 | [topological sort of scc](doc/graph_topological_sort_of_scc)★
  - 알 | [GALLERY](http://algospot.com/judge/problem/read/GALLERY)
    - dominating set
    - unrooted tree
  - 알 | [MEETINGROOM](doc/algospot_MEETINGROOM.md)★
    - sat (SATisfiability, boolean satisfiability problem)
    - conjunctive normal form
    - 2-sat
    - implication graph
  - 알 | bfs (breadth first search)
    - adj, bfs, discovered, q, order
    - O(|V| + |E|) adjacency list
    - O(|V|^2) adjacency matrix
  - 알 | [bfs shortest path](doc/graph_bfs_shortest_path.md)
    - adj, get_shortest_path, bfs, distance, parent, q
  - 알 | [SORTGAME](http://algospot.com/judge/problem/read/SORTGAME)
  - 알 | [CHILDRENDAY](doc/algospot_CHILDRENDAY.md)★
  - 알 | [15 puzzle - bfs](doc/graph_15_puzzle_bfs.md)
    - State, get_adj, operator<, operator==, bitmask, move, get, set, swap, get_zero_idx, state_map, bfs
  - 알 | [15 puzzle - bfs bidrectional search](doc/graph_15_puzzle_bfs_bs.md)
    - State, get_adj, operator<, operator==, bitmask, move, get, set, swap, get_zero_idx, state_map, get_sign, incr, bfs_bs
  - 알 | [15 puzzle - bfs ids (iteratively deep searching)](doc/graph_15_puzzle_bfs_ids.md)
    - State, get_adj, operator<, operator==, bitmask, move, get, set, swap, get_zero_idx, best, dfs, ids
  - 알 | [HANOI4](http://algospot.com/judge/problem/read/HANOI4)
  - 알 | [Dijkstra algorithm](doc/graph_dijkstra.md)
    ```cpp
    vector<pair<int, int>> adj, dijkstra, dist, priority_queue<pair<int, int>> pq
    ```
    - O(|E|lg|V|)
  - 알 | [Dijkstra algorithm without priority queue](doc/graph_dijkstra_without_pq.md)
    ```cpp
    vector<pair<int, int>> adj, dijkstra, dist, visited
    ```
    - O(|V|^2 + |E|)
  - 알 | [ROUTING](http://algospot.com/judge/problem/read/ROUTING)
  - 알 | [FIRETRUCKS](http://algospot.com/judge/problem/read/FIRETRUCKS)
  - 알 | [NTHLON](http://algospot.com/judge/problem/read/NTHLON)★
  - 알 | [Bellman-Ford algorithm](doc/graph_bellman_ford.md)
    ```cpp
    vector<pair<int, int>> adj[], bellmanford, vector<int> upper, bool updated
    ```
    - O(|E||V|)
  - 알 | [TIMETRIP](http://algospot.com/judge/problem/read/TIMETRIP)
  - 알 | [Floyd algorithm](doc/graph_floyd.md)
    ```cpp
    adj[][], via[][], floyd, reconstruct
    ```
  - 알 | [DRUNKEN](http://algospot.com/judge/problem/read/DRUNKEN)
  - 알 | [PROMISES](http://algospot.com/judge/problem/read/PROMISES)
  - [알](fundamentals/graph/kruskal/) | [Kruskal's minimum spanning tree](doc/graph_kruskal.md)
    - adj, DisjointSet, kruskal, totalcost, mst, edges
    - O(|E|lg|E|)
  - [알](fundamentals/graph/prim/) | [Prim's minimum spanning tree](doc/graph_prim.md)
    - adj, prim, totalcost, mst, added, min_weight, parent
    - O(|V|^2+|E|), O(|V|^2)
  - 알 | [LAN](http://algospot.com/judge/problem/read/LAN)
  - 알 | [TPATH](http://algospot.com/judge/problem/read/TPATH)
  - 알 | [Ford-Fulkerson algorithm with adjacency matrix](doc/graph_ford_fulkerson.md)
    ```cpp
    capacity[][], flow[][],
    ford_fulkerson, parent, q
    ```
    - small one between O(|E|f) and O(|V||E|^2)
  - 알 | [Ford-Fulkerson algorithm with adjacency list](doc/graph_ford_fulkerson_adj_list.md)
    ```cpp
    capacity[][], Edge, add_edge, get_edge 
    ford_fulkerson, parent, q
    ```
    - small one between O(|E|f) and O(|V||E|^2)
  - 알 | [MILEAGE](http://algospot.com/judge/problem/read/MILEAGE)
  - 알 | [SAINTTAIL](http://algospot.com/judge/problem/read/SAINTTAIL)
  - 알 | [MATCHFIX](http://algospot.com/judge/problem/read/MATCHFIX)
  - 알 | [PROJECTS](http://algospot.com/judge/problem/read/PROJECTS)★
  - 알 | [bipartite matching](doc/graph_bipartite_matching.md)
    - adj[][], amatch, bmatch, visited, dfs, bipartite_match
    - O(|V||E|)
  - 알 | [TRAVELPICTURES](http://algospot.com/judge/problem/read/TRAVELPICTURES)
  - 알 | [DOMINOS](http://algospot.com/judge/problem/read/DOMINOS)
  - 알 | [BISHOPS](http://algospot.com/judge/problem/read/BISHOPS)
  - 알 | [TRAPCARD](http://algospot.com/judge/problem/read/TRAPCARD)★
  - 알 | [maxium independent set problem](doc/graph_max_independent_set.md)
  - 알 | [dinic algorithm](doc/graph_dinic.md)
    - O(|V|^2|E|)
  - 알 | [successive shortest path](doc/graph_successive_shortest_path.md)
  - 알 | [Kuhn–Munkres algorithm (hungarian algorithm)](doc/graph_hungarian.md)
  - 알 | vertex cover problem
    - Kőnig's theorem
  - 알 | Hopcroft-Karp algorithm
  
## [Network Flow](doc/network_flow.md)
  - 백 | [최대 유량]()
  - 백 | [열혈강호]()
  - 백 | [열혈강호 2]()
  - 백 | [열혈강호 3]()
  - 백 | [열혈강호 4]()
  - 백 | [축사 배정]()
  - 백 | [노트북의 주인을 찾아서]()
  - 백 | [소수 쌍]()
  - 백 | [상어의 저녁식사]()
  - 백 | [주차장]()
  - 백 | [학교 가지마!]()
  - 백 | [돌멩이 제거]()
  - 백 | [게시판 구멍 막기]()
  - 백 | [컨닝 2]()
  - 백 | [등번호]()
  - 백 | [N-Rook]()
  - 백 | [비숍2]()
  - 백 | [흔한 수열 문제]()
  - 백 | [Crucial Links]()
  - 백 | [돼지 잡기]()
  - 백 | [좀비 아포칼립스]()
  - 백 | [스타 대결]()
  - 백 | [No Smoking, Please]()
  - 백 | [천하제일 서든어택 대회]()
  - 백 | [도시 왕복하기]()
  - 백 | [숫자판 만들기]()
  - 백 | [틀렸습니다]()
  - 백 | [Fake scoreboard]()
  - 백 | [블럭 퍼즐]()
  - 백 | [체스판 2]()
  - 백 | [달리기]()
  - 백 | [빨간 선분 파란 선분]()

## Min Cost Max Flow
  - 백 | [책 구매하기]()
  - 백 | [책 구매하기 2]()
  - 백 | [책 구매하기 3]()
  - 백 | [열혈강호 5]()
  - 백 | [열혈강호 6]()
  - 백 | [선발 명단]()
  - 백 | [최고의 팀 만들기]()
  - 백 | [풍선]()
  - 백 | [경찰]()
  - 백 | [왕복 여행]()
  - 백 | [제독]()
  - 백 | [Concert Hall Scheduling]()
  - 백 | [Crazy Bits]()
  - 백 | [Job Postings]()
  - 백 | [제주도 관광]()
  - 백 | [칙칙폭폭]()
  - 백 | [Train Tickets]()
  - 백 | [Catering]()

## Sort
  - 백 | [수 정렬하기 2]()
  - 백 | [좌표 정렬하기]()
  - 백 | [좌표 정렬하기 2]()
  - 백 | [나이순 정렬]()
  - 백 | [국영수]()
  - 백 | [수 정렬하기 3]()
  - 백 | [카드]()
  - 백 | [K번째 수]()
  - 백 | [버블 소트]()
  - Selection Sort
  - Isnertion sort
  - Bubble Sort
  - Shell Sort
  - Quicksort
  - Radix Sort
  - Heapsort
  - Merge sort
  - External Sort
  - Binary Tree Sort
  - counting sort

## Search
  - Sequential Search with array
  - Sequential Search with linked list
  - Binary Search with array
  - Interpolation Search
  - Binary Tree Search 
  - Radix Tree Search
  - Radix Trie Search 
  - Hash Table Linear Probing Search
  - Hash Table Seperate Chaining Search
  - B-Tree Search
  - Red-Black Tree Search
  - AVL Tree Search

## Numerical Analysis
  - 알 | bisection method
  - 알 | [ROOTS](https://algospot.com/judge/problem/read/ROOTS)
  - 알 | [LOAN](https://algospot.com/judge/problem/read/LOAN)
  - 알 | [RATIO](https://algospot.com/judge/problem/read/RATIO)
  - 알 | ternary search
  - 알 | [FOSSIL](https://algospot.com/judge/problem/read/FOSSIL)
  - 알 | simpson's method

## [Number Theory](doc/number_theory.md)
  - 백 | [나머지]()
  - 백 | [최대공약수와 최소공배수]()
  - 백 | [최소공배수]()
  - 백 | [GCD 합]()
  - 백 | [진법 변환 2]()
  - 백 | [진법 변환]()
  - 백 | [2진수 8진수]()
  - 백 | [8진수 2진수]()
  - 백 | [-2진수]()
  - 백 | [Base Conversion]()
  - 백 | [소수 찾기]()
  - 백 | [소수 구하기]()
  - 백 | [골드바흐의 추측]()
  - 백 | [소인수분해]()
  - 백 | [팩토리얼]()
  - 백 | [팩토리얼 0의 개수]()
  - 백 | [조합 0의 개수]()
  - 백 | [곱셈]()
  - 백 | [제곱 ㄴㄴ 수]()
  - 백 | [행렬 덧셈]()
  - 백 | [두 용액]()
  - 백 | [행렬 제곱]()
  - 백 | [피보나치 수]()
  - 백 | [피보나치 수 2]()
  - 백 | [피보나치 수 3]()
  - 백 | [피보나치 수 6]()
  - 백 | [피보나치 수 4]()
  - 백 | [피보나치 수 5]()
  - 백 | [피보나치 수의 확장]()
  - 백 | [피사노 주기]()
  - 백 | [피보나치 수의 합]()
  - 백 | [피보나치 수의 제곱의 합]()
  - 백 | [홀수번째 피보나치 수의 합]()
  - 백 | [짝수번째 피보나치 수의 합]()
  - 백 | [피보나치 수와 최대공약수]()
  - 백 | [이항 계수 1]()
  - 백 | [이항 계수 2]()
  - 백 | [이항 계수 4]()
  - 백 | [이항 계수 5]()
  - 백 | [괄호]()
  - 백 | [GCD(n, k) = 1]()
  - 백 | [해의 개수]()
  - 백 | [이항 계수 3]()
  - 알 | prime number, composite number
  - 알 | prime factorization
  - 알 | sieve of eratosthenes
  - 알 | prime factorization with sive of eratosthenes
  - 알 | [PASS486](https://algospot.com/judge/problem/read/PASS486)
  - 알 | Euclidean algorithm
  - 알 | [POTION](https://algospot.com/judge/problem/read/POTION)
  - 알 | modular arithmetic
    - add, sub, mul
    - div
  - 알 | extended euclidean algorithm
  - 알 | chinese remainder theorem
  - 알 | lucas' theorem

## Computational Geometry
  - 알 | how much closer
  - 알 | dot product
  - 알 | cross product
  - 알 | line intersection
  - 알 | segment intersection
  - 알 | segment intersects (counter clock wise)
  - 알 | point to line
  - 알 | [PINBALL](https://algospot.com/judge/problem/read/PINBALL)
  - 알 | polygon area
  - 알 | polygon inside
  - 알 | [TREASURE](https://algospot.com/judge/problem/read/TREASURE)
  - 알 | [NERDS](https://algospot.com/judge/problem/read/NERDS)
  - 알 | convex hull (Gift Wrapping)
  - 알 | convex hull (Javis's March)
  - 알 | convex hull (Graham Scan)
  - 알 | plane sweeping, line sweeping
  - 알 | segment intersects (Shamos-Hoey)
  - 알 | segment intersects (Bentley-Ottmann)
  - 알 | rotating calipers
  - 알 | spline (bezier spline)
  - 알 | spline (hermite spline)
  - 알 | spline (B-spline, Basis spline)
  - 알 | closest pair of points
  - 알 | voronoi diagrams
  - 알 | further reading
    - [geometry algorithms](http://geomalgorithms.com/)

## Recursion
  - [C](crackingthecodinginterview/8.6_TowerOfHanoi/) | tower of hanoi
  - fibonacci number
  - pick k numbers from n numbers

## Brute Force
  - 알 | [BOGGLE](https://algospot.com/judge/problem/read/BOGGLE)
  - 알 | [PICNIC](https://algospot.com/judge/problem/read/PICNIC)
  - 알 | [BOARDCOVER](https://algospot.com/judge/problem/read/BOARDCOVER)
  - 알 | [CLOCKSYNC](https://algospot.com/judge/problem/read/CLOCKSYNC)

## Divide And Conquor
  - 백 | [숫자 카드](https://www.acmicpc.net/problem/10815)
  - 백 | [숫자 카드 2](https://www.acmicpc.net/problem/10816)
  - 백 | [배열 합치기](https://www.acmicpc.net/problem/11728)
  - 백 | [종이의 개수](https://www.acmicpc.net/problem/1780)
  - 백 | [하노이 탑 이동 순서](https://www.acmicpc.net/problem/11729)
  - 백 | [트리의 순회](https://www.acmicpc.net/problem/2263)
  - 백 | [쿼드트리](https://www.acmicpc.net/problem/1992)
  - 백 | [별찍기 - 10](https://www.acmicpc.net/problem/2447)
  - 백 | [별찍기 - 11](https://www.acmicpc.net/problem/2448)
  - 백 | [Z](https://www.acmicpc.net/problem/1074)
  - 백 | [버블 소트](https://www.acmicpc.net/problem/1517)
  - 백 | [가장 가까운 두 점](https://www.acmicpc.net/problem/2261)
  - 알 | The fast sum of a sequence
  - 알 | the fast square of a matrix
  - 알 | merge sort
  - 알 | quick sort
  - 알 | Karatsuba
  - 알 | [QUADTREE](https://algospot.com/judge/problem/read/QUADTREE)
  - 알 | [FENCE](https://algospot.com/judge/problem/read/FENCE)★ 
  - 알 | [FANMEETING](https://algospot.com/judge/problem/read/FANMEETING)★

## Binary Search
  - 백 | [랜선 자르기](https://www.acmicpc.net/problem/1654)
  - 백 | [나무 자르기](https://www.acmicpc.net/problem/2805)
  - 백 | [공유기 설치](https://www.acmicpc.net/problem/2110)
  - 백 | [중량제한](https://www.acmicpc.net/problem/1939)
  - 백 | [놀이 공원](https://www.acmicpc.net/problem/1561)
  - 백 | [사다리](https://www.acmicpc.net/problem/2022)
  
## [Exhaustive Search](doc/exhaustive_search.md)
  - 백 | [집합]()
  - 백 | [다음 순열]()
  - 백 | [이전 순열]()
  - 백 | [모든 순열]()
  - 백 | [순열의 순서]()
  - 백 | [날짜 계산]()
  - 백 | [리모컨]()
  - 백 | [1, 2, 3 더하기]()
  - 백 | [차이를 최대로]()
  - 백 | [외판원 순회 2]()
  - 백 | [로또]()
  - 백 | [숨바꼭질]()
  - 백 | [소수 경로]()
  - 백 | [DSLR]()
  - 백 | [퍼즐]()
  - 백 | [물통]()
  - 백 | [암호 만들기]()
  - 백 | [N-Queen]()
  - 백 | [스도쿠]()
  - 백 | [알파벳]()
  - 백 | [로또]()
  - 백 | [부분집합의 합]()
  - 백 | [수들의 합 2]()
  - 백 | [부분합]()
  - 백 | [소수의 연속합]()
  - 백 | [알고스팟]()
  - 백 | [부분집합의 합 2]()
  - 백 | [합이 0인 네 정수]()
  - 백 | [피자판매]()
  - 백 | [두 배열의 합]()

## [Dynamic Programming](doc/dynamic_programming.md)
  - C | [boolean evaluation](crackingthecodinginterview/8.14_BooleanEvaluation/a.cpp)
  - 백 | [1로 만들기]()
  - 백 | [2×n 타일링]()
  - 백 | [2×n 타일링 2]()
  - 백 | [1, 2, 3 더하기]()
  - 백 | [붕어빵 판매하기]()
  - 백 | [쉬운 계단 수]()
  - 백 | [오르막 수]()
  - 백 | [이친수]()
  - 백 | [스티커]()
  - 백 | [포도주 시식]()
  - 백 | [가장 긴 증가하는 부분 수열]()
  - 백 | [가장 큰 증가 부분 수열]()
  - 백 | [가장 긴 감소하는 부분 수열]()
  - 백 | [가장 긴 바이토닉 부분 수열]()
  - 백 | [연속합]()
  - 백 | [계단 오르기]()
  - 백 | [제곱수의 합]()
  - 백 | [타일 채우기]()
  - 백 | [파도반 수열]()
  - 백 | [합분해]()
  - 백 | [암호코드]()
  - 백 | [이동하기]()
  - 백 | [점프]()
  - 백 | [팰린드롬?]()
  - 백 | [팰린드롬 분할]()
  - 백 | [동전 1]()
  - 백 | [동전 2]()
  - 백 | [내리막 길]()
  - 백 | [파일 합치기]()
  - 백 | [행렬 곱셈 순서]()
  - 백 | [구간 나누기]()
  - 백 | [자두나무]()
  - 백 | [고층 빌딩]()
  - 백 | [타일 코드]()
  - 백 | [기타리스트]()
  - 백 | [1학년]()
  - 백 | [올바른 괄호 문자열]()
  - 백 | [같은 탑]()
  - 백 | [타일 채우기]()
  - 백 | [외판원 순회]()
  - 백 | [발전소]()
  - 백 | [계단 수]()
  - 백 | [박성원]()
  - 백 | [격자판 채우기]()
  - 백 | [연습시즌]()
  - 백 | [팰린드롬 경로]()
  - 백 | [개근상]()
  - 백 | [토끼의 이동]()
  - 백 | [공의 충돌]()
  - 백 | [축구]()
  - 백 | [복권]()
  - 백 | [주사위 게임]()
  - 백 | [조약돌 꺼내기]()
  - 백 | [카지노]()
  - 백 | [토러스]()
  - 백 | [연휴]()
  - 백 | [동전 뒤집기]()
  - 백 | [생태학]()
  - 백 | [랜덤 소트]()
  - 백 | [복권 + 은행]()
  - 백 | [파일 합치기]()
  - 백 | [문자열 자르기]()
  - 백 | [행렬 곱셈 순서]()
  - 백 | [탈옥]()
  - 백 | [수열의 OR 점수]()
  - 백 | [나무 자르기]()
  - 백 | [땅따먹기]()
  - 백 | [특공대]()
  - 알 | [overlapping subproblems](doc/dynamic_overlapping_subproblems.md)
  - 알 | [binomial coefficient](doc/dynamic_binomial_coefficient.md)
  - 알 | [JUMPGAME](https://algospot.com/judge/problem/read/JUMPGAME)
  - 알 | [WILDCARD](https://algospot.com/judge/problem/read/WILDCARD)
  - 알 | [optimal substructure](doc/dynamic_optimal_substructure.md)
  - 알 | [TRIANGLEPATH](https://algospot.com/judge/problem/read/TRIANGLEPATH)
  - 알 | [LIS](https://algospot.com/judge/problem/read/LIS)
  - 알 | [JLIS](https://algospot.com/judge/problem/read/JLIS)
  - 알 | [PI](https://algospot.com/judge/problem/read/PI)
  - 알 | [QUANTIZE](https://algospot.com/judge/problem/read/QUANTIZE)
  - 알 | [TILING2](https://algospot.com/judge/problem/read/TILING2)
  - 알 | [TRIPATHCNT](https://algospot.com/judge/problem/read/TRIPATHCNT)
  - 알 | [SNAIL](https://algospot.com/judge/problem/read/SNAIL)
  - 알 | [ASYMTILING](https://algospot.com/judge/problem/read/ASYMTILING)
  - 알 | [POLY](https://algospot.com/judge/problem/read/POLY)
  - 알 | [NUMB3RS](https://algospot.com/judge/problem/read/NUMB3RS)★
  - 알 | [Markov Chain](doc/dynamic_markov_chain.md)

## Dynamic Programming Technique
  - 백 | [트리의 독립집합]()
  - 백 | [토너먼트 만들기]()
  - 백 | [택배]()
  - 백 | [가로등 끄기]()
  - 백 | [사수아탕]()
  - 백 | [Sequence]()
  - 백 | [축구]()
  - 백 | [팰린드롬의 개수]()
  - 알 | [PACKING](https://algospot.com/judge/problem/read/PACKING)
  - 알 | [knapsack problem](doc/dynamic_knapsack_problem.md)
  - 알 | [OCR](https://algospot.com/judge/problem/read/OCR)★
  - Hidden Markov Model, HMM
    - Viterbi algorithm
  - 알 | [MORSE](https://algospot.com/judge/problem/read/MORSE)
  - 알 | [KLIS](https://algospot.com/judge/problem/read/KLIS)★
  - 알 | [DRAGON](https://algospot.com/judge/problem/read/DRAGON)
  - 알 | [memoization with non-integer parameters](doc/dynamic_memoization_with_non_integer.md)
  - 알 | [TSP](https://algospot.com/judge/problem/read/TSP1)
  - 알 | [ZIMBABWE](https://algospot.com/judge/problem/read/ZIMBABWE)★
  - 알 | [RESTORE](https://algospot.com/judge/problem/read/RESTORE)
  - 알 | [combinatorial game](doc/dynamic_combinatorial_game.md)
  - 알 | [TICTACTOE](https://algospot.com/judge/problem/read/TICTACTOE)
  - 알 | [NUMBERGAME](https://algospot.com/judge/problem/read/NUMBERGAME)
  - 알 | [BLOCKGAME](https://algospot.com/judge/problem/read/BLOCKGAME)
  - 알 | [iterative vs recursive](doc/dynamic_iterative_vs_recursive.md)
  - 알 | [SUSHI](https://algospot.com/judge/problem/read/SUSHI)
  - 알 | [GENIUS](https://algospot.com/judge/problem/read/GENIUS)

## Greedy
  - 알 | [knapsack problem](doc/dynamic_knapsack_problem.md)
  - 알 | [Kruskal's minimum spanning tree](doc/graph_kruskal.md)
  - 알 | [Prim's minimum spanning tree](doc/graph_prim.md)
  - 알 | [Dijkstra algorithm](doc/graph_dijkstra.md)
  - 백 | [동전 0](https://www.acmicpc.net/problem/11047)
  - 백 | [회의실배정](https://www.acmicpc.net/problem/1931)
  - 백 | [ATM](https://www.acmicpc.net/problem/11399)
  - 백 | [잃어버린 괄호](https://www.acmicpc.net/problem/1541)
  - 백 | [수 묶기](https://www.acmicpc.net/problem/1744)
  - 백 | [대회 or 인턴](https://www.acmicpc.net/problem/2875)
  - 백 | [30](https://www.acmicpc.net/problem/10610)
  - 백 | [병든 나이트](https://www.acmicpc.net/problem/1783)
  - 백 | [NMK](https://www.acmicpc.net/problem/1201)
  - 백 | [행렬](https://www.acmicpc.net/problem/1080)
  - 백 | [롤러코스터](https://www.acmicpc.net/problem/2873)
  - 알 | [greedy algorithm proof](doc/greedy_proof.md)
  - 알 | [optimization problem](doc/greedy_optimization_problem.md)
  - 알 | [meta heuristic](doc/greedy_metaheuristic.md)
  - [알](acmicpc.net/회의실배정/) | [회의실배정](https://www.acmicpc.net/problem/1931)
  - 알 | [activity selection problem](doc/greedy_activity_selection.md)
  - [알](algospot.com/MATCHORDER/) | [MATCHORDER](https://algospot.com/judge/problem/read/MATCHORDER)
  - [알](algospot.com/LUNCHBOX/) | [LUNCHBOX](https://algospot.com/judge/problem/read/LUNCHBOX)
  - [알](algospot.com/STRJOIN/) | [STRJOIN](https://algospot.com/judge/problem/read/STRJOIN)
  - 알 | [huffman code](doc/greedy_huffman_code.md)
  - [알](algospot.com/MINASTIRITH/) | [MINASTIRITH](https://algospot.com/judge/problem/read/MINASTIRITH)★

## [Combinatorial Search](doc/combinatorial_search.md)
  - 알 | [back tracking](doc/combinatorial_search_backtracking.md)
  - 알 | [heuristic](doc/combinatorial_search_heuristic.md)
  - 알 | [metaheuristic](doc/combinatorial_search_metaheuristic.md)
  - [알](algospot.com/TSP2/) | [TSP (dynamic programming, backtracking, simple pruning, simple heuristic pruning, greedy, swapping past paths pruning, MST heuristic pruning, MST heuristic pruning with memoization)](https://algospot.com/judge/problem/read/TSP2)
  - [알](algospot.com/BOARDCOVER2) | [BOARDCOVER2](https://algospot.com/judge/problem/read/BOARDCOVER2)
  - [알](algospot.com/ALLERGY) | [ALLERGY](https://algospot.com/judge/problem/read/ALLERGY)
  - [알](algospot.com/KAKURO2) | [KAKURO2](https://algospot.com/judge/problem/read/KAKURO2)
  - 알 | [CSP (constraint satisfaction problem)](doc/combinatorial_search_csp.md)
  - 알 | [artificial intelligence: a modern approach by stuart russel, peter norvig](https://www.amazon.com/Artificial-Intelligence-Approach-Stuart-Russell/dp/1292024208/ref=mt_paperback?_encoding=UTF8&me=)
    - combinatorial search를 잘 설명한 인공지능 교과서이다. java, python소스가 제공된다.
  - 알 | [sudoku](http://norvig.com/sudoku.html)
    - 스도쿠 퍼즐을 해결하는 방법에 관한 에세이이다.
    - [sudoku-kor](https://github.com/jongman/articles/wiki/solving-every-sudoku-puzzle)
  - 알 | [Georgia Tech's TSP](http://www.tsp.gatech.edu/)
    - TSP 해결 프로그램중 가장 강력한 Concorde가 기술되어
      있다. Concorde는 1000개의 도시를 갖는 입력을 10분만에 풀어낸다.

## [Optimization Problems To Decision Problems](doc/optimization_to_decision.md)
  - 알 | [DARPA](https://algospot.com/judge/problem/read/DARPA)
  - 알 | [ARCTIC](https://algospot.com/judge/problem/read/ARCTIC)
  - 알 | [CANADATRIP](https://algospot.com/judge/problem/read/CANADATRIP)
  - 알 | [WITHDRAWAL](https://algospot.com/judge/problem/read/WITHDRAWAL)

## [Algorithm Game](doc/algorithm_game.md)
  - 백 | [돌 게임](https://www.acmicpc.net/problem/9655)
  - 백 | [돌 게임 2](https://www.acmicpc.net/problem/9656)
  - 백 | [돌 게임 3](https://www.acmicpc.net/problem/9657)
  - 백 | [돌 게임 4](https://www.acmicpc.net/problem/9658)
  - 백 | [돌 게임 5](https://www.acmicpc.net/problem/9659)
  - 백 | [돌 게임 6](https://www.acmicpc.net/problem/9660)
  - 백 | [돌 게임 7](https://www.acmicpc.net/problem/9661)
  - 백 | [돌 게임 8](https://www.acmicpc.net/problem/9662)
  - 백 | [박스 나누기 게임](https://www.acmicpc.net/problem/11867)
  - 백 | [님 게임 2](https://www.acmicpc.net/problem/11868)
  - 백 | [님블](https://www.acmicpc.net/problem/11869)
  - 백 | [님 게임 홀짝](https://www.acmicpc.net/problem/11871)
  - 백 | [님 게임 나누기](https://www.acmicpc.net/problem/11872)
