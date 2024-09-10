class Solution{
	public:
	void dfs(vector <vector <int> >& adjT, vector < vector <int>>& adj, stack <int>& s, vector <bool>& visited, int u){
	    visited[u] = true;
	    for(auto v: adj[u]){
	        adjT[v].push_back(u);
	        if(!visited[v]){
	            dfs(adjT, adj, s, visited, v);
	        }
	    }
	    s.push(u);
	}
	
	void explore(vector <vector <int>>& adj, vector <bool>& visited, int u){
	    visited[u] = true;
	    for(auto v: adj[u]) if(!visited[v]) explore(adj, visited, v);
	}
	
    int kosaraju(int V, vector<vector<int>>& adj){
        vector <vector <int> > adjT(V);
        stack <int> s;
        vector <bool> visited(V, false);
        for(int u = 0; u < V; u++){
            if(!visited[u]){
                dfs(adjT, adj, s, visited, u);
            }
        }
        for(int u = 0; u < V; u++) visited[u] = false;
        int scc = 0;
        while(!s.empty()){
            int u = s.top();
            s.pop();
            
            if(!visited[u]){
                scc++;
                explore(adjT, visited, u);
            }
        }
        return scc;
    }
};