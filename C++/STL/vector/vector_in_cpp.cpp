#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector <int> arr;
    arr.push_back(100);
    cout << arr.capacity() << "\n";
}