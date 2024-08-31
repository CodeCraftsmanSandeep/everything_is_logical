// double ended queue
// https://www.geeksforgeeks.org/deque-cpp-stl/
#include <vector>
#include <iostream>
#include <deque>
using namespace std;


struct Node{
    int x;
    int y;
    Node(int x, int y): x(x), y(y) {}
};

int main(){
    // initilizing deque
    deque <int> dq1 = {1, 2, 3};

    // traversing deque from reverse
    for(auto it = dq1.rbegin(); it != dq1.rend(); it++) cout << *it << " ";
    cout << "\n";

    cout << "------------------\n\n";

    // max size of deque
    cout << "Max size: " << dq1.max_size() << "\n";
    
    // size of deque
    cout << "Size: " << dq1.size() << "\n";

    // checking empty
    cout << "Is empty: " << dq1.empty() << "\n";

    // resizing deque
    dq1.resize(10);
    cout << dq1.size() << "\n";

    // range based for loop for deque
    for(auto ele: dq1) cout << ele << " ";
    cout << "\n";

    cout << "------------------\n\n";
    
    vector <int> arr = {10, -1, 2, 1};
    // another way of initializing deque
    deque <int> dq2(arr.begin(), arr.end());

    // push_front() and push_back()
    dq2.push_front(99);
    dq2.push_back(100);

    // traversing deque using iterators
    for(auto it = dq2.cbegin(); it != dq2.cend(); it++) cout << *it << " ";
    cout << "\n";

    // pop_front() and pop_back()
    dq2.pop_front(); dq2.pop_front();
    dq2.pop_back(); dq2.pop_back();

    // elements in deque can be accessed using [], O(1) time
    for(int i = 0; i < dq2.size(); i++) cout << dq2[i] << " ";
    cout << "\n";

    cout << "------------------\n\n";
    // emplace_back()
    // emplace_front()
    deque <Node> dq3;
    Node obj(10, 10);
    dq3.push_back(obj);
    dq3[0].x = 100;
    cout << obj.x << "\n"; // first element is still 10
    dq3.emplace_back(-9, -10);
    dq3.emplace_front(-10, 10);
    for(int i = 0; i < dq3.size(); i++) cout << "(" << dq3[i].x << ", " << dq3[i].y << ")\n";

    cout << "------------------\n\n";
    // clear in deque
    dq3.clear();
    cout << dq3.size() << "\n";


    // we can insert multiple ways in deque
    // insert is ambgious
}