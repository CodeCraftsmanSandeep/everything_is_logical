## ✨ Frequently Used Codes

| S.No | Concept | Code | Quick Notes | 
|:--|:--|:---|:---|
| 1️⃣ | Finding the length of a binary format string of a number | [code1.cpp](code1.cpp) | |
| 2️⃣ | Converting numbers in any format (binary, octal, etc.) to decimal | [../C++/string/practise1](../C++/string/practise1) | Uses `stoi()`, `stol()`, `stoll()` for conversion |
| 3️⃣ | Conversion: Binary to Decimal and Decimal to Binary | [../C++/bitset/practise1](../C++/bitset/practise1) | |
| 4️⃣ | GCD and LCM | [euclid_recursive_code.cpp](euclid_recursive_code.cpp), [euclid_iterative_code.cpp](euclid_iterative_code.cpp), [extended_gcd.cpp](extended_gcd.cpp) | **Finding GCD**: Time Complexity: O(log(min(a, b))) <br/> `GCD(a, b) * LCM(a, b) = a * b` <br/> **Euclid's Algorithm**: <br/> `GCD(a, b) = GCD(a - b, b)` <br/> `GCD(a, b) = GCD(a % b, b)` |
| 5️⃣ | Modular Multiplicative Inverse | [modular_multiplicative_inverse.cpp](modular_multiplicative_inverse.cpp) | |
| 6️⃣ | Lucas Theorem | N/A | Useful for finding `(n choose k) % m` when `m` is small and `n` and `k` are large |


## Notes
- **Stirling's Approximation**: 
    - n! ~= sqrt(2 * pi * n) * (n/e)^n
- Sequence and series
    - nth odd number = 2*n - 1
    - Sum of first n positive integers = 1 + 2 + ... + n = n*(n+1)/2
    - Sum of first n squares = 1^2 + 2^2 + 3^2 + ... + n^2 = n*(n+1)(2n+1)/6
    - ![formulae.jpg](formulae.jpg)


