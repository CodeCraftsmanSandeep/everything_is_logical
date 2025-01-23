#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace my{
    template <typename T, typename FUNC>
    class priority_queue{
        FUNC comp;
        int size = 0;
        T* arr;
        int capacity = 0;

        void pushHeap(int );
        void downHeapify(int );
    public:
        priority_queue(FUNC comp): comp(comp){}
        void push(T );
        void pop();
        bool empty();
        T top();
    };

    template <typename T, typename FUNC> 
    void priority_queue<T, FUNC>::push(T node){
        if(size == 0){
            arr = new T[1];
            capacity = size = 1;
            arr[0] = node;
            return;
        }
        if(capacity == size){
            T* new_arr = new T[2*capacity];
            for(int i = 0; i < size; i++) new_arr[i] = arr[i];
            delete[] arr;
            arr = new_arr;
            capacity *= 2;
        }
        arr[size++] = node;
        pushHeap(size - 1);
    }

    template <typename T, typename FUNC>
    void priority_queue <T, FUNC>::pushHeap(int i){
        if(i == 0) return;
        int parent = i/2;
        while(comp(arr[parent], arr[i])){
            swap(arr[parent], arr[i]);
            i = parent;
            parent = i/2;
        }
        return;
    }

    template <typename T, typename FUNC>
    bool priority_queue <T, FUNC>::empty(){
        return size == 0;
    }

    template <typename T, typename FUNC>
    T priority_queue <T, FUNC>::top(){
        if(size == 0) return NULL;
        return arr[0];
    }

    template <typename T, typename FUNC>
    void priority_queue <T, FUNC>::pop(){
        if(size == 0) return;
        swap(arr[0], arr[--size]);
        downHeapify(0);
    }

    template <typename T, typename FUNC>
    void priority_queue<T, FUNC>::downHeapify(int i){
        int leftChild, rightChild, swapIndex;
        do{
            leftChild = 2 * i;
            rightChild = 2 * i + 1;
            swapIndex = i;

            if(leftChild < size && comp(arr[swapIndex], arr[leftChild])) swapIndex = leftChild;
            if(rightChild < size && comp(arr[swapIndex], arr[rightChild])) swapIndex = rightChild;
            if(swapIndex != i){
                swap(arr[swapIndex], arr[i]);
                i = swapIndex;
            }else break;
        }while(true);
    }
}

pair <vector <int>, vector <int>> dijkstra(int n, vector <vector <pair <int, int>>>& adj, int s){
    auto comp = [](const pair <int, int>& p1, const pair <int, int>& p2){
        return p1.second > p2.second;
    };
    
    vector <int> dist(n, INT_MAX);
    dist[s] = 0;

    vector <int> pred(n, -1);
    
    // min heap
    priority_queue <pair <int, int>, vector <pair <int, int>>, decltype(comp) > minPQ(comp);
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
    auto comp = [](const pair <int, int>& p1, const pair <int, int>& p2){
        return p1.second > p2.second;
    };
    
    my::priority_queue <pair <int, int>, 



    return 0;
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