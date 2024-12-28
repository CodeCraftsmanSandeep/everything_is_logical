#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
public:
    int data1;
    int data2;

    Node(){

    }

    Node(int x, int y): data1(x), data2(y){

    }
};

struct comp_ptr{
    bool operator()  (const Node* nd1, const Node* nd2) {
        return (nd1->data1 < nd2->data1) || ((nd1->data1 == nd2->data1) && (nd1->data2 <= nd2->data2));
    }
};


struct comp_node{
    bool operator()  (const Node nd1, const Node nd2) {
        return (nd1.data1 < nd2.data1) || ((nd1.data1 == nd2.data1) && (nd1.data2 <= nd2.data2));
    }
};

struct min_comp{
    bool operator() (const Node* nd1, const Node* nd2){
        return (nd1->data1 > nd2->data1) || ((nd1->data1 == nd2->data1) && (nd1->data2 > nd2->data2));
    }
};

int main(){
    // descending PQ (max heap)
    priority_queue <int> pq;
    
    // push
    pq.push(11);
    pq.push(100);
    pq.push(12);

    // size
    cout << "Size: " << pq.size() << "\n";

    // empty, top, pop
    cout << "Elements: ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";

    // swap , O(1) time
    priority_queue <int> temp;
    temp.push(20);
    temp.push(100);
    temp.push(-10);
    cout << "Before swapping: " << temp.size() << ", " << pq.size() << "\n";
    temp.swap(pq);
    cout << "After swapping: " << temp.size() << ", " << pq.size() << "\n";

    cout << "--------------\n";
    // custom comparator
    priority_queue <Node*, vector <Node*>, comp_ptr> custom_pq;
    Node* new_node = new Node(10, 20);
    custom_pq.push(new_node);
    new_node->data2 = 21;
    custom_pq.push(new_node);
    new_node->data1 = 11;

    // see that the elements in PQ are {11, 21}
    // becuase only Node* is copied into PQ and not values in new_node
    while(!custom_pq.empty()){
        cout << custom_pq.top()->data1 << ", " << custom_pq.top()->data2 << "\n";
        custom_pq.pop();
    }

    cout << "--------------\n";
    priority_queue <Node, vector <Node>, comp_node> another_custom_pq;
    Node temp_node(10, 20);
    another_custom_pq.push(temp_node);
    temp_node.data1 = 100;
    another_custom_pq.push(temp_node);
    temp_node.data2 = -1000;

    // the data in Node are copied
    while(!another_custom_pq.empty()){
        cout << another_custom_pq.top().data1 << ", " << another_custom_pq.top().data2 << "\n";
        another_custom_pq.pop();
    }
    cout << "--------------\n";

    // ascending PQ (min heap)
    priority_queue <Node*, vector <Node*>, min_comp> min_pq;
    min_pq.push(new Node(99, 200000));
    min_pq.push(new Node(99, 20));
    min_pq.push(new Node(-1, -1));

    int size = min_pq.size();
    while(size--){
        cout << min_pq.top()->data1 <<  ", " << min_pq.top()->data2 << "\n";
        min_pq.pop();
    }
    cout << "--------------\n";

    // using emplace
    another_custom_pq.emplace(100, 100);
    // but the below one will not work
    // min_pq.emplace(100, 200);

    cout << "--------------\n";
    // making array a PQ
    vector <int> arr = {1, -100, 20, -1000, 11};
    priority_queue <int> exp_pq(arr.begin(), arr.end());

    cout << "arr ele:\n";
    for(auto ele: arr) cout << ele << " ";
    cout << "\n";

    cout << "MAX PQ ele:\n";
    while(!exp_pq.empty()){
        cout << exp_pq.top() << " ";
        exp_pq.pop();
    }
    cout << "\n";
    cout << "--------------\n";
}

// std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;