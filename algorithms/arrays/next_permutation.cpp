class Solution {
public:
    void nextPermutation(vector<int>& arr){
        int n = arr.size();
        if(n <= 1) return;
        int indexPoint = -1;
        for(int i = n-2; i >= 0; i--){
            if(arr[i] < arr[i+1]){
                indexPoint = i;
                break;
            }
        }
        if(indexPoint == -1){
            reverse(arr.begin(), arr.end());
            return;
        }
        // int swapPoint = indexPoint + 1;
        // while(swapPoint + 1 <= n-1 && arr[swapPoint + 1] > arr[indexPoint]) swapPoint++;
        int swapPoint = lower_bound(arr.begin() + indexPoint + 1, arr.end(), arr[indexPoint], greater <int> ()) - arr.begin() - 1;
        swap(arr[indexPoint], arr[swapPoint]);
        reverse(arr.begin() + indexPoint + 1, arr.end());
    }
};