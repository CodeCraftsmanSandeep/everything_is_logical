// two pointer approach
// O(n) time
// O(1) space
class Solution{
    public:
    long long trappingWater(int arr[], int n){
        int i = 0;
        int j = n-1;
        
        int left_max = 0;
        int right_max = 0;
        
        long long int ans = 0;
        while(i <= j){
            if(left_max <= right_max){
                ans += max(0, left_max - arr[i]);
                left_max = max(left_max, arr[i++]);
            }else{
                ans += max(0, right_max - arr[j]);
                right_max = max(right_max, arr[j--]);
            }
        }
        return ans;
    }
};