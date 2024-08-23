#include <vector>
#include <iostream>
using namespace std;

class Node{
public:
    int data = 10;
    Node(int data): data(data){

    }
};

int main(){
    // deep copy in vectors
    vector <Node> arr = {Node(1), Node(100)};
    vector <Node> temp = arr;
    temp[0].data = -10;
    cout << arr[0].data << "\n";
}