// O(nlogn) using binary search
int leastIndex(vector <int>& LIS, int low, int high, int ele){
    while(low < high){
        int mid = (low + high)/2;
        if(LIS[mid] < ele) low = mid + 1;
        else high = mid;
    }
    return low;
}

int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector <int> dp(n);
    vector <int> LIS(n);
    LIS[0] = arr[0];
    int index = 0;
    dp[0] = 1;
    int max_len = 1;
    cout << 1 << " ";
    for(int i = 1; i < n; i++){
        if(LIS[index] < arr[i]) LIS[++index] = arr[i];
        else{
            // least j such that LIS[j] > arr[i]
            LIS[leastIndex(LIS, 0, index, arr[i])] = arr[i];
        }
        cout << index + 1 << " ";
        max_len = max(max_len, index + 1);
    }
    cout << "\n";
    return max_len;
}