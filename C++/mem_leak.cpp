#include <iostream>
using namespace std;

int main(){
    // no bound checking performed by c++
    // operations which access data at out-of-bounds are called undefined in C++
    // I think compiler should throw some run-time error :-(
    int arr1[5];
    arr1[5] = 20;   
    cout << arr1[5] << "\n";

    int* arr2 = new int(5);
    cout << arr2[6] << "\n";

    int* arr3 = (int*)malloc(5*sizeof(int));
    arr3[100] = -1;
    cout << arr3[100] << "\n";
}