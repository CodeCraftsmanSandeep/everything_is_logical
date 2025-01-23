
int getMaxSubArraySum(vector <int>& arr, int n, int k){
    // return maxSubarray sum which is <= k
    set <int> prefixSum;
    int maxSubArraySum = INT_MIN;
    int prevSum = 0;
    prefixSum.insert(0);
    for(int i = 0; i < n; i++){
        prevSum += arr[i];
        auto it = prefixSum.lower_bound(prevSum - k);
        if(it != prefixSum.end()) maxSubArraySum = max(maxSubArraySum, prevSum - *it);
        prefixSum.insert(prevSum);
    }
    // INT_MIN is returned if every element in arr is > k
    return maxSubArraySum;
}