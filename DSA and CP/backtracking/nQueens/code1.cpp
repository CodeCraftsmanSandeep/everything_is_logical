/*
I think the recurrence relation is:
T(n) = n + n*T(n-1)

which is much greater than O(n!)
but in GFG it is given O(n!), I guess it is false
*/

class Solution{
public:
    void recurse(int n, int i, int j, vector <vector <int>>& marked, vector <vector <int>>& positions, vector <int>& pos, int& index){
        pos[++index] = j + 1;
        if(i == n-1){
            positions.push_back(pos);
            index--;
            return;
        }
        
        marked[i][j]++;
        int row = i + 1;
        int col1 = j - 1;
        int col2 = j;
        int col3 = j + 1;
        while(row < n){
            if(col1 >= 0) marked[row][col1--]++;
            marked[row][col2]++;
            if(col3 < n) marked[row][col3++]++;
            row++;
        }
        
        for(int j = 0; j < n; j++){
            if(marked[i+1][j] == 0) recurse(n, i+1, j, marked, positions, pos, index);
        }
        
        row = i + 1;
        col1 = j - 1;
        col2 = j;
        col3 = j + 1;
        while(row < n){
            if(col1 >= 0) marked[row][col1--]--;
            marked[row][col2]--;
            if(col3 < n) marked[row][col3++]--;
            row++;
        }
        marked[i][j]--;
        index--;
    }

    vector<vector<int>> nQueen(int n) {
        vector <vector <int>> marked(n, vector <int> (n, 0));
        vector <vector <int>> positions;
        vector <int> pos(n);
        int index = -1;
        for(int j = 0; j < n; j++) recurse(n, 0, j, marked, positions, pos, index);
        return positions;
    }
};
