#include <bits/stdc++.h>
using namespace std;

void prev_and_next_index(vector <long long>& arr) {
    // nse_index[i] = next smaller element index of ith element
    // pse_index[i] = previous smaller element index of ith element
    
    int n = arr.size();
    vector <int> pse_index(n), nse_index(n);
    stack <int> st;
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            nse_index[st.top()] = i;
            st.pop();
        }
        
        if(st.empty()) pse_index[i] = -1;
        else if(arr[st.top()] == arr[i]) pse_index[i] = pse_index[st.top()];
        else pse_index[i] = st.top();

        st.push(i);
    }
    while(!st.empty()){
        nse_index[st.top()] = n;
        st.pop();
    }

    for(int i = 0; i < n; i++){
        cout << "prev_index[" << i << "] = " << pse_index[i] << ", next_index[" << i << "] = " << nse_index[i] << "\n";
    }
}

int main(){
    int n;
    cin >> n;

    vector <long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    prev_and_next_index(arr);
}
