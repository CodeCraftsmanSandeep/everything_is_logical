// O(nlogn) time using segment tree
int get_val(int root, int low, int high, int index, vector <int>& segment_tree){
    if(high == index) return segment_tree[root];
    int mid = (low + high)/2;
    if(index <= mid) return get_val(2*root+1, low, mid, index, segment_tree);
    return max(segment_tree[2*root+1], get_val(2*root+2, mid+1, high, index, segment_tree));
}

int update(int root, int low, int high, int index, int new_val, vector <int>& segment_tree){
    if(low == high) return segment_tree[root] = new_val;
    int mid = (high + low)/2;
    if(index <= mid) return segment_tree[root] = max(segment_tree[root], update(2*root+1, low, mid, index, new_val, segment_tree));
    return segment_tree[root] = max(segment_tree[root], update(2*root + 2, mid + 1, high, index, new_val, segment_tree));
}

int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector <int> dp(n);
    vector <int> segment_tree(4*n, 0);
    vector <pair<int,int>> vec(n);
    for(int i = 0; i < n; i++){
        vec[i].first = arr[i];
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end());

    int i = 0;
    while(i < n){
        int j;
        for(j = i; j < n && vec[j].first == vec[i].first; j++) dp[vec[j].second] = 1+get_val(0, 0, n-1, vec[j].second, segment_tree);
        for(j = i; j < n && vec[j].first == vec[i].first; j++) update(0, 0, n-1, vec[j].second, dp[vec[j].second], segment_tree);
        i = j;
    }
    return *max_element(dp.begin(), dp.end());
}