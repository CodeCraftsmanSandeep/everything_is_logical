class Solution {
public:
    // O(1) solution
    int rob_prev(vector<int>& arr, int low, int high) {
        int n = low - high + 1;
        if(n == 1) return arr[low];
        int prev_prev = arr[low];
        int prev = max(arr[low], arr[low+1]);
        for(int i = low + 2; i <= high; i++){
            int curr = max(prev, arr[i] + prev_prev);
            prev_prev = prev;
            prev = curr;
        }
        return prev;

    }

    int rob(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        return max(rob_prev(arr, 0, n-2), rob_prev(arr, 1, n-1));
    }
};