# Segment trees
- Operations supported by segment trees:
  - ![operations_supported_by_seg_tree.png](operations_supported_by_seg_tree.png)
- persistent segment tree
  - [article](https://www.geeksforgeeks.org/persistent-segment-tree-set-1-introduction/)
  - O(logn) per query
- Merge sort tree
  -  O(log^2) per query


# questions
- For each query (l, r, k) find number of i such l <= i <= k and a[i] > k
  - [question link](https://www.spoj.com/problems/KQUERY/)
  - [effecient code](kqueryEfficient.cpp), O(logn) per query on avarage, offline queries, pre-processing the queries, inspired from comments from [blog](https://codeforces.com/blog/entry/10183#comment-156355)
  - [using merge sort tree](kqueryMergeSortTree.cpp), O(log^2(n)) on average per query on average, online queries
  - [using persistent seg tree](kqueryPersistent.cpp) , O(logn) time per query on average, online quries