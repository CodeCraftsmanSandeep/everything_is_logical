# Concepts
1) Graph traversals
  - DFS
  - BFS
2) Topological sorting
  - DFS based approach
  - Kahn's algorithm
3) Cycle detection
  - back edge detection in undirected graphs
4) DSU
  - path compression
5) Connectivity
  - SCC (Strongly Connected Components)
6) Articulation point (or) cut vertices
7) Euler paths and circuits
8) Hamiltonian



-------



- graphs can be 
  - weighted (or) unweighted
  - directed (or) undirected


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

- Disjoint set union (dsu)
  - [GFG article](https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/)
  - Union by rank 
    - logn time 
  - Union by size
  - Path compression
    - nearly constant time 
    -  the final amortized time complexity is O(α(n)), where α(n) is the inverse Ackermann function, which grows very steadily (it does not even exceed for n<10600  approximately).


- **Connectivity**
  - Undirected graphs
    - A undireted graph G is connnected graph if the number of connected components in G = 1
  - Directed graphs
    - SCC (Strongly Connected Components) [article](https://www.geeksforgeeks.org/strongly-connected-components/)
      - A strongly connected component of a directed graph is a maximal subgraph where every pair of vertices is mutually reachable.
    - A directed graph G is stronlgy connected graph if the number of strongly connected components in G = 1
    - Kosaraju's algorithm
      - can be used to solve both problems of (Q1. Finding the number of SCC's) and (Q2. Print all SCC's)
        - [Find number of SCC's ?](https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)
          - [My code](kosarajus_algo.cpp)
          - Time: 2 times DFS, O(n + m)
          - Space: O(n + m) for transpose of the graph + O(n) for stack + O(m) recursive stack for dfs
    - Find the number of SCC's
    - Print all SCC's
-------
#### **Articulation point (or) cut vertex**:
- A vertex v is an articulation point (also called cut vertex) if removing v increases the number of connected components.
- 

-------
- **Euler path**:
  - In graph theory, an Eulerian trail (or Eulerian path) is a trail in a finite graph that visits every edge exactly once (allowing for revisiting vertices)
- **Eulerian circuit or Eulerian cycle**
  - An Eulerian circuit or Eulerian cycle is an Eulerian trail that starts and ends on the same vertex.
  - **Euler's theorem**:
    - A connected graph has an Euler cycle if and only if every vertex has even degree.
  - A graph which has eulerian cycle is called Euler graph.
- For the existence of Eulerian trails it is necessary that zero or two vertices have an odd degree. If there are no vertices of odd degree, all Eulerian trails are circuits. If there are exactly two vertices of odd degree, all Eulerian trails start at one of them and end at the other. A graph that has an Eulerian trail but not an Eulerian circuit is called semi-Eulerian.
- An undirected graph has euler cycle if
  1) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges). 
  2) All vertices have even degree.
- An undirected graph has euler path if:
  1) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges). 
  2) zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph with no self-loops)
- [Check if a graph is euler (or) semi-euler graph?](https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1)
  - [My code](euler_graphs_detection.cpp)
    - O(n + m) time, O(n) space
- [Find the euler cycle (or) euler path if exists?]()

-------
- Hamiltonian

-------
--

