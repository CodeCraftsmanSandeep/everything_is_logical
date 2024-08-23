vector<int> mergeKArrays(vector<vector<int>> arr, int k){
    auto custom_comp = [&arr](const pair<int,int>& pos1, const pair<int,int>& pos2){
        return arr[pos1.first][pos1.second] > arr[pos2.first][pos2.second];
    };
    
    vector <int> ans;
    priority_queue <pair <int,int>, vector <pair<int,int>>, decltype(custom_comp)> min_pq(custom_comp);
    
    for(int i = 0; i < k; i++) min_pq.push(make_pair(i, 0));
    while(!min_pq.empty()){
        auto min_pos = min_pq.top();
        min_pq.pop();
        ans.push_back(arr[min_pos.first][min_pos.second]);
        if(++min_pos.second < k) min_pq.push(make_pair(min_pos.first, min_pos.second));
    }
    return ans;
}