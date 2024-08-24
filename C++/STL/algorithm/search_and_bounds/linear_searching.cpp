#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[] = {2, 1, 2, 1, 1, 1, 0, -100, 100, -200};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "n = " << n << "\n";

    int i = find(arr, arr + n, 20) - arr;
    cout << i << "\n";

    i = find(arr, arr+n, 100) - arr;
    cout << i << "\n";
}

// find()
// O(n) time
// O(1) space