#include <bits/stdc++.h>
using namespace std;

void shortestCommonSupersequence(string X, string Y, int n, int m){
    // assuming m < n

    // dp[i][j] = SCS of X[i:] and Y[j:]
    vector <int> dp(m+1, 0);
    iota(dp.rbegin(), dp.rend(), 0);

    for(int i = n-1; i >= 0; i--){
        int diag = dp[m]; // dp[i+1][j+1]
        dp[m] = n-i;
        for(int j = m-1; j >= 0; j--){
            int store = dp[j];
            if(X[i] == Y[j]){
                dp[j] = 1 + diag;
            }else{
                dp[j] = min(1+dp[j+1], 1 + dp[j]);
            }
            diag = store;
        }
    }

    cout << "Length of shortest common super sequence: " << dp[0] << "\n";
}

int main(){
    string X, Y;
    cin >> X >> Y;

    int n = X.size();
    int m = Y.size();
    if(m < n) shortestCommonSupersequence(X, Y, X.size(), Y.size());
    else shortestCommonSupersequence(Y, X, Y.size(), X.size());
}
