class Solution {
  public:
    vector<int> twoRepeated(int n, int arr[]) {
        int xor_val = 0;
        for(int i = 0; i < n + 2; i++) xor_val ^= arr[i];
        for(int i = 1; i <= n; i++) xor_val ^= i;
        
        int right_most_set_bit = xor_val & (-xor_val);
        int x = 0;
        int y = 0;
        for(int i = 0; i < n + 2; i++){
            if(arr[i] & right_most_set_bit) x ^= arr[i];
            else y ^= arr[i];
        }
        
        for(int i = 1; i <= n; i++){
            if(i & right_most_set_bit) x ^= i;
            else y ^= i;
        }
        
        bool x_occur = false;
        bool y_occur = false;
        for(int i = 0; i < n + 2; i++){
            if(arr[i] == x){
                if(x_occur) return {x, y};
                x_occur = true;
            }else if(arr[i] == y){
                if(y_occur) return {y, x};
                y_occur = true;
            }
        }
    }
};