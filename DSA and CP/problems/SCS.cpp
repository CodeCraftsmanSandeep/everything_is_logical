#include <bits/stdc++.h>
using namespace std;

void shortestCommonSupersequence(string X, string Y, int n, int m){
    // dp[i][j] = SCS of X[i:] and Y[j:]
    vector <vector <int>> dp(n+1, vector <int>(m+1, 0));
    
    // base cases
    for(int i = n-1; i >= 0; i--) dp[i][m] = n - i;
    for(int j = m-1; j >= 0; j--) dp[n][j] = m - j;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(X[i] == Y[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }else{
                dp[i][j] = min(1 + dp[i+1][j], 1 + dp[i][j+1]);
            }
        }
    }

    // let us print shortestCommonSupersequence
    int i = 0;
    int j = 0;
    string ans;
    while(i < n && j < m){
        if(X[i] == Y[j]){
            ans += X[i];
            i++; j++;
        }else if(dp[i][j] == 1 + dp[i+1][j]){
            ans += X[i++];
        }else{
            ans += Y[j++];
        }
    }
    while(i < n) ans += X[i++];
    while(j < m) ans += Y[j++];

    cout << "Length of shortest common super sequence: " << dp[0][0] << "\n";
    cout << "Shortest common super sequence: " << ans << "\n";
}

int main(){
    string X, Y;
    cin >> X >> Y;

    shortestCommonSupersequence(X, Y, X.size(), Y.size());
}
