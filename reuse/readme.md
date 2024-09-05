## ✨ Frequently Used Codes

Below is a list of code snippets that I find frequently useful in solving problems:

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
    Stirling’s approximation is one of the most famous and useful bounds for \( n! \). For large \( n \), the factorial grows very fast, and Stirling's approximation gives an estimate for \( n! \):
    \[
    n! \approx \sqrt{2 \pi n} \left(\frac{n}{e}\right)^n
    \]

    This can be refined to give both lower and upper bounds:
    \[
    \sqrt{2 \pi n} \left(\frac{n}{e}\right)^n \leq n! \leq \sqrt{2 \pi n} \left(\frac{n}{e}\right)^n e^{\frac{1}{12n}}
    \]
    This is useful for asymptotic analysis of algorithms involving \( n! \).

Feel free to explore these snippets and see how they can aid in problem-solving! 🚀