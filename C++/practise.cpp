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