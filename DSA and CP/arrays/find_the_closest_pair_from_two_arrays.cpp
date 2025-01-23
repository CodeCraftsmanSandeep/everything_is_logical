class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int l = 0;
        int r = m - 1;
        int diff = INT_MAX;
        vector <int> ans = {-1, -1};
        while(l < n && r >= 0){
            if(abs(arr[l] + brr[r] - x) < diff){
                diff = abs(arr[l] + brr[r] - x);
                ans[0] = arr[l];
                ans[1] = brr[r];
            }
            
            if(arr[l] + brr[r] > x) r--;
            else l++;
        }
        return ans;
    }
};