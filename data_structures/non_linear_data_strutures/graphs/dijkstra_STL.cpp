#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair <vector <int>, vector <int>> dijkstra(int n, vector <vector <pair <int, int>>>& adj, int s){
    struct comp{
        bool operator() (const pair <int, int>& p1, const pair <int, int>& p2){
            return p1.second > p2.second;
        }
    };
    
    vector <int> dist(n, INT_MAX);
    dist[s] = 0;

    vector <int> pred(n, -1);
    
    // min heap
    priority_queue <pair <int, int>, vector <pair <int, int>>, comp > minPQ;
    for(int u = 0; u < n; u++) minPQ.push({u, dist[u]});

    // Time complexity: O(|E| * log(|E|) )
    // because there will be atmost |E| insertions into PQ in the below while loop
    // Using decrease key, the time complexity can become: O(|E| * log(|V|))
    
    while(!minPQ.empty()){
        pair <int, int> minNode = minPQ.top();
        minPQ.pop();

        int u = minNode.first;
        int w = minNode.second;
        
        for(auto it: adj[u]){
            int v = it.first;
            int cost = it.second;

            if(w != INT_MAX && w + cost < dist[v]){
                dist[v] = w + cost;
                pred[v] = u;
                minPQ.push({v, dist[v]});
            }
        }
    }
    
    return {dist, pred};
}

int main(){
    int n, m;
    cin >> n >> m;

    // 0 based indexing graph
    vector <vector <pair <int, int>>> adj(n);
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source; cin >> source;
    
    pair <vector <int>, vector <int>> output = dijkstra(n, adj, source);
    vector <int> dist = output.first;
    vector <int> pred = output.second;

    for(int u = 0; u < n; u++){
        cout << "dis[" << u << "] = " << (dist[u] == INT_MAX ? "inf" : to_string(dist[u])) << " ";
        cout << "pred[" << u << "] = " << pred[u] << "\n";
    }
}