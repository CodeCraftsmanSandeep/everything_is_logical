// Seive of Eratosthenes algo 1
// time complexity  :  n*log(log(n))
// space complexity : O(n)

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector <bool> is_prime(1+n, true);
    is_prime[0] = is_prime[1] = false;
    for(int p = 2; p*p <= n; p++){
        if(is_prime[p]){
            // p is prime
            for(int m = p*p; m <= n; m += p){ 
                // m = p * j 
                // where j >= p
                // note that 1 <= j < p are already marked !!
                is_prime[m] = false;
            }
        }
    }
    for(int p = 0; p <= n; p++) if(is_prime[p]) cout << p << " ";
    cout << "\n";
}