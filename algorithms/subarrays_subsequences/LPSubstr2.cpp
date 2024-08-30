string longestPalin (string str){
    int n = str.size();
    vector <vector <int>> dp(n, vector <int> (n, 0));
    int low = 0;
    int high = 0;
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
        for(int j = i-1; j >= 0; j--){
            if(str[i] == str[j]){
                if(i - 1 < j + 1) dp[i][j] = 2;
                else if(dp[i-1][j+1] != 0) dp[i][j] = 2 + dp[i-1][j+1];


                if(dp[i][j] > high - low + 1){
                    high = i;
                    low = j;
                }else if(dp[i][j] == high - low + 1 && j < low){
                    high = i;
                    low = j;
                }
            }
        }
    }
    return str.substr(low, high - low + 1);
}