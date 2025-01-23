class Solution{
  public:
    bool pairSum(int arr[], int low, int high, int val){
        while(low < high){
            if(arr[low] + arr[high] < val) low++;
            else if(arr[low] + arr[high] > val) high--;
            else return true;
        }
        return false;
    }
  
    bool findTriplets(int arr[], int n){
        sort(arr, arr + n);
        for(int i = 0; i < n; i++){
            if(pairSum(arr, i + 1, n-1, -arr[i])) return true;
        }
        return false;
    }
};