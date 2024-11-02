# Count number of set bits in a number:
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
    - ```cpp



    ```

