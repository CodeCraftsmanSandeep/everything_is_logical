// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size() - 1;
        
        vector <vector <int>> dp(1+n, vector <int> (1+n, 0));
        for(int len = 2; len <= n; len++){
            for(int i = 1; i + len - 1 <= n; i++){
                int j = i + len - 1;
                
                dp[i][j] = INT_MAX;
                for(int k = i; k < j; k++){
                    dp[i][j] = min(dp[i][j], arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};