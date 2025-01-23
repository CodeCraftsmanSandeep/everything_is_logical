class Solution{
  public:
    int cutRod(int price[], int n) {
        vector <int> dp(price, price + n);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++) dp[i] = max(dp[i], dp[j] + dp[i-j-1]);
        }
        return dp[n-1];
    }
};
// O(n^2) time
// O(n) space
// we can directly use price array to get the answer