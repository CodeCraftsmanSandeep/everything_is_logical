// using dp
int longestPalinSubseq(string s) {
    int n = s.size();
    
    // dp[i][j] = LPS from j to i (inclusive)
    vector <vector <int>> dp(1+n, vector <int> (1+n, 0));
    for(int i = 1; i <= n; i++){
        dp[i][i] = 1;
        for(int j = i-1; j >= 1; j--){
            if(s[i-1] == s[j-1]){
                dp[i][j] = 2 + dp[i-1][j+1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j+1]);
            }
        }
    }
    
    int i = n;
    int j = 1;
    string ans;
    while(j < i){
        if(s[i-1] == s[j-1]) {
            ans += s[i-1];
            i--;
            j++;
        }else if(dp[i][j] == dp[i-1][j]){
            i--;
        }else{
            j++;
        }
    }
    
    string rev = ans;
    reverse(rev.begin(), rev.end());
    
    if(i == j){
        ans += s[i-1];
    }
    ans += rev;
    cout << ans << "\n";
    
    return dp[n][1];
}
