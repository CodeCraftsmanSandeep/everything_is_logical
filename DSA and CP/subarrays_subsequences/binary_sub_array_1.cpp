class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int goal) {
        int countOfSubArrays = 0;
        int n = arr.size();

        if(goal == 0){
            int i = 0;
            while(i < arr.size()){
                int zeros = 0;
                while(i < n && arr[i] == 0){
                    zeros++;
                    i++;
                }
                i++;
                countOfSubArrays += zeros * (zeros + 1) / 2;
            }
            return countOfSubArrays;
        }

        int low = 0;
        int high = 0;
        int curr_sum = 0;

        while(high < n){
            while(high < n && curr_sum < goal) curr_sum += arr[high++];
            int prev_zeros = 0;
            while(arr[low] == 0){
                prev_zeros++;
                low++;
            }

            int next_zeros = 0;
            while(high < n && arr[high] == 0){
                next_zeros++;
                high++;
            }

            if(curr_sum == goal) countOfSubArrays += (prev_zeros + 1) * (next_zeros + 1);
            curr_sum -= arr[low++];
        }
        return countOfSubArrays;
    }
};