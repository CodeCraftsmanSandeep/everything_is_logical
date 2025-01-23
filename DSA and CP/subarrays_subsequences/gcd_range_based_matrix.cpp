#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int gcd[n][n];
    for(int i = 0; i < n; i++){
        gcd[i][i] = arr[i];
        for(int j = i+1; j < n; j++){
            gcd[i][j] = __gcd(arr[j], gcd[i][j-1]);
        }
    }

    int q;
    cin >> q;
    int l, r;
    while(q--){
        // zero-based indexing
        cin >> l >> r;
        cout << gcd[l][r] << "\n";
    }

    return 0;
}