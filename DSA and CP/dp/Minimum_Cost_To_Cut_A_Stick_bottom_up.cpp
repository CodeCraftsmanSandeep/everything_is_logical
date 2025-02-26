// Bottom-up approach (or) Tabulation method

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector <int> new_cuts = {0};
        new_cuts.insert(new_cuts.end(), make_move_iterator(cuts.begin()), make_move_iterator(cuts.end()));
        new_cuts.push_back(n);
        sort(new_cuts.begin(), new_cuts.end());

        int m = new_cuts.size();
        vector <vector <int>> dp(m, vector <int> (m, 0));

        for(int len = 3; len <= m; len++){
            for(int i = 0; i + len - 1 <= m-1; i++){
                int j = i + len - 1;

                dp[i][j] = INT_MAX;
                for(int k = i + 1; k <= j-1; k++){
                    dp[i][j] = min(dp[i][j], new_cuts[j] - new_cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][m-1];
    }
};