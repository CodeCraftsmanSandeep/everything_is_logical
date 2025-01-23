/*
I think the recurrence relation is:
T(n) = n + n*T(n-1)

which is much greater than O(n!)
but in GFG it is given O(n!), I guess it is false
*/


class Solution{
public:
    bool is_safe(int n, int i, int j, vector <vector <bool>>& marked){
        int row = i - 1;
        int col1 = j-1;
        int col2 = j;
        int col3 = j+1;
        while(row >= 0){
            if(col1 >= 0 && marked[row][col1]) return false;
            if(marked[row][col2]) return false;
            if(col3 < n && marked[row][col3]) return false;
            col1--;
            col3++;
            row--;
        }
        return true;
    }
    
    
    void recurse(int n, int i, int j, vector <vector <bool>>& marked, vector <vector <int>>& positions, vector <int>& pos, int& index){
        marked[i][j] = true;
        pos[++index] = j + 1;
        if(i == n - 1){
            marked[i][j] = false;
            positions.push_back(pos);
            index--;
            return;
        }
        for(int col = 0; col < n; col++){
            if(is_safe(n, i+1, col, marked)){
                recurse(n, i + 1, col, marked, positions, pos, index);
            }
        }
        marked[i][j] = false;
        index--;
    }

    vector<vector<int>> nQueen(int n) {
        vector <vector <bool>> marked(n, vector <bool> (n, false));
        vector <vector <int>> positions;
        vector <int> pos(n);
        int index = -1;
        for(int j = 0; j < n; j++){
            recurse(n, 0, j, marked, positions, pos, index);
        }
        
        return positions;
    }
};


