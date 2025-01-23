// optimized code
class Solution
{
    public:
    string smallestWindow (string s, string p){
        vector <int> freq(26, 0);
        for(auto ch: p) freq[ch - 'a']++;
        
        vector <int> curr_freq(26, 0);
        int low = 0;
        int high = 0;
        int i = 0;
        while(i < 26 && high < s.size()){
            while(high < s.size() && freq[i] > curr_freq[i]) curr_freq[s[high++] - 'a']++;
            if(freq[i] <= curr_freq[i]) i++;
        }
        while(i < 26){
            if(freq[i] > curr_freq[i]) return "-1";
            i++;
        }
        while(low < high){
            if(curr_freq[s[low] - 'a'] - 1 >= freq[s[low] - 'a']){
                curr_freq[s[low++] - 'a']--;
            }else break;
        }
        int window = high - low;
        int ans_low = low;
        char prev = s[low];
        curr_freq[s[low++] - 'a']--;
        
        while(high < s.size()){
            while(high < s.size() && s[high] != prev) curr_freq[s[high++] - 'a']++;
            if(high == s.size()) break;
            curr_freq[prev - 'a']++;
            high++;
            while(low < high){
                if(curr_freq[s[low] - 'a'] - 1 >= freq[s[low] - 'a']){
                    curr_freq[s[low++] - 'a']--;
                }else break;
            }
            if(window > high - low){
                window = high - low;
                ans_low = low;
            }
            prev = s[low];
            curr_freq[s[low++] - 'a']--;
        }
        return s.substr(ans_low, window);
    }
};