# Notes
- The following are the two main properties of a problem that suggest that the given problem can be solved using dp
  - 1) Overlapping subproblems
  - 2) Optimal substructure
    - A given problem is said to have Optimal Substructure Property if the optimal solution of the given problem can be obtained by using the optimal solution to its subproblems instead of trying every possible way to solve the subproblems. 


# Problems

- [Rod cutting problem](https://www.geeksforgeeks.org/problems/rod-cutting0840/1)
  - [rod_cutting.cpp](rod_cutting.cpp)
  - O(n^2) time
  - O(n) space
- Number of times string s2 appears as sub-seqeunce in string s1
  - [question](https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)
- Number of times string 2 apperas as sub-string in string s1
  - [article](https://www.sanfoundry.com/c-program-count-occurrence-substring/)
  - not sure whether this is the optimized
- **Edit distance**
  - [Minimum number of operations (insert/delete/update) should be perfomed inorder to make two strings equal](https://www.geeksforgeeks.org/problems/edit-distance3702/1)
  - [edit_distance.cpp](edit_distance.cpp)
- **[Coin change](https://www.geeksforgeeks.org/problems/number-of-coins1824/1)**
  - My code: [coin_change.cpp](coin_change.cpp)
    - Time: O(sum*n)
    - Space: O(sum)
- **Knapsack variants**
  - Zero one knapsack
    - [Knapsack with duplicates](https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1)
      - [My code](zero_one_knap_sack_with_duplicates.cpp)
        - Time: O(W*n)
        - Space: O(W)
    - [Knapsack without duplicates](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)
      - It is important to understand why [zero_one_knap_sack_with_duplicates.cpp](zero_one_knap_sack_with_duplicates.cpp) fails for this problem.
      - 
  
  
