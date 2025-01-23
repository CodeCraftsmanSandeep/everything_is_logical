class Solution {
    int numSubarraysWithLessThanOrEqualToSum(vector <int>& arr, int goal){
        if(goal < 0) return 0;
        int curr_sum = 0;
        int low = 0;
        int high = 0;
        const int n = arr.size(); 
        int numSubarrays = 0;

        while(high < n){
            while(high < n && curr_sum + arr[high] <= goal){
                numSubarrays += (high - low + 1);
                curr_sum += arr[high++];
            }
            while(curr_sum == goal && low <= high) curr_sum -= arr[low++];
        }
        return numSubarrays;
    }

public:
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        // ans = (number of subarrays with sum <= goal) - (number of subarrays with sum <= goal -1)
        return numSubarraysWithLessThanOrEqualToSum(arr, goal) - numSubarraysWithLessThanOrEqualToSum(arr, goal - 1);
    }
};