class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        int max_go = 0;
        for(int i = 0; max_go < n-1 && i < n && i <= max_go; i++){
            max_go = max(max_go, i + arr[i]);
        }
        return (max_go >= (n-1));
    }
};