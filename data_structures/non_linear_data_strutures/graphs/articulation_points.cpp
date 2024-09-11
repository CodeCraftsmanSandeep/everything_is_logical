// I discovered this algorithm
// This code has same idea as of GFG article https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/

#include <iostream>
#include <vector>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dfs(int u, int& curr_time, vector <int>& disc, vector <int>& parent, vector <int> adj[], vector <int>& articulation_points){
        disc[u] = curr_time;
        bool is_articulation = false;
        int min_time = curr_time++;
        int children = 0;
        for(auto v: adj[u]){
            if(disc[v] == -1){
                children++;
                parent[v] = u;
                int child_min_time = dfs(v, curr_time, disc, parent, adj, articulation_points);
                if(child_min_time >= disc[u]) is_articulation = true; // no back edge
                min_time = min(child_min_time, min_time);
            }else if(v != parent[u]) min_time = min(min_time, disc[v]);
        }
        if(parent[u] == -1){
            // root
            if(children >= 2) articulation_points.push_back(u);
        }else if(is_articulation) articulation_points.push_back(u);
        return min_time;
    }
    
    vector<int> articulationPoints(int n, vector<int>adj[]){
        vector <int> articulation_points;
        vector <int> disc(n, -1);     // disc[u] = time at which vertex u is discovered in DFS
        vector <int> parent(n, -1);  // parent[u] = vertex which is parent of u in DFS tree
        int curr_time = 0;
        for(int u = 0; u < n; u++){
            if(disc[u] == -1) dfs(u, curr_time, disc, parent, adj, articulation_points);
        }
        if (articulation_points.size() == 0) return std::vector<int>(1, -1);
        sort(articulation_points.begin(), articulation_points.end());
        return articulation_points;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends