- Find sum of two numbers without using arthimetic operators.
  - [question](https://leetcode.com/problems/sum-of-two-integers/description/)
- Find bitwise and of numbers in given range
  - [question](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)
- Number of 1 bits in a binary representation of number n
  - [question](https://leetcode.com/problems/number-of-1-bits/submissions/1363323311/)
- [Find nth number in a sequence in which every number containing 9 is removed from sequence.](https://www.geeksforgeeks.org/problems/nth-natural-number/1)
- [Find non-duplicate numbers](https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1)
- [Find the maximum of two numbers without using comprision operator](https://www.geeksforgeeks.org/compute-maximum-of-two-integers-in-c-c-using-bitwise-operators/)
  - [My code](finding_max.cpp) 
  - related question: [Find the smallest number in 3 numbers.](https://www.geeksforgeeks.org/smallest-of-three-integers-without-comparison-operators/)

- [Find two repeated numbers](https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1)
  - [find_two_repeated_numbers.cpp](find_two_repeated_numbers.cpp)
    - Time: O(n)
    - Auxillary space: O(1)

- [Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.](https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1)
  - [My code](find_duplicates.cpp)
    - Time: O(n)
    - Auxillary space: O(1)

# notes
- n = n&(n-1) 
  - removes the right most 1 from n
  - notable thing: if n & (n-1) == 0 then n is power of two
- x = n & (-n)
  - x is the right most 1 in n
  - n&(n-1) = n - (n&(-n))
- a & b + a ^ b = a | b

- XOR of first n natural numbers:
  - (n mod 4) = 0:
    - XOR(n) = n
  - (n mod 4) = 1
    - XOR(n) = 1
  - (n mod 4) = 2
    - XOR(n) = n + 1
  - (n mod 4) = 3
    - XOR(n) = 0
  
- a xor (b + c) != a xor (b) + a xor (c)
  - Example: Take a = 5, b = 3, c = 2. 

- (num xor 1) is either num-1 (or) num+1

--------
- [https://www.codechef.com/practice/course/5-star-and-above-problems/DIFF2500/problems/SUBARRAYXOR?tab=statement](Good xor problem)
  - [https://discuss.codechef.com/t/subarrayxor-editorial/98660/4?u=sandeep_iitpkd](post)