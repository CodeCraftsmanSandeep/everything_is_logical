// Top-down approach
class Solution {
    int getMinCost(vector <int>& cuts, int i, int j, vector <vector <int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(j - i <= 1) return dp[i][j] = 0;

        dp[i][j] = INT_MAX;
        for(int k = i+1; k <= j-1; k++){
            dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + getMinCost(cuts, i, k, dp) + getMinCost(cuts, k, j, dp));
        }
        return dp[i][j];
    }
public:
    int minCost(int n, vector<int>& cuts) {
        vector <int> new_cuts = {0};
        new_cuts.insert(new_cuts.end(), make_move_iterator(cuts.begin()), make_move_iterator(cuts.end()));
        new_cuts.push_back(n);
        sort(new_cuts.begin(), new_cuts.end());
        int m = new_cuts.size();

        vector <vector <int>> dp(m, vector <int> (m, -1));
        return getMinCost(new_cuts, 0, m-1, dp);
    }
};