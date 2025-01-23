// O(n^2) time
// O(1) space
int celebrity(vector<vector<int> >& mat){
    int n = mat.size();
    for(int j = 1; j < n; j++) mat[0][j] += mat[0][j-1];
    for(int i = 1; i < n; i++){
        mat[i][0] += mat[i-1][0];
        for(int j = 1; j < n; j++) mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
    }
    
    for(int i = 0; i < n; i++){
        int row_sum = mat[i][n-1];
        if(i > 0) row_sum -= mat[i-1][n-1];
            
        int col_sum = mat[n-1][i];
        if(i > 0) col_sum -= mat[n-1][i-1];
            
        if(row_sum == 0 && col_sum == n-1) return i;
    }
    
    return -1;
}