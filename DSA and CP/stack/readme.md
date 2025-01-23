# 📚 Stack Concepts and Problems

## 📝 Key Concepts

- **Computers Evaluate Using Postfix Expressions**:  
  - Computers naturally evaluate expressions in postfix notation.
  - **Stacks** can be effectively used to convert between different expression notations: postfix, infix, and prefix. This is a fundamental application of stacks in computer science.

- Expressions:
   - Infix expressions, Prefix expression (polish notation) and Postfix expression (reverse polish notation)
   - [Infix to Postfix](https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1)
      - [infix_to_postfix.cpp](infix_to_postfix.cpp)


## 🧩 Practice Problems

Explore these problems to deepen your understanding of stacks and their applications:

1. **Next Greater Element (NGE)**:  
   - Problem Link: [GeeksforGeeks - Next Greater Element](https://www.geeksforgeeks.org/next-greater-element/)
   - Learn about the [Monotonic Stack](https://www.geeksforgeeks.org/introduction-to-monotonic-stack-2/), which can be used to solve this problem efficiently.
   - We can find next smaller element index and previous smaller element index in just one loop: 
      - [next_and_prev_smaller.cpp](next_and_prev_smaller.cpp)
         - Time: O(N)
         - Space: O(N)
   - Related question: [question](https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1)

2. **Lexicographically Largest or Smallest Subsequence with Distinct Characters**:
   - Find the subsequence with unique characters that is lexicographically smallest or largest.
   - Problem Links:
     - [GeeksforGeeks - Largest Subsequence](https://www.geeksforgeeks.org/lexicographically-largest-subsequence-containing-all-distinct-characters-only-once/)
     - [LeetCode - Smallest Subsequence of Distinct Characters](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/)

3. **Largest Balanced Substring**:
   - Find the longest substring with balanced parentheses.
   - Problem Link: [GeeksforGeeks - Valid Substring](https://www.geeksforgeeks.org/problems/valid-substring0624/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

4. **Special Stack**:
   - Design and implement a special stack that supports additional operations. 
   - Problem Link: [GeeksforGeeks - Special Stack](https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/), MinStack

5. [Find the smallest number possible after removing k digits from a number](https://leetcode.com/problems/remove-k-digits/submissions/1487612346/)
   - [My solution](smallest_possible_num.cpp)