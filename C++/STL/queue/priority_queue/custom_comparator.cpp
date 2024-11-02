// priority_queue in C++ STL follows different syntax for 
// lambda comparator and comparator in struct (or) class
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int value;

    Node(int key, int value): key(key), value(value) {}
};

int main(){
    struct minHeapComparator{
        bool operator()(const Node& nd1, const Node& nd2){
            return nd1.value > nd2.value;
        }
    };

    auto maxHeapComparator = [](const Node& nd1, const Node& nd2){
        return nd1.value < nd2.value;
    };

    priority_queue <Node, vector <Node>, minHeapComparator> minPQ;
    priority_queue <Node, vector <Node>, decltype(maxHeapComparator)> maxPQ(maxHeapComparator);

    Node arr[] = {Node(2, 10), Node(3, 8), Node(11, 10)};
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        minPQ.push(arr[i]); maxPQ.push(arr[i]);
    }

    cout << "Min PQ elements:\n";
    while(!minPQ.empty()){
        cout << minPQ.top().key << " " << minPQ.top().value << "\n";
        minPQ.pop();
    }

    cout << "\nMax PQ elements:\n";
    while(!maxPQ.empty()){
        cout << maxPQ.top().key << " " << maxPQ.top().value << "\n";
        maxPQ.pop();
    }


}