This is one of the hottest topics among competetive programming and dsa problems, which is also one of my favourite:

# Problems

- [Find the smallest sub-array with sum greater than x](https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1)
  - my code: [smallest_sub_array.cpp](smallest_sub_array.cpp)
    - O(n) time
    - O(1) space

- [Find the number of arrays with sum k.](https://leetcode.com/problems/subarray-sum-equals-k/description/)


- Find the Longest Increasing Subseqeunce
  - [Question](https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn/)
  - cool approaches:
    - [LIS_dp.cpp](LIS_dp.cpp)
      - Time: O(n^2)
      - Auxillary space: O(n)
    - [LIS_binary_search.cpp](LIS_binary_search.cpp)  
      - Time: O(nlogn)
      - Auxillary space: O(n)
    - [LIS_segment_tree.cpp](LIS_segment_tree.cpp)
      - Time: O(nlogn)
      - Auxillary space: O(n)
    - LIS_BIT.cpp yet to come!!

- Longest consecutive sub-sequence
  - see blind 75 solutions for solution

- [Find the longest sub-array whoose sum is k](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1)

- [Maximum product subarray](https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1)
  - O(n) time, O(1) solution: [maximumProductSubarray.cpp](maximumProductSubarray.cpp)

- [Count the nunber of sub-arrays with product < k](https://leetcode.com/problems/subarray-product-less-than-k/description/)
  - [countSubArraysWithProduct<k.cpp](countSubArraysWithProduct<k.cpp)
  - Time complexity: O(n)
  - Auxillary space: O(1)

- Maximum sub-array sum
  - [kadanes algo](https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1)
  - O(n) time
  - O(1) space
  - [kadanes_algo.cpp](kadanes_algo.cpp)

- Find maximum sub-array sum <= k
  - [maxSubArraySum<=k.cpp](maxSubArraySum<=k.cpp)

- Find the maximum for each sub-array of size k
  - [question](https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)
  - [max_subarray.cpp](max_subarray.cpp)

- Longest palindromic substring
  - Find the length of longest palidromic substring
  - [Find the longest palindromic substring](https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1)
    - O(n^2) time, O(1) space method: [LPSubstr1.cpp](LPSubstr1.cpp)
    - O(n^2) time, O(n^2) space method(dp method): [LPSubstr2.cpp](LPSubstr2.cpp)
    - slower algorithm 
      - O(n^2) time, O(n) space (extra space for augumenting string)
      - [LPSubstr3.cpp](LPSubstr3.cpp)
    - manacher's algo 
      - O(n) time, O(n) space
      - Very complicated, need to do!!

- Longest k unique characters substring
  - [question](https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)
  - My code: [longest_k_unique_characters.cpp](longest_k_unique_characters.cpp)

- [Find the longest substring which is valid parenthesis.](https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1)
  - [Using stack](longest_valid_parenthesis_substring.cpp)
    - O(N) time
    - O(N) auxillary space
  - [Nice approach](longest_valid_parenthesis_substring_optimized.cpp) from [this article.](https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/)
    - O(N) time
    - O(1) auxillary space

- [Find the longest subseq which is valid parenthesis.]
  - This is easy

- [Range based queries for the longest balanced subsseq. Given a string s of length n, given q queries each of the form l r, for each query find the longest balanced subseq in s from l to r(inclusive)](https://www.geeksforgeeks.org/range-queries-longest-correct-bracket-subsequence-set-2/)
  - Using segment trees: 
    - [longest_balanced_subseq_2.cpp](longest_balanced_subseq_2.cpp)
    - Preprocessing time: O(nlogn)
    - Per query time: O(log2(r - l + 1))
    - Auxillary space: O(n) for segment tree 
  - there is O(1) time algo which I did not understand !!
    - [longest_balanced_subseq_3.cpp](longest_balanced_subseq_3.cpp)
  
- [Find the smallest substring in s which contains all characters in string p](https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1)
  - [smallest_substring_1.cpp](smallest_substring_1.cpp)
    - Time: 26*|s| = O(|s|)
    - Auxillary space: O(26*2) = O(1)
  - [smallest_substring_2.cpp](smallest_substring_2.cpp), optimized code
    - Time: |s| + 26 = O(|s|)
    - Auxillary space: O(26*2) = O(1)

- [Given an integer array arr[] of size N, find the maximum of the minimums for every window size in the given array.Note: The window size varies from 1 to N.](https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1)
  - [maximum_of_minimum.cpp](maximum_of_minimum.cpp)
    - Time: O(n)
    - Auxillary space: O(n)


## Range based queries questions
- [Range based quries question.](https://www.geeksforgeeks.org/array-range-queries-range-queries/)
    - Question:
        - Given an array of size n and a give set of commands of size m. The commands are enumerated from 1 to m. These commands can be of the following two types of commands: 
            - Type 1 [l r (1 <= l <= r <= n)] : Increase all elements of the array by one, whose indices belongs to the range [l, r]. In these queries of the index is inclusive in the range.
            - Type 2 [l r (1 <= l <= r <= m)] : Execute all the commands whose indices are in the range [l, r]. In these queries of the index is inclusive in the range. It’s guaranteed that r is strictly less than the enumeration/number of the current command.
    - [My code](arrays_with_range.cpp)
        - My code is better than the ones present in article!!
        - Auxillary space: O(n + m)
        - Total time: O(n + m)


- [Given an array A of size N. Given Q queries of the type {l, r}, 0 <= l <= m <= N-1. Find GCD of sub-array L and R](https://www.geeksforgeeks.org/gcds-of-a-given-index-ranges-in-an-array/)  
    - Approach I:
        - Use 2-D matrix to store GCD of every sub-array and use this table to print answer for each query.
        - [gcd_range_based_matrix.cpp](gcd_range_based_matrix.cpp)
        - Auxillary space: O(N^2)
        - Time: O(N^2 + Q)
    - Approach II:
        - Use segment tree

# Related questions:
- [Question1](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/)
- 