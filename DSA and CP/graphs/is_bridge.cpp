class Solution
{
	public:
	void normal_dfs(int u, vector <bool>& visited, vector <int> adj[]){
	    if(visited[u]) return;
	    visited[u] = true;
	    for(auto v: adj[u]) normal_dfs(v, visited, adj);
	}
	
    int isBridge(int V, vector<int> adj[], int c, int d){
        vector <bool> visited(V, false);
        visited[c] = true;
        for(auto v: adj[c]){
            if(v == d) continue;
            normal_dfs(v, visited, adj);
        }
        return (!visited[d]);
    }
};
