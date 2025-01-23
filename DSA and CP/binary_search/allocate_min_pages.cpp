// Function to find minimum number of pages.
long long findPages(vector <int>& arr, int n, int m){
    if(m > n) return -1;
    
    long long low = arr[0];
    for(int i = 1; i < n; i++){
        low = max(low, (long long int)arr[i]);
        arr[i] += arr[i-1];
    }
    long long int high = arr[n-1];
    
    while(low < high){
        long long mid = (high + low)/2;
        // whether it is possible that answer is <= mid
        
        int start = 0;
        int groups = 0;
        long long int max_sum = 0;
        long long int prev_sum = 0;
        while(start < n && groups <= m){
            int j = upper_bound(arr.begin() + start, arr.end(), prev_sum + mid) - arr.begin();
            long long int curr_sum = arr[j-1] - prev_sum;
            max_sum = max(max_sum, curr_sum);
            prev_sum = arr[j-1];
            start = j;
            groups++;
        }
        
        if(groups <= m) high = max_sum;
        else low = mid + 1;
    }
    return high;
}