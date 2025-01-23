#define ll long long int
#define f(i, a, b) for(ll i = a; i <= b; i++)
#define vb vector <bool>
#define pb push_back
#define vl vector <ll>

// khans algorithm 
class Solution
{
	public:
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) {
	   
	   vl in_degree(n, 0);
	   f(u, 0, n-1){
	       for(auto v: adj[u]){
	           in_degree[v]++;
	       }
	   }
	   vector <int> q;
	   f(u, 0, n-1){
	       if(in_degree[u] == 0) q.pb(u);
	   }
	   ll i = 0;
	   while(i < q.size()){
	       ll u = q[i++];
	       for(auto v: adj[u]){
	           in_degree[v]--;
	           if(in_degree[v] == 0) q.pb(v);
	       }
	   }
	   if(i != n){
	       // there is a cycle;
	       cout << "NOT DAG\n";
	       return q;
	   }
	   
	   return q;
	}
};