
class Solution {
public:
    void neighbour(int pi, int pj, int ci, int cj, int n, int m, vector <vector <bool>>& visited, vector <vector <int>>& heights){
        if(ci < 0 || ci >= n || cj < 0 || cj >= m || visited[ci][cj] || heights[pi][pj] > heights[ci][cj]) return;
        mark_reachable(ci, cj, n, m, visited, heights);
    }

    // dfs
    void mark_reachable(int i, int j, int n, int m, vector <vector <bool>>& visited, vector <vector <int>>& heights){
        visited[i][j] = true;
        neighbour(i, j, i+1, j, n, m, visited, heights);
        neighbour(i, j, i-1, j, n, m, visited, heights);
        neighbour(i, j, i, j+1, n, m, visited, heights);
        neighbour(i, j, i, j-1, n, m, visited, heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // reachable from pacific
        vector <vector <bool>> pacific(n, vector <bool> (m, false));
        vector <vector <bool>> atlantic(n, vector <bool> (m, false));
        for(int i = 0; i < n; i++){
            if(pacific[i][m-1] == false) mark_reachable(i, m-1, n, m, pacific, heights);
            if(atlantic[i][0] == false) mark_reachable(i, 0, n, m, atlantic, heights);
        }

        for(int j = 0; j < m; j++){
            if(pacific[n-1][j] == false) mark_reachable(n-1, j, n, m, pacific, heights);
            if(atlantic[0][j] == false) mark_reachable(0, j, n, m, atlantic, heights);
        }

        vector <vector <int>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};