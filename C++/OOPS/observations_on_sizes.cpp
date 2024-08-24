#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string val;
    int index;

    Node(string val, int index): val(val), index(index){

    }
};

int main(){
    Node* arr[] = {new Node("sandeep", 100), new Node("long long long long long long long long long long long long long long long long long long long long string", 11), new Node("IIT PKD", 1000)};
    cout << sizeof(arr) << "\n";
    int n = sizeof(arr)/sizeof(arr[0]);
    // the size of pointer Node* is 8 bytes which is constant

    for(int i = 0; i < n; i++) cout << sizeof(arr[i]) << " "; // sizeof pointer
    cout << "\n";

    for(int i = 0; i < n; i++) cout << sizeof(*arr[i]) << " "; // size of Node object
    cout << "\n";

/*
Even though the std::string in Node can be long, sizeof only gives the size of the object’s direct memory layout, not the dynamically allocated memory.

The std::string class usually has a small fixed-size internal buffer to hold short strings directly within the object (often referred to as the small-string optimization). For longer strings, std::string allocates memory on the heap. sizeof(Node) does not include the size of this dynamically allocated memory; it only includes the size of the std::string object itself and the int in the Node.

So, sizeof(Node) returns a constant size which does not change based on the length of the string stored inside it. This size typically includes:

A small buffer for the std::string (which is usually a fixed size, regardless of the actual string length).
The int field.
In your case, the size of Node is 40 bytes for each object, and it remains the same regardless of the length of the string, because the sizeof operator does not account for dynamically allocated memory.
*/
}