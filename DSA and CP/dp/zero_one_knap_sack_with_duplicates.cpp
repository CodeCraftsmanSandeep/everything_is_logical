class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[]){
        vector <int> dp(1+W, 0); // value
        for(int w = 1; w <= W; w++){
            for(int j = 0; j < n; j++){
                if(w - wt[j] >= 0) dp[w] = max(dp[w], val[j] + dp[w-wt[j]]);
            }
        }
        return dp[W];
    }
};