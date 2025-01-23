// Find maximum of minimum for every window size in a given array
#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

vector <int> find_max_of_min(const vector <int>& arr, int n){
    vector <int> next_small_index(n);
    stack <int> st;
    for(int i = n-1; i >= 0; i--){
        while((!st.empty()) && (arr[st.top()] >= arr[i])) st.pop();
        if(st.empty()){
            next_small_index[i] = n;
        }else next_small_index[i] = st.top();
        st.push(i);
    }
    st = stack <int> (); // new empty stack

    vector <int> prev_small_index(n);
    for(int i = 0; i < n; i++){
        while((!st.empty()) && (arr[st.top()] >= arr[i])) st.pop();
        if(st.empty()) prev_small_index[i] = -1;
        else prev_small_index[i] = st.top();
        st.push(i);
    }

    vector <int> ans(n, -1);
    for(int i = 0; i < n; i++){
        int len = next_small_index[i] - prev_small_index[i] - 1;
        ans[len-1] = max(ans[len-1], arr[i]);
    }
    for(int i = n-2; i >= 0; i--) ans[i] = max(ans[i], ans[i+1]);
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector <int> ans = find_max_of_min(arr, n);

    for(auto ele: ans) cout << ele << " ";
    cout << "\n";

}