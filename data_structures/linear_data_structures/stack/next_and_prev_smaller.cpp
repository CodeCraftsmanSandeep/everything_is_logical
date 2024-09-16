void prev_and_next_index(vector <long long>& arr) {
    // next_index[i] = next index with smallest number
    // prev_index[i] = prev index with smallest number
    
    int n = arr.size();
    vector <int> prev_index(n), next_index(n);
    stack <int> st;
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            int curr_index = st.top();
            st.pop();
            
            next_index[curr_index] = i;
            if(st.empty()) prev_index[curr_index] = -1;
            else prev_index[curr_index] = st.top();
        }
        st.push(i);
    }
    while(!st.empty()){
        int curr_index = st.top();
        st.pop();
        
        next_index[curr_index] = n;
        if(st.empty()) prev_index[curr_index] = -1;
        else prev_index[curr_index] = st.top();
    }
}