class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector <long long int> dp(n, 0);
        vector <long long int> pref(n, 0);
        vector <long long int> mapping(n, 0);
        stack <long long int> index;
        long long int max_index = 0;
        index.push(0);
        pref[1] = arr[0];
        for(int i = 1; i < n; i++){
            while(!index.empty() && arr[index.top()] < arr[i]) index.pop();
            if(index.empty()){
                long long int between_sum = pref[i-1] - pref[max_index];
                dp[max_index] = arr[max_index] * (i - max_index - 1) - between_sum;
                mapping[max_index] = i;
            }else{
                long long int between_sum = pref[i-1] - pref[index.top()];
                dp[index.top()] = arr[i] * (i - index.top() - 1) - between_sum;
                mapping[index.top()] = i;
            }
            pref[i] = pref[i-1] + arr[i];
            index.push(i);
            if(arr[max_index] <= arr[i]) max_index = i;
        }
        
        long long int ans = 0;
        int i = 0;
        while(i < n-1){
            ans += dp[i];
            i = mapping[i];
        }
        return ans;
    }
};