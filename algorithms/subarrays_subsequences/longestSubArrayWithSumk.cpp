int lenOfLongestSubarr(vector<int>& arr, int k) {
    map <int, int> index;
    int pref = 0;
    index[0] = -1;
    int n = arr.size();
    int maxLen = 0;
    for(int i = 0; i < n; i++){
        pref += arr[i];
        auto it = index.find(pref - k);
        if(it != index.end()) maxLen = max(maxLen, i - it->second);
        if(index.find(pref) == index.end()) index[pref] = i;
    }
    return maxLen;
}