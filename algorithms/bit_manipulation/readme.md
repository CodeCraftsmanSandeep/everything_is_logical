- Find sum of two numbers without using arthimetic operators.
  - [question](https://leetcode.com/problems/sum-of-two-integers/description/)
- Find bitwise and of numbers in given range
  - [question](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)
- Number of 1 bits in a binary representation of number n
  - [question](https://leetcode.com/problems/number-of-1-bits/submissions/1363323311/)
- [Find nth number in a sequence in which every number containing 9 is removed from sequence.](https://www.geeksforgeeks.org/problems/nth-natural-number/1)

# notes
- n = n&(n-1) 
  - removes the right most 1 from n
- x = n & (-n)
  - x is the right most 1 in n
  - n&(n-1) = n - (n&(-n))
