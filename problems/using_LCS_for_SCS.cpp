string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector <vector <int>> dp(1+n, vector <int> (1+m, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    int i = n;
    int j = m;
    string ans;
    while(i >= 1 && j >= 1){
        if(dp[i][j] == dp[i-1][j]){
            ans += str1[i-1];
            i--;
        }else if(dp[i][j] == dp[i][j-1]){
            ans += str2[j-1];
            j--;
        }else{
            ans += str1[i-1];
            i--;
            j--;
        }
    }
    while(i >= 1) ans += str1[--i];
    while(j >= 1) ans += str2[--j];
    reverse(ans.begin(), ans.end());
    return ans;
}
