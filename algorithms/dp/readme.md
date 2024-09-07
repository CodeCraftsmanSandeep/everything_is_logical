# Notes
- The following are the two main properties of a problem that suggest that the given problem can be solved using dp
  - 1) Overlapping subproblems
  - 2) Optimal substructure
    - A given problem is said to have Optimal Substructure Property if the optimal solution of the given problem can be obtained by using the optimal solution to its subproblems instead of trying every possible way to solve the subproblems. 
- [Tabulation vs Memoization](https://www.geeksforgeeks.org/tabulation-vs-memoization/)
  - Memoization is a top-down approach where we cache the results of function calls and return the cached result if the function is called again with the same inputs. Memoization is typically implemented using recursion and is well-suited for problems that have a relatively small set of inputs.
  - Tabulation is a bottom-up approach where we store the results of the subproblems in a table and use these results to solve larger subproblems until we solve the entire problem. Tabulation is typically implemented using iteration and is well-suited for problems that have a large set of inputs.

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
      - Different solutions
        - | S.no | Notes | code | time | space|
          |:-----|:------|:-----|:-----|:-----|
          | 1 | Using choose and not-choose recursive brute force approach. (generating all 2^N subsequences) | [zero_one_knap_sack_1.cpp](zero_one_knap_sack_1.cpp) | O(2^N) | O(N) recursive stack space |
          | 2 | Using choose and not-choose recursive memoization approach. (Top-down approach) | [zero_one_knap_sack_2.cpp](zero_one_knap_sack_2.cpp) | O(N*W) | O(N*W) space for table + O(N) recursive stack space |
          | 3 | DP (tabulation approach) | [zero_one_knap_sack_3.cpp](zero_one_knap_sack_3.cpp) | O(N*W) | O(N*W) |
          | 4 | Space optimized DP (tabulation approach) | [zero_one_knap_sack_4.cpp](zero_one_knap_sack_4.cpp) | O(N*W) | O(W) |

  
  
