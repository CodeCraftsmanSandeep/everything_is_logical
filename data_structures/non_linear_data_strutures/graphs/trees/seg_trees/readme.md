- persistent segment tree
  - [article](https://www.geeksforgeeks.org/persistent-segment-tree-set-1-introduction/)
  - O(logn) per query
- Merge sort tree
  -  O(log^2) per query

# questions
- For each query (l, r, k) find number of i such l <= i <= k and a[i] > k
  - [question link](https://www.spoj.com/problems/KQUERY/)
  - [effecient code](kqueryEfficient.cpp), O(logn) per query on avarage, offline queries, pre-processing the quries
  - [using merge sort tree](kqueryMergeSortTree.cpp), O(log^2(n)) on average per query on average, online quries
  - [using persistent seg tree](kqueryPersistent.cpp) , O(logn) time per query on average, online quries