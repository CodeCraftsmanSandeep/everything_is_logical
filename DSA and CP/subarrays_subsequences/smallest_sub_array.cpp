class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int low = 0;
        int high = 0;
        int prev = 0;
        int len = INT_MAX;
        while(high < arr.size()){
            while(high < arr.size() && prev <= x) prev += arr[high++];
            while(low < high && prev - arr[low] > x) prev -= arr[low++];
            if(prev > x){
                len = min(len, high - low);
                prev -= arr[low++];
            }
        }
        if(len == INT_MAX) return 0;
        return len;
    }
};
// O(n) time
// O(1) space
// 2 pointer approach