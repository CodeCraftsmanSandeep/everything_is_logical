// dp[i][w] = maximum value obtained with knapsack with weight w and items wt[i:], val[i:]
// the below version will work only if wt[i] >= 1
// if wt[i] = 0 then w-wt[i] = w, which will point to dp[i][w], but actually it should point to dp[i+1][w]
int knapSack(int W, vector <int>& wt, vector <int>& val){
    int n = wt.size();
    vector <int> dp(1+W, 0);
    for(int i = n-1; i >= 0; i--){
        for(int w = W; w >= 1; w--){
            if(w >= wt[i]) dp[w] = max(dp[w], dp[w-wt[i]] + val[i]);
        }
    }
    return dp[W];
}