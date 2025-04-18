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

- Number of times string 2 appears as sub-string in string s1
  - [article](https://www.sanfoundry.com/c-program-count-occurrence-substring/)
  - not sure whether this is the optimized

- **Edit distance**
  - [Minimum number of operations (insert/delete/update) should be perfomed inorder to make two strings equal](https://www.geeksforgeeks.org/problems/edit-distance3702/1)
  - [edit_distance.cpp](edit_distance.cpp)

- **[Coin change](https://www.geeksforgeeks.org/problems/number-of-coins1824/1)**
  - My code: [coin_change.cpp](coin_change.cpp)
    - Time: O(sum*n)
    - Space: O(sum)

- **Knapsack variants** [article](https://www.geeksforgeeks.org/introduction-to-knapsack-problem-its-types-and-how-to-solve-them/)
  - 0-1 knapsack
    - [0-1 Knapsack with duplicates](https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1)
      - This is called unbounded knap-sack 
      - [My code](zero_one_knap_sack_with_duplicates.cpp)
        - Time: O(W*n)
        - Space: O(W)
    - [0-1 Knapsack without duplicates](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)
      - This problem is bounded knapsack (but here number of items selected <= number of items (instead of some k))
      - It is important to understand why [zero_one_knap_sack_with_duplicates.cpp](zero_one_knap_sack_with_duplicates.cpp) fails for this problem.
      - Different solutions to find the maximum value that can be obtained
        - | S.no | Notes | code | time | space|
          |:-----|:------|:-----|:-----|:-----|
          | 1 | Using choose and not-choose recursive brute force approach. (generating all 2^N subsequences) | [zero_one_knap_sack_1.cpp](zero_one_knap_sack_1.cpp) | O(2^N) | O(N) recursive stack space |
          | 2 | Using choose and not-choose recursive memoization approach. (Top-down approach) | [zero_one_knap_sack_2.cpp](zero_one_knap_sack_2.cpp) | O(N*W) | O(N*W) space for table + O(N) recursive stack space |
          | 3 | DP (tabulation approach) | [zero_one_knap_sack_3.cpp](zero_one_knap_sack_3.cpp) | O(N*W) | O(N*W) |
          | 4 | Space optimized DP (tabulation approach) | [zero_one_knap_sack_4.cpp](zero_one_knap_sack_4.cpp) | O(N*W) | O(W) |
      - Printing items that are resulting in maximum value (a optimal solution)
        - [code](zero_one_knap_sack_with_duplicates_print_items.cpp)
        - input-output pair1:
          - input: <br/> 
          ```
            7 20
            6 5 1 5 6 5 9
            5 3 4 9 6 1 1
          ```
          - output: <br/>
          ```
            item 0 : (w=6, v=5)
            item 2 : (w=1, v=4)
            item 3 : (w=5, v=9)
            item 4 : (w=6, v=6)
            Maximum value: 24
          ```
        - input-output pair2:
          - input: <br/>
          ```
            3 50
            10 20 30
            60 100 120
          ```
          - output: <br/>
          ```
            item 1 : (w=20, v=100)
            item 2 : (w=30, v=120)
            Maximum value: 220
          ```
    - 0-1 Bounded knapsack
      - Variant 1:
        - Given N items, each item having a given weight Ci and a profit value Pi, the task is to maximize the profit by selecting a maximum of K items adding up to a maximum weight W.
        - [Different solutions](https://www.geeksforgeeks.org/maximize-profit-by-picking-elements-of-different-types-with-total-weight-k/):
          - | S.No | Notes | code | time | space |
            |:-----|:-----|:-----|:-----|:----|
            | 1 | Memoized approach | [zero_one_bounded_knapsack_1.cpp](zero_one_bounded_knapsack_1.cpp) | O(N*W*K) | O(N*W*K) |
            | 2 | dp (tabulation) | [zero_one_bounded_knapsack_2.cpp](zero_one_bounded_knapsack_2.cpp) | O(N*W*K) | O(N*W*K) | 
            | 3 | space optimized dp (tabulation) | [zero_one_bounded_knapsack_3.cpp](zero_one_bounded_knapsack_3.cpp) | O(N*W*K) | O(W*K) |
      - Variant 2:
        - You are given n types of items, you have ui items of ith type, and each item of ith type weighs wi and costs ci. What is the maximal cost you can get by picking some items weighing at most W in total?
        - [Solutions blog](http://dhruvbird.blogspot.com/2011/09/integer-01-bounded-knapsack-problem.html), Let M the mean of number of items of each type. 
        - Brute force solution [broute_force_zero_one_bounded_knapsack.cpp](broute_force_zero_one_bounded_knapsack.cpp), Time: O((1+freq[0]) * (1 + freq[1]) * .. * (1+freq[n-1])), Space: O(n) 
          - | S.No | Notes | code | time | space |
            |:-----|:------|:-----|:-----|:------|
            | 1 | Directly using knapsack, without using much brain | [zero_one_bounded_knapsack_4.cpp](zero_one_bounded_knapsack_4.cpp) | O(W * N * M) | O(W*N), can be optimized to O(W) but not done to maintain clarity |
            | 2 | Using knapsack and little 🧠, Try to prove as the proof is hot. | [zero_one_bounded_knapsack_5.cpp](zero_one_bounded_knapsack_5.cpp) | O(W * N * logM) | O(W * N * logM), can be optimized to O(W) but not done to maintain clarity | 
            | 3 | using knapsack and 🧠 | [zero_one_bounded_knapsack_6.cpp](zero_one_bounded_knapsack_6.cpp) NEED TO CODE | O(W * N) | O(W * N) can be optimzed to O(W) but not done |
  - [Fractional knapsack](https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)
    - [fractional_knapsack.cpp](fractional_knapsack.cpp), greedy one

- Matrix chain multiplication:
  - [Problem link](https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)
  - My nice code:
    - [MCM_bottom_up](MCM_bottom_up.cpp)
      - Time: O(n ^ 3), Space: O(n ^ 2)
    - [MCM_top_down](MCM_top_down.cpp)

- Minimum cost to cut a stick
  - [Problem link](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/)
  - Why greedy does not work: [link](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/editorial/comments/1874468)
  - My nice codes:
    - [Minimum_Cost_To_Cut_A_Stick: bottom_up approach](Minimum_Cost_To_Cut_A_Stick_bottom_up.cpp)
      - Time: O(numCuts ^ 3), Space: O(numCuts ^ 2)
    - [Minimum_Cost_To_Cut_A_Stick: top_down approach](Minimum_Cost_To_Cut_A_Stick_top_down.cpp)

- [Burst Balloons](https://leetcode.com/problems/burst-balloons/)
  - My clean code: [solution](burst_ballons.cpp)

- [Good problem](https://www.codechef.com/problems/CIRMERGE)
