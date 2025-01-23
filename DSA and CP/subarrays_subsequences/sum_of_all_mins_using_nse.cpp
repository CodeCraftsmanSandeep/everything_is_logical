long long int mod = 1e9 + 7;
#define ll long long int
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // solving using next smaller element logic
        int n = arr.size();
        stack < pair <int, long long int> > nse_index;
        long long int min_sum = 0;

        for(long long int i = n-1; i >= 0; i--){
            while(!nse_index.empty() && arr[nse_index.top().first] >= arr[i]) nse_index.pop();

            if(nse_index.empty()){
                nse_index.push({i, (n-i) * arr[i]});
            }else{
                nse_index.push({i, (nse_index.top().first - i) * arr[i] + nse_index.top().second});
            }
            min_sum = (min_sum + nse_index.top().second) % mod;
        }

        return min_sum;
    }
};