// optimized solution
class Solution{
public:
    void recurse(int n, int i, int j, vector <int>& right_col, vector <int>& down_col, vector <int>& left_col, vector <vector <int>>& positions, vector <int>& pos, int& index){
        left_col[i+j]++;
        down_col[j]++;
        right_col[(n-1) + (i-j)]++;
        pos[++index] = j + 1;
        
        if(i < n-1){
            int row = i + 1;
            for(int col = 0; col < n; col++){
                if(left_col[row + col] == 0 && down_col[col] == 0 && right_col[(n-1) + (row - col)] == 0) recurse(n, row, col, right_col, down_col, left_col, positions, pos, index);
            }
        }else positions.push_back(pos);

        left_col[i+j]--;
        down_col[j]--;
        right_col[(n-1) + (i-j)]--;
        index--;
    }

    vector<vector<int>> nQueen(int n) {
        vector <int> left_col(2*(n-1) + 1, 0);
        vector <int> right_col(2*(n-1) + 1, 0);
        vector <int> down_col(n, 0);
        
        vector <vector <int>> positions;
        vector <int> pos(n);
        int index = -1;
        for(int j = 0; j < n; j++){
            recurse(n, 0, j, right_col, down_col, left_col, positions, pos, index);
        }
        
        return positions;
    }
};