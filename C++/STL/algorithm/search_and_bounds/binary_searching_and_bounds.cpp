/*
- binary_search(iterator begin, iterator end, x)
    - returns true if x is found in [begin, end)
- lower_bound(iterator begin, iterator end, x)
    - if all elements in [begin, end) are < x:
        - returns end
    - else:
        - returns lb where lb is the first iterator in [begin, end) such that x <= element at lb
- upper_bound(iterator begin, iterator end, x)
    - if all elements in [begin, end) are <= x:
        - returns end
    - else:
        - returns ub where ub is the first iterator in [begin, end) such that x < element at ub
*/

#include <iostream>
#include <algorithm>
using namespace std;

void defaultComparator(){
    cout << "Default comprator:\n";
    pair <int,int> arr[] = {make_pair(2, 10), make_pair(3, 1), make_pair(100, -100), make_pair(100, -100), make_pair(101, 0)};;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Size of arr: " << n << "\n";

    bool isPresent = binary_search(arr, arr+n, make_pair(100, -100));
    cout << "isPresent = " << isPresent << "\n";

    int i = lower_bound(arr, arr +n, make_pair(100, -100))- arr;
    if(i < n) cout << "i = " << i << ", " << "(" << arr[i].first << "," << arr[i].second << ")\n";

    int j = upper_bound(arr, arr+n, make_pair(100, -100)) - arr;
    if(j < n) cout << "j = " << j << ", " << "(" << arr[j].first << "," << arr[j].second << ")\n";
}

void customComparator(){
    cout << "Custom comparator:\n";
    class Node{
    public:
        int val;
        double index;
        Node(int val, double index): val(val), index(index){
        }
    };

    // arr is in descneding order
    Node* arr[] = {new Node(100, 20), new Node(40, 100), new Node(40, 79), new Node(40, 79), new Node(32, 100), new Node(32, 100), new Node(32, 32), new Node(10, 1000)};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "size of pointer: " << sizeof(arr[0]) << "\n"; 
    cout << "size of node: " << sizeof(*arr[0]) << "\n";

    auto customComp = [](const Node* nd1, const Node* nd2){
        return (nd1->val > nd2->val) || ((nd1->val == nd2->val) && (nd1->index > nd2->index));
    };
    Node* search_key = new Node(40, 79);
    bool isPresent = binary_search(arr, arr+n, search_key, customComp);

    cout << "isPresent(" << search_key->val << "," << search_key->index << ") = " << isPresent << "\n";

    int i = lower_bound(arr, arr + n, search_key, customComp) - arr;
    cout << i << "\n";

    int j = upper_bound(arr, arr + n, search_key, customComp) - arr;
    cout << j << "\n";
}

int main(){
    // code using default comparator
    defaultComparator();
    cout << "----------------\n";

    // code using custom comparator
    customComparator();
}