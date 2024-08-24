class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        vector <bool> dp(n + 1, false);
        // dp[i] = s[i:] is possible using wordDict
        dp[n] = true;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                int k;
                bool isPresent = true;
                for(k = i; k <= n-1 && k-i < wordDict[j].size(); k++){
                    if(s[k] != wordDict[j][k-i]){
                        isPresent = false;
                        break;
                    }
                }
                if((isPresent) && (k-i != wordDict[j].size())) isPresent = false;
                if(isPresent){
                    dp[i] = dp[k];
                    if(dp[i]) break;
                }
            }
        }
        return dp[0];
    }
};