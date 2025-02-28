// https://leetcode.com/problems/burst-balloons/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector <int> coins = {1};
        coins.insert(coins.begin(), make_move_iterator(nums.begin()), make_move_iterator(nums.end()));
        coins.push_back(1);

        // O(n ^ 3) Time, O(n ^ 2) space
        // Bottom up (or) Tabulation approach
        vector <vector <int>> dp(2+n, vector <int> (1+n, 0));
        for(int len = 1; len <= n; len++){
            for(int i = 1; i + len - 1 <= n; i++){
                int j = i + len - 1;

                for(int k = i; k <= j; k++){
                    // kth ballon is the last ballon to burst in [i, j]
                    dp[i][j] = max(dp[i][j], coins[i-1] * coins[k] * coins[j+1] + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }

        return dp[1][n];
    }
};