long long int maxSubarraySum(vector<int> &arr) {
    long long int maxSubArraySum = arr[0];
    long long int maxEnding = arr[0];
    for(int i = 1; i < arr.size(); i++){
        maxEnding = max(maxEnding + arr[i],(long long int) arr[i]);
        maxSubArraySum = max(maxSubArraySum, maxEnding);
    }
    return maxSubArraySum;
}