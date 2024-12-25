class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        int i = 0;
        int ans = 0;
        while(i < n){
            int j = i;
            int neg_ele = 0;
            int first_index = -1;
            int last_index = -1;
            while(j < n && arr[j] != 0){
                if(arr[j] < 0){
                    neg_ele++;
                    if(first_index == -1) first_index = j;
                    last_index = j;
                }
                j++;
            }
            int temp = 1;
            for(int k = first_index + 1; k < j; k++) temp *= arr[k];
            if(first_index + 1 < j) ans = max(ans, temp);

            temp = 1;
            for(int k = i; k < last_index; k++) temp *= arr[k];
            if(i < last_index) ans = max(ans, temp);

            temp = 1;
            for(int k = i; k < j; k++) temp *= arr[k];
            if(i < j) ans = max(ans, temp);
            i = j + 1;
        }
        return ans;
    }
};