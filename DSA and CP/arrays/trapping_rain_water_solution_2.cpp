// O(n) time
// O(1) space
class Solution {
public:
    int trap(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        int water = 0;
        int left_max = 0;
        int right_max = 0;

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

// This is the best code for trapping rain water problem