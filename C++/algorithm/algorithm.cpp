#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    // count()
    int arr[] = {1, 2, 1, 4, 9, 10};
    int n = sizeof(arr)/sizeof(typeof(arr[0]));
    int freq = count(arr, arr + n, 1);
    cout << "Freq(1): " << freq << "\n";

}