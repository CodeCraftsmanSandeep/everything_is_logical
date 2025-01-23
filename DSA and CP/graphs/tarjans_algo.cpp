class Solution
{
	public:
	enum status {un_visited, visited, explored};
	// visited vertices are one in stack st
	void dfs(int u, vector <int>& scc_start_time, vector <status>& color, stack <int>& st, vector <int> adj[], int& seq, vector <vector <int>>& all_scc){
	        int vertex_start_time = seq;
	        scc_start_time[u] = seq++;
	        color[u] = visited;
	        st.push(u);
	        
	        for(auto v: adj[u]){
	            if(color[v] != explored){
	                if(color[v] == un_visited) dfs(v, scc_start_time, color, st, adj, seq, all_scc);
	                scc_start_time[u] = min(scc_start_time[u], scc_start_time[v]);
	            }
	        }
	        
	        // checking whether the time vertex u got visited and the time SCC(u) got visited for the first time are same (or) not
	        if(vertex_start_time == scc_start_time[u]){
	            // u is the vertex which is visited for the first time in SCC(u)
	            vector <int> scc;
	            int top_vertex;
	            do{
	                top_vertex = st.top();
	                st.pop();
	                color[top_vertex] = explored;
	                scc.push_back(top_vertex);
	                scc_start_time[top_vertex] = vertex_start_time;
	            }while(top_vertex != u);
	            sort(scc.begin(), scc.end());
	            all_scc.push_back(scc);
	        }
	}
	
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int n, vector<int> adj[]){
        vector <vector <int>> ans;
        vector <int> scc_start_time(n);
        vector <status> color(n, un_visited);
        stack <int> s;
        int seq = 0;
        for(int u = 0; u < n; u++){
            if(color[u] == un_visited) dfs(u, scc_start_time, color, s, adj, seq, ans);
        }
        // scc_start_time[u] = the first time the SCC containing vertex u is visited is computed
        sort(ans.begin(), ans.end());
        return ans;
    }
};