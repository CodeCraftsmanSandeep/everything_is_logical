int knapSack(int W, vector <int>& wt, vector <int>& val){
    int n = wt.size();
    // dp[i][w] = maximum value obtained with knapsack with weight w and items wt[i:], val[i:]
    vector <vector <int>> dp(1+n, vector <int> (1+W, 0));
    for(int i = n-1; i >= 0; i--){
        for(int w = 1; w <= W; w++){
            dp[i][w] = dp[i+1][w]; // with same weight not including object i
            if(w >= wt[i]) dp[i][w] = max(dp[i][w], dp[i+1][w-wt[i]] + val[i]);
        }
    }
    return dp[0][W];
}