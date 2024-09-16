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

-------
#### Traversal techniques
- **DFS**
  - DFS tree:
    - A rooted directed tree which is constructed by doing DFS on a graph
  -  In the DFS tree, a vertex u is the parent of another vertex v, if v is discovered by u. 
  - DFS forest:
    - Collection of DFS trees
  - Tree edge:
    - Edge that is part of DFS tree, i.e edge which is used while performing DFS traversal.
  - Back Edge: 
    - An edge that connects a vertex to one of its ancestors in the DFS tree. Back edges indicate cycles and are used to help find strongly connected components.
  - Forward Edge: 
    - An edge that connects a vertex to one of its descendants, but is not part of the DFS tree.
  - Cross Edge: 
    - An edge that connects two vertices that are in different DFS trees (i.e., different branches) and do not have an ancestor-descendant relationship.
  - Cross edges do not affect the identification of SCCs since they don't form part of cycles. Therefore, while identifying SCCs, you only care about tree edges and back edges because they help identify cycles and strongly connected components.

-------
#### Topological sorting
- Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u-v, vertex u comes before v in the ordering.
- Topological order is defined for directed graph, because a undirected edge is itself a cycle!!
- Topological order exists iff G is DAG
- Topological order may not be unique.
- Find any topological order of G
  1) using stack(or linked list) and dfs. 
    - [topo_sort_dfs.cpp](topo_sort_dfs.cpp)
      - Time: O(n + m) for dfs
      - Space: O(n) auxillary space for stack
  2) (it is a BFS kind of algo) Kahn's algo
    - DAG has at least one vertex v such that indegree(v) = 0
    - DAG has at least one vertex v such that outdegree(u) = 0
    - [topo_sort_khans_algo.cpp](topo_sort_khans_algo.cpp) is my code.
      - Time: O(n + m) + O(n) + O(n + m)
      - Space: O(n) auxillary space for indegree array and queue.
    - Kahn's algo can also be used for cycle detection.
    - More than a algorithm, khan's algorithm is food for thought.
-------
#### Cycle detection
- Directed graphs:
  - DFS (or) BFS can be used to detect cycle.
    - Time: O(n)
      - Only O(n) time is required to find a cycle in an n-vertex graph, since at most n − 1 edges can be tree edges.
    - Space: O(n)
  - DSU can also be used to detect cycle.
    - [My code](cycle_detection_using_dsu.cpp)
      - Time: O((n)*alpha(n))
        - it is not n+m because atmost n edges needed to be merged to detect whether a 
      - Space: O(n) auxillary space for storing representatives.
  - Finding all cycles in a undirected graph is a hard problem
    - The largest cycle (hamiltonian cycle) bound is iteself is (n-1)!/2
    - Note: Each back edge need not nessarily correspond to one cycle in graph G.
      - Example: Complete graph K4
- In directed graphs
  - Method 1:
    - A directed graph G has a directed cycle in it iff there is a back edge [i.e., a node points to one of its ancestors in a DFS tree] present in the graph.
    - [back_edge_detection.cpp](back_edge_detection.cpp) uses above fact. 
      - Time: n+m
      - Space: 2n + O(n)
  - Method 2:
    - Using khans algo, we can detect there is a cycle.
    - [cycle_detection_topo_sort.cpp](cycle_detection_topo_sort.cpp)

-------
#### Disjoint set union (dsu)
- This is a spicy data structure.
- [GFG article](https://www.geeksforgeeks.org/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/)
- Union by rank 
  - O(logn) time 
- Union by size
- Path compression
  - nearly constant time 
  -  the final amortized time complexity is O(α(n)), where α(n) is the inverse Ackermann function, which grows very steadily (it does not even exceed for n<10600  approximately).
-------
#### Connectivity
- Undirected graphs
  - A undireted graph G is connnected graph if the number of connected components in G = 1
- Directed graphs
  - SCC (Strongly Connected Components) [article](https://www.geeksforgeeks.org/strongly-connected-components/)
    - A strongly connected component of a directed graph is a maximal subgraph where every pair of vertices is mutually reachable.
  - A directed graph G is stronlgy connected graph if the number of strongly connected components in G = 1
  - kosaraju's algo and Tarjan's algo can be used to solve both problems of (Q1. Finding the number of SCC's) and (Q2. Print all SCC's)
  - **Kosaraju's algorithm**
    - This algo has very interesting proof of correctness.
      - [Find number of SCC's ?](https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)
        - [My code](kosarajus_algo.cpp)
        - Time: 2 times DFS, O(n + m)
        - Auxillary space: O(n + m) for transpose of the graph + O(n) for stack + O(n) recursive stack for dfs
  - **Tarjan's algorithm**
    - Only one DFS tarversal of graph is needed.
    - [Find SCC's?](https://www.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1)
      - [My code](tarjans_algo.cpp)
        - Time: O(n + m) for dfs + O(n) for stack
        - Auxillary space: O(n) 

-------
#### Bridges (cut-edge) in a graph
- A edge e is called a bridge if by erasing the edge e, the number of connected components in graph increases by one.
- If you remove an edge from a graph, the maximum difference in the number of connected components is 1.
- [Check whether a edge is bridge edge (or) not?](https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1)
  - [is_bridge.cpp](is_bridge.cpp)
    - O(n+m) time for dfs
    - O(n) auxillary space
- [Find all bridges in a graph](https://leetcode.com/problems/critical-connections-in-a-network/description/). This algorithm is based on tarjan's algorithm technique.
  - [My code](find_bridges.cpp)
    - O(n + m) time for dfs
    - O(n) auxillary space for storing time, O(n) auxillary space for stack

-------
#### Articulation point (or) cut vertex:
- A vertex v is an articulation point (also called cut vertex) if removing v increases the number of connected components.
- [Find all articulation points](https://www.geeksforgeeks.org/problems/articulation-point2616/1)
  - [My code](articulation_points.cpp) (code using tarjans algo technique)
    - O(|V| + |E|) time
    - O(|V|) auxillary space
- In DFS tree, a vertex u is an articulation point if one of the following two conditions is true. 
  1) u is the root of the DFS tree and it has at least two children. 
  2) u is not the root of the DFS tree and it has a child v such that no vertex in the subtree rooted with v has a back edge to one of the ancestors in DFS tree of u.
- Bridges and articulation points are important to know, as this will give information of vulnerabilities of the graph.

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
- **Hamiltonian**
- Number of hamiltonian cycles O((n-1)! / 2)
-------


## Questions

1) [Find the number of paths from u to v in a DAG?](https://www.geeksforgeeks.org/count-possible-paths-two-vertices/)
2) [Find the minimum number of edges to be removed to make a undirected graph acyclic?](https://www.geeksforgeeks.org/minimum-number-of-edges-required-to-be-removed-from-an-undirected-graph-to-make-it-acyclic/)