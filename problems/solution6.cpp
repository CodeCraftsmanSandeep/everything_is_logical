#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(int n, string s, int m, string t){
    // length(t) <= length(s)
    vector <int> dp(m+1, 0);
    int next_ele, new_next_ele;
    for(int i = n-1; i >= 0; i--){
        next_ele = dp[m]; // dp[i+1][j+1] value
        for(int j = m-1; j >= 0; j--){
            new_next_ele = dp[j];
            dp[j] = (s[i] == t[j] ? 1 + next_ele : max(dp[j], dp[j+1]));
            next_ele = new_next_ele;
        }
    }
    return dp[0];
}

int solve(string s, string t) {
    int n = s.size();
    int m = t.size();

    if(n > m) return longestCommonSubsequence(n, s, m, t);
    else return longestCommonSubsequence(m, t, n, s);
}

int main(){
    string s, t;
    cin >> s >> t;

    cout << solve(s, t) << "\n";
}
