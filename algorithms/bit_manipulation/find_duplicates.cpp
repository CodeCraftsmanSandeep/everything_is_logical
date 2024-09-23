class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int xor_value = 0;
        for(auto ele: arr) xor_value ^= ele;
        for(int i = 1; i <= n; i++) xor_value ^= i;
        
        // a ^ b = xor_value
        int right_most_set_bit = xor_value & (-xor_value);
        int val1 = 0;
        int val2 = 0;
        for(auto ele: arr){
            if(ele & right_most_set_bit){
                val1 ^= ele;
            }else{
                val2 ^= ele;
            }
        }
        
        for(int i = 1; i <= n; i++){
            if(i & right_most_set_bit){
                val1 ^= i;
            }else{
                val2 ^= i;
            }
        }
        
        for(auto ele: arr){
            if(ele == val1) return {val1, val2};
            if(ele == val2) return {val2, val1};
        }
        // returning {b, a}
    }
};
