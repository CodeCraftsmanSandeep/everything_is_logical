int recurse(int W, vector <int>& wt, vector <int>& val, int i, vector <vector <int>>& dp){
    if(i < 0) return 0;
    if(dp[i][W] != -1) return dp[i][W];
    if(wt[i] <= W) return dp[i][W] = max(val[i] + recurse(W-wt[i], wt, val, i-1, dp), recurse(W, wt, val, i-1, dp));
    return dp[i][W] = recurse(W, wt, val, i-1, dp);
}

int knapSack(int W, vector <int>& wt, vector <int>& val){
    vector <vector <int>> dp(wt.size(), vector <int> (1+W, -1));
    return recurse(W, wt, val, wt.size() - 1, dp);
}

// works for
// w[i] >= 0