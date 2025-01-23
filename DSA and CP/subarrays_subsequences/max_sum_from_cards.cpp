class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        // attatch arr back of arr
        int n = arr.size();
        int low = n-k;
        int high = n-1;
        int curr_sum = accumulate(arr.begin() + low, arr.end(), 0);
        int max_sum = curr_sum;
        while(low != 0){
            curr_sum -= arr[low];
            
            low = (low + 1) % n;
            high = (high + 1) % n;

            curr_sum += arr[high];
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};