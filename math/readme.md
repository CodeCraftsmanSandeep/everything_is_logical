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