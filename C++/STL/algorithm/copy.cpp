#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data): data(data), next(nullptr) {}
    Node(): data(0) {}
};

void experiment1(){
    Node* arr[] = {new Node(10),new Node(100), new Node(20), new Node(20)};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // copying n-2 elements
    // shallow copy
    Node* copy_arr[n-2];
    copy(arr, arr + n - 2, copy_arr);
    for(int i = 0; i < n-2; i++){
        cout << copy_arr[i]->data << " ";
    }
    cout << "\n";

    // proving that it is shallow copy
    copy_arr[0]->data = -10;
    cout << arr[0]->data << "\n";  // output: -10
}

int main(){
    experiment1();
}