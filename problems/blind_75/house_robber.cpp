class Solution {
public:
    // int rob(vector<int>& arr) {
    //     int n = arr.size();
    //     if(n == 1) return arr[0];
    //     vector <vector <int>> dp(n, vector <int> (2, 0));
    //     dp[0][1] = arr[0];
    //     dp[1][0] = max(dp[0][0], dp[0][1]);
    //     dp[1][1] = arr[1];
    //     for(int i = 2; i < n; i++){
    //         dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    //         dp[i][1] = arr[i] + max(dp[i-2][0], dp[i-2][1]);
    //     }
    //     return max(dp[n-1][0], dp[n-1][1]);

    // }

    // O(1) solution
    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        int prev_prev = arr[0];
        int prev = max(arr[0], arr[1]);
        for(int i = 2; i < n; i++){
            int curr = max(prev, arr[i] + prev_prev);
            prev_prev = prev;
            prev = curr;
        }
        return prev;

    }
};