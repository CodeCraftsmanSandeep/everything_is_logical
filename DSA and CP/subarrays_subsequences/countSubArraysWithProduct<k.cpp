class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        if(k <= 1) return 0;
        int low = 0;
        int high = 0;
        int n = arr.size();
        int currProduct = 1;
        int count = 0;
        while(high < n){
            while(high < n && currProduct < k){
                count += high - low;
                currProduct *= arr[high++];
            }
            while(currProduct >= k) currProduct /= arr[low++];
        }
        count += high - low;
        return count;
    }
};