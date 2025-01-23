class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector <int> dp(1+sum, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= sum; i++){
            for(auto coin: coins){
                if(i-coin >= 0 && dp[i-coin] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }
        if(dp[sum] == INT_MAX) return -1;
        return dp[sum];
    }
};