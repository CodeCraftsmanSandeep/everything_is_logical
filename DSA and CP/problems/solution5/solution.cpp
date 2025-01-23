#include <bits/stdc++.h>
using namespace std;

long long int solve(string& S, string& T){
    int n = S.size();
    int m = T.size();

    // dp[i][j] = number of times T[j:] occured as subsequence in S[i:]
    vector <vector <int>> dp(m+1, vector<int>(n+1, 0));       // padding from bottom

    // matching empty sub-sequences
    for(int j = n; j >= 0; j--) dp[m][j] = 1;

    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(S[j] == T[i]) dp[i][j] = (dp[i][j+1] + dp[i+1][j+1]);
            else dp[i][j] = dp[i][j+1];
        }
    }

    return dp[0][0];
}

int main(){
    string S, T;
    cin >> S >> T;
    
    cout << solve(S, T) << "\n";
}
