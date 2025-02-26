// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution {
  int findMinOperations(vector <int>& arr, int i, int j, vector <vector <int>>& dp){
      if(dp[i][j] != -1) return dp[i][j];
      if(i == j) return dp[i][j] = 0;
      
      dp[i][j] = INT_MAX;
      for(int k = i; k < j; k++){
          dp[i][j] = min(dp[i][j], arr[i-1] * arr[k] * arr[j] + findMinOperations(arr, i, k, dp) + findMinOperations(arr, k+1, j, dp));
      }
      return dp[i][j];
  }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size() - 1;
        if(n == 1) return 0;
        
        vector <vector <int>> dp(1+n, vector <int> (1+n, -1));
        return findMinOperations(arr, 1, n, dp);
    }
};