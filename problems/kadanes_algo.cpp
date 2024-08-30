class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        long long int sum = 0;
        int max_ele = INT_MIN;
        long long int ans = 0;
        for(auto ele : arr){
            max_ele = max(max_ele, ele);
            sum += ele;
            if(sum < 0) sum = 0;
            ans = max(ans, sum);
        }
        if(max_ele < 0) return max_ele;
        return ans;
    }
};