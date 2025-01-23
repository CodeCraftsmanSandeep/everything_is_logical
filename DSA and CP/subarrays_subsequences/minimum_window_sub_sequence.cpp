string minWindow(string s, string t){
	int n = s.size();
	int m = t.size();

	vector < vector < pair <int, int> > > dp(m, vector < pair <int, int> > (n + 1, {-1, INT_MAX}));

	for(int i = m-1; i >= 0; i--){
		for(int j = n-1; j >= 0; j--){
			dp[i][j] = dp[i][j+1];

			if(t[i] == s[j]){
				if(i == m-1){
					dp[i][j] = {j, 1};
				}else if(dp[i+1][j+1].first != -1 && (dp[i][j].second >= dp[i+1][j+1].second + dp[i+1][j+1].first - j)){
					dp[i][j] = {j, dp[i+1][j+1].second + dp[i+1][j+1].first - j};
				}
			}
		}
	}

	if(dp[0][0].first == -1) return "";
	return s.substr(dp[0][0].first, dp[0][0].second);
}