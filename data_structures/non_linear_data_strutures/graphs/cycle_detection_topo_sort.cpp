class Solution {
  public:
    bool isCyclic(int n, vector<int> adj[]) {
        vector <int> in_degree(n, 0);
        for(int u = 0; u < n; u++){
            for(auto v: adj[u]) in_degree[v]++;
        }
        
        vector <int> q;
        for(int u = 0; u < n; u++) if(in_degree[u] == 0) q.push_back(u);
        
        int i = 0;
        while(i < q.size()){
            int u = q[i++];
            for(int v: adj[u]){
                in_degree[v]--;
                if(in_degree[v] == 0) q.push_back(v);
            }
        }
        return (i!= n);
    }
};
