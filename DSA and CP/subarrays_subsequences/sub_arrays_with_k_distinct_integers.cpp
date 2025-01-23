class Solution {
    int subarraysWithLessThanOrEqualToKDistinct(vector <int>& arr, int k){
        if(k <= 0) return 0;
        int n = arr.size();

        int low = 0;
        int high = 0;
        int distinct = 0;
        int numSubArrays = 0;
        vector <int> freq((int) 2 * 1e4 + 1, 0);
        while(high < n){
            while(high < n && distinct + (freq[arr[high]] == 0) <= k){
                if(freq[arr[high]] == 0) distinct++;
                numSubArrays += (high - low + 1);
                freq[arr[high++]]++;
            }
            while(distinct == k){
                if(freq[arr[low]] == 1) distinct--;
                freq[arr[low++]]--;
            }
        }
        return numSubArrays;
    }

public:
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        return subarraysWithLessThanOrEqualToKDistinct(arr, k) - subarraysWithLessThanOrEqualToKDistinct(arr, k-1);
    }
};