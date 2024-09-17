class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector <vector <int>> row(1+n, vector <int> (1+m, 0));
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(mat[i][j] == 0) continue;
                row[i][j] = 1 + row[i][j+1];
            }
        }
        
        vector <vector <int>> col(1+n, vector <int> (1+m, 0));
        for(int j = m-1; j >= 0; j--){
            for(int i = n-1; i >= 0; i--){
                if(mat[i][j] == 0) continue;
                col[i][j] = 1 + col[i+1][j];
            }
        }
        
        vector <vector <int>> dp(1+n, vector <int> (1+m, 0));
        int max_dim = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int min_d = min(row[i][j], col[i][j]);
                if(dp[i+1][j+1] >= min_d - 1){
                    dp[i][j] = min_d;
                }else dp[i][j] = dp[i+1][j+1] + 1;
                max_dim = max(max_dim, dp[i][j]);
            }
        }
        return max_dim;
    }
};