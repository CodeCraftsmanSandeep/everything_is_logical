class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        pair <int, int> new_arr[n];
        for(int i = 0; i < n; i++){
            new_arr[i].first = arr[i];
            new_arr[i].second = i;
        }
        sort(new_arr, new_arr + n);
        int max_index = new_arr[n-1].second;
        int ans = 0;
        for(int j = n-2; j >= 0; j--){
            ans = max(ans, max_index - new_arr[j].second);
            max_index = max(max_index, new_arr[j].second);
        }
        return ans;
    }

};