- graphs can be 
  - weighted (or) unweighted
  - directed (or) undirected

# Concepts
- Topological sorting
  - Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.
  - Topological order is defined for directed graph, because a undirected edge is itself a cycle!!
  - Topological order exists iff G is DAG
  - Topological order is not unique.
  - Find any topological order of G
    1) using stack(or linked list) and dfs. [topo_sort_dfs.cpp](topo_sort_dfs.cpp), O(n + m) time, O(n) space
    2) (it is a BFS kind of algo) Kahn's algo
      - DAG has at least one vertex v such that indegree(v) = 0
      - DAG has at least one vertex v such that outdegree(u) = 0
      - [topo_sort_khans_algo.cpp](topo_sort_khans_algo.cpp) is my code.

- Cycle detection
  - In directed graphs
    - Method 1:
      - A directed graph G has a cycle in it iff there is a back edge [i.e., a node points to one of its ancestors in a DFS tree] present in the graph.
      - [back_edge_detection.cpp](back_edge_detection.cpp) uses above fact. n+m time and 2n + O(n) space
    - Method 2:
      - Using khans algo, we can detect there is a cycle.
      - [cycle_detection_topo_sort.cpp](cycle_detection_topo_sort.cpp)