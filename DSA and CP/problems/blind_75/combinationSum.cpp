class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector <long long int> dp(1+target, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            long long int sum = 0;
            for(auto ele: nums){
                if(ele <= i && sum <= 1e11) sum += dp[i-ele]; // leetcode is wrong!!
            }
            dp[i] = sum;
        }
        return dp[target];
    }
};