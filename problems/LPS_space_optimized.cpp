// space optmized
int longestPalinSubseq(string s) {
    int n = s.size();
    
    // dp[i][j] = LPS from j to i (inclusive)
    vector <int> dp(1+n, 0);
    
    for(int i = 1; i <= n; i++){
        int diag = dp[i]; // dp[i-1][j+1]
        dp[i] = 1;
        for(int j = i-1; j >= 1; j--){
            int store = dp[j];
            if(s[i-1] == s[j-1]){
                dp[j] = 2 + diag;
            }else{
                dp[j] = max(dp[j], dp[j+1]);
            }
            diag = store;
        }
    }
    
    return dp[1];
}
