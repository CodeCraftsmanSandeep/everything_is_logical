class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        long long int ans = INT_MIN;
        long long int sub_arr = 0;
        for(auto ele: arr){
            sub_arr += ele;
            ans = max(ans, sub_arr);
            if(sub_arr < 0){
                sub_arr = 0;
            }
        }
        return ans;
    }
};