class Solution{
  public:
    int longestKSubstr(string s, int k) {
        vector <int> freq(26, 0);
        int uniq = 0;
        int low = 0;
        int high = 0;
        int ans = -1;
        int n = s.size();
        while(high < n){
            if(freq[s[high] - 'a'] == 0) uniq++;
            freq[s[high++] - 'a']++;
            while(uniq > k){
                if(freq[s[low] - 'a'] == 1) uniq--;
                freq[s[low++] - 'a']--;
            }
            if(uniq == k) ans = max(ans, high - low);
        }
        return ans;
    }
};
// my code is better than gfg article code of this question