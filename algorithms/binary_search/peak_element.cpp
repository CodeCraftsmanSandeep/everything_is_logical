class Solution
{
    public:
    int peakElement(int arr[], int n){
        if(n == 1) return 0;
        int low = 0;
        int high = n-1;
        
        while(low < high){
            int mid = (low + high)/2;
            if(arr[mid] <= arr[mid + 1]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};