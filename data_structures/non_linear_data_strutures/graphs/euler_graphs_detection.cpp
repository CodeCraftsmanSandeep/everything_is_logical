class Solution {
public:
    int findOddDegreeVerticesCount(int n, vector <int> adj[]){
        int odd_degree_vertices = 0;
        for(int u = 0; u < n; u++){
            if(adj[u].size() & 1) odd_degree_vertices++;
        }
        return odd_degree_vertices;
    }
    int find_rep(int u, vector <int>& parent){
        if(parent[u] == u) return u;
        return parent[u] = find_rep(parent[u], parent);
    }
    
    void merge(int u, int v, vector <int>& parent, vector <int>& size){
        int p1 = find_rep(u, parent);
        int p2 = find_rep(v, parent);
        
        if(p1 != p2){
            parent[p1] = p2;
            size[p2] += size[p1];
        }
    }
    
    bool connectedWithoutDegreeZeroVertices(int n, vector <int> adj[]){
        vector <int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        vector <int> size(n, 1);
        
        for(int u = 0; u < n; u++){
            for(auto v: adj[u]){
                merge(u, v, parent, size);
            }
        }
        
        int componentsSizeGreaterThanOne = 0;
        for(int u = 0; u < n; u++){
            if(size[u] > 1 && parent[u] == u) componentsSizeGreaterThanOne++;
        }
        return componentsSizeGreaterThanOne == 1;
    }
    
	int isEulerCircuit(int v, vector<int>adj[]){
	    int oddDegreeVertices = findOddDegreeVerticesCount(v, adj);
	    if(oddDegreeVertices > 2) return 0;
	    if(connectedWithoutDegreeZeroVertices(v, adj)){
	        if(oddDegreeVertices == 0) return 2;
	        return 1;
	    }
	    return 0;
	    
	}
};