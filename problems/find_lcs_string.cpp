string findLCS(int n1, int n2,string &text1, string &text2){
	// these are good ones!
	vector <vector <int>> dp(n1+1, vector <int> (n2+1, 0));
	vector < vector <int>> index(n1 + 1, vector <int> (n2+1, -1));
	for(int i = 1; i <= n1; i++){
		for(int j = 1; j <= n2; j++){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if(text1[i-1] == text2[j-1]) dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
		}
	}
	string ans;
	int i = n1;
	int j = n2;
	while(i > 0 && j > 0){
		if(dp[i][j] == dp[i-1][j]) i--;
		else if(dp[i][j] == dp[i][j-1]) j--;
		else{
			// true: dp[i][j] == 1+dp[i-1][j-1]
			ans = text1[i-1] + ans;
			i = i-1;                   
			j = j-1;
		}
	}
	return ans;
}
