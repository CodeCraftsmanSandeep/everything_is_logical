// using deque 
// Time : O(n)
// Space: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque <int> dq;
        vector <int> maxEleOfWindow(n - k + 1);

        for(int i = n-1; i >= n-k+1; i--){
            while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
        }
        for(int i = n-k; i >= 0; i--){
            while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
            maxEleOfWindow[i] = arr[dq.front()];
            if(dq.front() - i + 1 == k) dq.pop_front();
        }
        return maxEleOfWindow;
    }
};