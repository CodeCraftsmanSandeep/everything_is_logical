class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> is_present(nums.begin(), nums.end());
        int max_len = 0;
        for(auto ele: is_present){
            if(is_present.find(ele - 1) != is_present.end()) continue;
            int len = 1;
            while(is_present.find(ele + len) != is_present.end()) len++;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};