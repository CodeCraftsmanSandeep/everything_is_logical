int knapSack(int W, vector <int>& wt, vector <int>& val){
    int n = wt.size();
    // dp[i][w] = maximum value obtained with knapsack with weight w and items wt[i:], val[i:]
    vector <int> dp(1+W, 0);
    for(int i = n-1; i >= 0; i--){
        for(int w = W; w >= 0; w--){
            int curr_val = dp[w];
            if(w >= wt[i]) curr_val = max(curr_val, dp[w-wt[i]] + val[i]);
            dp[w] = curr_val;
        }
    }
    return dp[W];
}

// works for
// wt[i] >= 0