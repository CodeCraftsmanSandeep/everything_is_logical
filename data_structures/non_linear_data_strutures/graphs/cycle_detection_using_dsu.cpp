class Solution {
  public:
    // using DSU
    int find_parent(int u, vector <int>& parent){
        if(parent[u] == u) return u;
        return parent[u] = find_parent(parent[u], parent);
    }
    
    bool merge(int u, int v, vector <int> adj[], vector <int>& parent){
        int p1 = find_parent(u, parent);
        int p2 = find_parent(v, parent);
        if(p1 == p2) return true;
        parent[p1] = p2;
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector <int> parent(V, 0);
        iota(parent.begin(), parent.end(), 0);
        
        for(int u = 0; u < V; u++){
            for(int v: adj[u]){
                if(u > v) continue; // lets add each edge only once
                if(merge(u, v, adj, parent)) return true;
            }
        }
        return false;
    }
};