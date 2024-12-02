
class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2) return 0;

        int left_max = 0;
        int right_max = 0;

        int low = 0;
        int high = n - 1;

        int water = 0;
        while(low <= high){
            if(left_max <= right_max){
                water += max(0, left_max - arr[low]);
                left_max = max(left_max, arr[low++]);
            }else{
                water += max(0, right_max - arr[high]);
                right_max = max(right_max, arr[high--]);
            }
        }
        return water;
    }
};