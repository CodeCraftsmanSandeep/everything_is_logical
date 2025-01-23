class Solution {
    // histogram problem
    int largestRectangleArea(vector<int>& arr) {
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
        
        int max_area = 0;
        for(int i = 0; i < n; i++) max_area = max(max_area, arr[i] * (nse_index[i] - pse_index[i] - 1));
        return max_area;
    }
public:

    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector <int> height(n, 0);
        int max_area = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0') height[j] = 0;
                else height[j]++;
            }

            max_area = max(max_area, largestRectangleArea(height));
        }
        return max_area;
    }
};

// preq: https://leetcode.com/problems/largest-rectangle-in-histogram/