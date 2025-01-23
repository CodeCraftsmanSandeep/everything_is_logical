// GFG solution
// O(n) time
// O(1) space
int celebrity(vector<vector<int> >& mat){
    int n = mat.size();
    int low = 0;
    int high = n-1;
    
    while(low < high){
        if(mat[low][high] == 0){
            // high is not celabrity
            high--;
        }else{
            // low is not celebraity
            low++;
        }
    }
    
    // check if low is celebraity
    int row_sum = 0;
    for(int j = 0; j < n; j++) row_sum += mat[low][j];
    int col_sum = 0;
    for(int i = 0; i < n; i++) col_sum += mat[i][low];
    
    if(row_sum == 0 && col_sum == n-1) return low;
    return -1;
}