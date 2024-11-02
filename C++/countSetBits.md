# Count number of set bits in a number:
- Sources:
    - [GFG](https://www.geeksforgeeks.org/count-set-bits-in-an-integer/)
    - [Article](https://www.chessprogramming.org/Population_Count)
- Using C++ built in function:
    - ```cpp
        #include <iostream>
        using namespace std;

        template <typename T>
        int countSetBits(T n){
            return __builtin_popcount(n);
        }

        int main(){
            unsigned long long int a;
            cin >> a;
            cout << countSetBits <unsigned long long int> (a) << "\n";
        }
    ```
- Technique 1:
    - Iterate through each and every bit and get the number of set bits.
    - Time: $\log_2(n)$, Space: O(1)
    - ```cpp
        #include <iostream>
        using namespace std;

        template <typename T>
        int countSetBits(T n){
            // works for long long, unsigned datatypes as well
            int setBits = 0;
            while(n){
                setBits += (n&1);
                n >>= 1;
            }
            return setBits;
        }

        int main(){
            int n;
            cin >> n;

            cout << countSetBits <int> (n) << "\n";
        }
        ```
- Technique 2:
    - Brian Kernighan’s Algorithm
    - Time: θ(Number of set bits in n), Space: O(1)
    - ```cpp
        #include <iostream>
        using namespace std;

        template <typename T>
        int countSetBits(T n){
            // works for long long, unsigned datatypes as well
            int setBits = 0;
            while(n){
                setBits++;
                n &= (n-1); // remove the left most set bit
            }
            return setBits;
        }

        int main(){
            int n;
            cin >> n;

            cout << countSetBits <int> (n) << "\n";
        }
    ```
- Technique 3:
    - Using look-up table.
    - Construct look-up table for either 4 bit (nibble) or 8 bit (byte).
    - Time complexity: O(1), Space complexity: O(1) 
    - This is especially useful, when you want to find number of setBits for large number  of test cases.
    - ```cpp
        #include <iostream>
        #include <type_traits>
        using namespace std;

        template <typename T>
        int countSetBits(T n){
            int byte = (1 << 8);
            int lookUp[byte]; // for one byte
            lookUp[0] = 0;
            for(int i = 1; i < byte; i++) lookUp[i] = (i&1) + lookUp[(i >> 1)];

            // constexpr make the below if statements evaluated at compile time
            if constexpr ((is_same <T, int>::value) || (is_same <T, unsigned int>::value)){
                return  lookUp[n & 0xff] + lookUp[(n >> 8) & 0xff] + 
                    lookUp[(n >> 16) & 0xff] + lookUp[(n >> 24) & 0xff];
            }else if constexpr ((is_same <T, long long int>::value) || (is_same <T, unsigned long long int>::value)){
                return  lookUp[n & 0xff] + lookUp[(n >> 8) & 0xff] + 
                    lookUp[(n >> 16) & 0xff] + lookUp[(n >> 24) & 0xff] + 
                    lookUp[(n >> 32) & 0xff] + lookUp[(n >> 40) & 0xff] + 
                    lookUp[(n >> 48) & 0xff] + lookUp[(n >> 56) & 0xff];
            }else{
                std::cerr << "Datatype not supported\n";
                exit(1); 
            }
        }

        int main(){
            unsigned long long int a;
            a = 0xFFFFFF1;
            cout << countSetBits <unsigned long long int> (a) << "\n";
        }
    ```

