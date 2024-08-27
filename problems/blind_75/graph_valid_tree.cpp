class Solution {
  public:
    int find_rep(int u, vector <int>& parent){
        if(parent[u] == u) return u;
        return parent[u] = find_rep(parent[u], parent);
    }
  
    bool unite_components(int u, int v, vector <int>& parent){
        int p1 = find_rep(u, parent);
        int p2 = find_rep(v, parent);
        
        if(p1 == p2){
            // cylce (or) self edge
            return true;
        }
        parent[p1] = p2;
        return false;
    }
    
    // fact: if there are n-1 edges and no cycle then graph is a tree
    // another fact: A connected graph with n-1 edges contains no cycle
    int isTree(int n, int m, vector<vector<int>> &edges) {
        if(m != n-1) return 0; // tree has n-1 edges
        vector <int> parent(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(unite_components(u, v, parent)){
                // cycle found
                return 0;
            }
        }
        
        return 1;
    }
};
