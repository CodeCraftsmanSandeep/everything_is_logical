class Solution
{
    public:
    string smallestWindow (string s, string p){
        vector <int> freq(26, 0);
        for(auto ch: p) freq[ch - 'a']++;
        
        vector <int> curr_freq(26, 0);
        int low = 0;
        int high = 0;
        int window = INT_MAX;
        int ans_low;
        
        while(high < s.size()){
            int i = 0;
            while(i < 26 && high < s.size()){
                while(high < s.size() && freq[i] > curr_freq[i]) curr_freq[s[high++] - 'a']++;
                if(freq[i] <= curr_freq[i]) i++;
            }
            bool is_substring = true;
            while(i < 26){
                if(freq[i] > curr_freq[i]){
                    is_substring = false;
                    break;
                }
                i++;
            }
            if(!is_substring) break;
            while(low < high){
                if(curr_freq[s[low] - 'a'] - 1 >= freq[s[low] - 'a']){
                    curr_freq[s[low++] - 'a']--;
                }else break;
            }
            if(window > high - low){
                window = high - low;
                ans_low = low;
            }
            curr_freq[s[low++] - 'a']--;
        }
        if(window == INT_MAX) return "-1";
        return s.substr(ans_low, window);
    }
};