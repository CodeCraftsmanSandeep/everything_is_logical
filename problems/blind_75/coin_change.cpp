class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector <int> dp(1+amount, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(auto ele: coins){
                if(ele > i) break;
                if(dp[i-ele] != INT_MAX) dp[i] = min(dp[i], dp[i-ele] + 1);
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};