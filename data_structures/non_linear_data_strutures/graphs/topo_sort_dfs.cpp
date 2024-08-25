// This code is about finding topological sort of DAG
#define ll long long int
#define f(i, a, b) for(ll i = a; i <= b; i++)
#define vb vector <bool>
#define pb push_back

class Solution
{
	public:
	void dfs(stack <int>& s, vb& visited, ll u, vector <int> adj[]){
	    visited[u] = true;
	    for(auto v: adj[u]){
	        if(!visited[v]) dfs(s, visited, v, adj);
	    }
	    s.push(u);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) {
	   vb visited(n, false);
	   stack <int> s;
	   f(u, 0, n-1){
	       if(!visited[u]){
	           dfs(s, visited, u, adj);
	       }
	   }
	   vector <int> ans;
	   while(!s.empty()){
	       ans.pb(s.top());
	       s.pop();
	   }
	   
	   return ans;
	}
};

// practise link: https://www.geeksforgeeks.org/problems/topological-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article