- Sieve of Eratosthenes
  - Given integer ‘n’, print all prime numbers <= n. (similar question: [link](https://leetcode.com/problems/count-primes/description/))
    - Algo 1 (GFG) Normal seive
      - [seive_1.cpp](seive_1.cpp)
      - Time : O(nlog(log(n)))
      - Proof of time complexity: [GFG article](https://www.geeksforgeeks.org/how-is-the-time-complexity-of-sieve-of-eratosthenes-is-nloglogn/)
    - Algo 2: Segmented seive
      - [code](segmented_seive.cpp)
      - Segmented sieve is used for better cache, i.e diving into segments, no difference in time complexity, but running time is possibly less than algo1 because algo1 is not cache favored.
  
- Prime number theorem:
  - Number of primes less than (or) equal to n is =  π(N) ~ n/log(n)
- Euclid's theorem: (wiki)
    - There are infinitely many primes. (Infinitude of primes)
- Betrand’s postulate:
    - For all n > 1, there exists at least one prime in (n, 2*n)

- Upper bound on number of factors
  - Blog: [link](https://math.stackexchange.com/questions/1699330/upper-bound-on-number-of-factors)
  - Useful bound: Number of factors <= sqrt(3 * x). See the plot of this [here](https://i.sstatic.net/0bWW9.png)

- Harmonic number:
    - [Wiki](https://en.wikipedia.org/wiki/Harmonic_number)
    - H(n) = Sum of reciprocals of first n natural numbers = 1 + 1/2 + 1/3 + … + 1/n 
    - H(n) ~ O (lg(n) + γ) 
    - γ = [Wiki](https://en.wikipedia.org/wiki/Euler%27s_constant)
    - See plot of lg(n) + γ vs H(n): [here](harmonic_number.ipynb)


- Pegion hole principle
  - Pegion hole sorting


- Erodos seekers theorem:
  - [WIKI](https://en.wikipedia.org/wiki/Erd%C5%91s%E2%80%93Szekeres_theorem)
  - In mathematics, the Erdős–Szekeres theorem asserts that, given r, s, any sequence of distinct real numbers with length at least (r − 1)(s − 1) + 1 contains a monotonically increasing subsequence of length r or a monotonically decreasing subsequence of length s. 


- \((a + b)² = a² + b² + 2ab\)
- \((a + b)² + (a - b)² = 2(a² + b²)\)


## Probability
- Expected value:
  - [Wiki](https://en.wikipedia.org/wiki/Expected_value)

# Math related CP questions
- [Question 1](https://www.codechef.com/problems/LUCMAT)
- [Random NIM problem](https://www.codechef.com/problems/RANDOM_NIM)


------------------------------------------------------------------------------------------------------------------------
## MOD

- a = b (mod n) if n divides (a-b)
- (a + b) (mod n) = ((a mod n) + (b mod n)) mod n
- (a * b) (mod n) = ((a mod n) * (b mod n)) mod n
- a = b (mod n) => a ^ i = b ^ i (mod n)

------------------------------------------------------------------------------------------------------------------------

## Digital roots
- [WIKI](https://en.m.wikipedia.org/wiki/Digital_root)
- Properties of digital root : [link](https://en.m.wikipedia.org/wiki/Digital_root#Properties)

------------------------------------------------------------------------------------------------------------------------

## Grey codes
https://en.wikipedia.org/wiki/Gray_code


--------
To solve a **quadratic equation**, which is in the standard form:

\[
ax^2 + bx + c = 0
\]

where \(a\), \(b\), and \(c\) are constants and \(a \neq 0\), you can use the **quadratic formula**. The quadratic formula provides the solutions for \(x\) as:

\[
x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}
\]

### Steps to Solve a Quadratic Equation:

1. **Identify coefficients**: Identify \(a\), \(b\), and \(c\) from the quadratic equation.

2. **Calculate the discriminant**: The discriminant is the expression inside the square root:
   \[
   \Delta = b^2 - 4ac
   \]
   - If \(\Delta > 0\), the equation has **two distinct real solutions**.
   - If \(\Delta = 0\), the equation has **one real solution** (a repeated root).
   - If \(\Delta < 0\), the equation has **two complex (imaginary) solutions**.

3. **Apply the quadratic formula**: Use the quadratic formula to find the solutions for \(x\).

### Example 1: Real solutions
Solve the quadratic equation \(2x^2 - 4x - 6 = 0\).

1. **Identify coefficients**: Here, \(a = 2\), \(b = -4\), and \(c = -6\).
   
2. **Calculate the discriminant**:
   \[
   \Delta = (-4)^2 - 4(2)(-6) = 16 + 48 = 64
   \]
   Since the discriminant is positive (\(\Delta = 64 > 0\)), there will be two distinct real solutions.

3. **Apply the quadratic formula**:
   \[
   x = \frac{-(-4) \pm \sqrt{64}}{2(2)} = \frac{4 \pm 8}{4}
   \]
   Now, compute the two solutions:
   \[
   x_1 = \frac{4 + 8}{4} = \frac{12}{4} = 3
   \]
   \[
   x_2 = \frac{4 - 8}{4} = \frac{-4}{4} = -1
   \]
   
   So, the solutions are \(x = 3\) and \(x = -1\).

### Example 2: Complex solutions
Solve the quadratic equation \(x^2 + 4x + 8 = 0\).

1. **Identify coefficients**: Here, \(a = 1\), \(b = 4\), and \(c = 8\).

2. **Calculate the discriminant**:
   \[
   \Delta = 4^2 - 4(1)(8) = 16 - 32 = -16
   \]
   Since the discriminant is negative (\(\Delta = -16 < 0\)), there will be two complex solutions.

3. **Apply the quadratic formula**:
   \[
   x = \frac{-4 \pm \sqrt{-16}}{2(1)} = \frac{-4 \pm 4i}{2}
   \]
   Now, compute the two solutions:
   \[
   x_1 = \frac{-4 + 4i}{2} = -2 + 2i
   \]
   \[
   x_2 = \frac{-4 - 4i}{2} = -2 - 2i
   \]
   
   So, the solutions are \(x = -2 + 2i\) and \(x = -2 - 2i\).

---

### Summary:
- If the discriminant \(\Delta = b^2 - 4ac\) is positive, the quadratic equation has two real solutions.
- If \(\Delta = 0\), the equation has exactly one real solution (repeated root).
- If \(\Delta < 0\), the equation has two complex solutions.

