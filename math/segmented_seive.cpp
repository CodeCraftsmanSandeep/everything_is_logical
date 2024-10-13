/*
Problem statement:
Print all primes from L to R (inclusive)

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long int

// NOTES:
//      LTEQ - Less Than Or Equal To
//      BTW  - Between 

/* normal_seive returns vector which contains all primes <= n*/
vector <ll> normal_seive(ll n){
    vector <bool> is_prime(1+n, true);
    vector <ll> primes_LTEQ_n;
    is_prime[0] = is_prime[1] = false;
    for(ll num = 2; num <= n; num++){
        if(is_prime[num]){
            primes_LTEQ_n.push_back(num);
            for(ll multiple = num*num; multiple <= n; multiple += num) is_prime[multiple] = false;
        }
    }
    return primes_LTEQ_n;
}

/* segmented_seive returns vector which contains prime numbers p such that L <= p and p <= R */
// Overall time(dominant terms)  : O((R-L+1)loglog(sqrt(R))) + O(sqrt(R) loglog(sqrt(R))) 
// Overall space(dominant terms) : O(sqrt(R)) + O(R-L+1)
vector <ll> segmented_seive(ll L, ll R){

    // time  :  O(sqrt(R) loglog(sqrt(R)))     (time consumed in normal_seive())
    // space :  O(sqrt(R))                     (auxillary space used inside function normal_seive())
    vector <ll> primes_LTEQ_root_R = normal_seive(sqrt(R));

    // time  : O(R-L+1)   (internally to allocate space)
    // space : O(R-L+1)   (internally to allocate space)
    vector <bool> is_prime(R-L+1, true); // mapping from L to R inclusive
    
    // edge case (when L <= 1)
    // number which satisfies L <= number <= 1 is marked not prime
    for(int num = L; num <= 1; num++) is_prime[num-L] = false;

    // number of multiples of prime (prime <= sqrt(R)) from L to R is O((R-L+1)/prime)
    // (from euler approximation of sum of reciprocals of primes) we get O((R-L+1)loglog(sqrt(R)))
    for(ll prime: primes_LTEQ_root_R){
        ll smallest_multiple = L;
        if(smallest_multiple%prime != 0) smallest_multiple += prime - (smallest_multiple%prime);
        if(smallest_multiple <= prime) smallest_multiple = 2*prime;  // i.e when smallest_multiple = 0 (or) prime
        // smallest_multiple = j * prime
        // such that j > 1
        //           L <= smallest_multiple
        for(ll multiple = smallest_multiple; multiple <= R; multiple += prime){
            is_prime[multiple-L] = false;
        }
    }

    // time : O(R-L+1)
    vector <ll> primes_BTW_L_to_R;
    for (ll num = L; num <= R; num++){
        if(is_prime[num-L]) primes_BTW_L_to_R.push_back(num);
    }
    return primes_BTW_L_to_R;
}

int main(){
    ll L, R;
    cin >> L >> R;

    vector <ll> primes_BTW_L_to_R = segmented_seive(L, R);
    cout << primes_BTW_L_to_R.size() << " primes from " << L << " to " << R << " inclusive \n";
    for(auto prime_num: primes_BTW_L_to_R) cout << prime_num << " ";
    cout << "\n";
}

/*
Test cases:

Input:
    5 10
Output:
    2 primes from 5 to 10 inclusive 
    5 7

Input:
    0 10
Output:
    4 primes from 0 to 10 inclusive 
    2 3 5 7


*/