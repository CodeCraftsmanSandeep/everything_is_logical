class Solution {
public:
    int search(vector<int>& arr, int key) {
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[high] >= arr[mid]){
                if(arr[high] < key) high = mid - 1;
                else if(arr[mid] <= key) low = mid + 1;
                else high = mid - 1;
            }else{
                if(key < arr[low]) low = mid + 1;
                else if(key <= arr[mid]) high = mid;
                else low = mid + 1;
            }
        }
        if(high >= 0 && arr[high] == key) return high;
        return -1;
    }
};