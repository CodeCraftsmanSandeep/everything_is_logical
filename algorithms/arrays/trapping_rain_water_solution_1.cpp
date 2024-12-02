class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return 0;

        vector <int> left_max = arr;
        vector <int> right_max = arr;

        for(int i = 1; i < n; i++) left_max[i] = max(left_max[i-1], left_max[i]);
        for(int i = n-2; i >= 0; i--) right_max[i] = max(right_max[i+1], right_max[i]);

        int water = 0;
        for(int i = 1; i <= n-2; i++) water += max(min(left_max[i], right_max[i]) - arr[i], 0);
        return water;
    }
};