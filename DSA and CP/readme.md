
## 📝 Notes

- Very important: In C++, comparator should return false if its arguments are equal.

- **Cyclomatic Complexity**:
  - Check out this [GFG article](https://www.geeksforgeeks.org/cyclomatic-complexity/) for a deep dive into understanding cyclomatic complexity.
  
- **Handy Orders for Problem Solving**:
  - `1e9 < 2^(31) - 1 < 1e10`  
    (Where \(2^{31} - 1 = 2.147 \times 1e9\))
  - `1e18 < 2^(63) - 1 < 1e19`  
    (Where \(2^{63} - 1 = 9.22 \times 1e18\))

- Complexity analysis
  - Amortized analysis:
    - Amortized time complexity is a method for analyzing the average time complexity of a sequence of operations in an algorithm, rather than the worst-case time complexity of a single operation.
    - This approach is particularly useful for algorithms that have expensive operations that happen only rarely, such as:
      - Eg: Dynamic arrays, DSU using path compression. 
      - Amortized time complexity typically refers to analyzing the average time per operation over a sequence of operations, and is not typically used to describe Quick Sort. Instead, it's the average-case complexity that is Θ(n log n) for Quick Sort.


## WHY prime numbers in CP??

Using a prime number for modulo operations in competitive programming (CP) is a well-established practice, and it serves several purposes:

### **1. Prevent Integer Overflow**
In many problems, intermediate results can exceed the limits of standard data types like `int` or `long long` (e.g., \(10^{18}\) in C++). Taking results modulo a number helps keep computations within manageable bounds. For example:

\[
\text{result} = (\text{a} \cdot \text{b}) \% \text{MOD}
\]


### **2. Properties of Modular Arithmetic**
Modulo with a prime number \( P \) enables the use of advanced mathematical properties, such as **modular multiplicative inverses** and **Fermat's Little Theorem**, which make computations easier and faster:

#### **a. Modular Multiplicative Inverse**
For a prime \( P \), the inverse of \( a \mod P \) can be calculated using:

\[
a^{-1} \equiv a^{P-2} \mod P
\]

This avoids division in modular arithmetic, which is typically not straightforward.

#### **b. Fermat's Little Theorem**
\[
a^{P} \equiv a \mod P
\]

This property simplifies large exponentiations, which is especially useful in CP problems involving repeated squaring.


### **3. Uniform Distribution**
Prime numbers avoid certain artifacts in modular arithmetic that arise with composite numbers. For example, when \( P \) is composite, some remainders might appear more frequently, leading to skewed distributions. Primes ensure better behavior in modular arithmetic.

### **4. Commonly Used Large Primes**
In CP, specific primes are chosen because:
- They are large enough to reduce the likelihood of collisions in hash functions.
- Their properties are well-suited to modular arithmetic.

Examples include:
- \( 10^9 + 7 \) (a prime near \( 10^9 \))
- \( 998244353 \) (a prime that is also a power of 2 plus 1, useful in FFT problems)

### **5. Practical Benefits**
- Primes ensure that modular arithmetic forms a **finite field**, which has well-defined rules and eliminates edge cases.
- Modular operations with primes are efficient to compute and fit within standard CP constraints.
-------

## Prefix sum-stuff:
- https://codeforces.com/blog/entry/86420


## Bitwise operators
- https://codeforces.com/blog/entry/94470


## CP things!!
- TLE where ```long long int``` is used instead of ```int```
  - https://codeforces.com/blog/entry/82238
  - example:
      - with int: https://codeforces.com/contest/1538/submission/306835139
      - with long long int: https://codeforces.com/contest/1538/submission/306835426
- Mex:
  - (Point updates) https://codeforces.com/blog/entry/81287?#comment-677837
- Important stuff regarding c++ set custom operator. To know what is the key in set. See this code:

## Problems:
1) https://codeforces.com/contest/1538/problem/F
2) https://www.codechef.com/problems/SSO
3) https://www.codechef.com/DEC21B/problems-old/PYRAMIDMOVES
4) https://www.codechef.com/problems/ANTSCHEF
5) https://www.codechef.com/problems/STROPERS
6) https://www.codechef.com/problems/ABCSTR
7) https://www.codechef.com/problems/ONEORALL
8) https://www.codechef.com/problems/TWOCOUNTERS
9) https://www.codechef.com/problems/MAXCYCSHIFT
10) https://www.codechef.com/problems/GSEQ
11) https://www.codechef.com/problems/SMOOTHINC