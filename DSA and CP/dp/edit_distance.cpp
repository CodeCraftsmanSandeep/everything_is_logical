// space can be optimized to O(min(n, m))
// time: O(n*m)
class Solution {
  public:
    int findDis(string& str1, string& str2){
        int n = str1.size();
        int m = str2.size();
        vector <vector <int>> dp(1+n, vector <int> (1+m, 0));
        for(int i = n; i >= 0; i--) dp[i][m] = n - i;
        for(int j = m; j >= 0; j--) dp[n][j] = m - j;
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(str1[i] == str2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = 1+min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
            }
        }
        return dp[0][0];
    }
  
    int editDistance(string str1, string str2){
        // i did the following check, so that number of columns >= rows, which will have cache benefit
        if(str1.size() <= str2.size()) return findDis(str1, str2);
        else return findDis(str2, str1);
    }
};