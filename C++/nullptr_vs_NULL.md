- In C++ NULL is typically defined as  ```#define NULL 0``` (or) ```#define NULL ((void*)0)```

```
#include <iostream>

void foo(int) {
    std::cout << "Called foo(int)\n";
}

void foo(char*) {
    std::cout << "Called foo(char*)\n";
}

int main() {
    // Using NULL
    // foo(NULL);  // Ambiguous call: could call foo(int) or foo(char*)

    // Using nullptr
    foo(nullptr); // Unambiguous call: calls foo(char*)

    return 0;
}
```
