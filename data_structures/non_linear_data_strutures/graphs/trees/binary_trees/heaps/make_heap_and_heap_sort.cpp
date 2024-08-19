#include "min_heap.hpp"
#include <iostream>
using namespace std;

void min_heapify(int* arr, int i, int n){
    int prev;
    do{
        prev = i;
        int left_child = 2*i + 1;
        int right_child = 2*i + 2;
        int high_priority_index = i;
        if(left_child < n && arr[left_child] < arr[high_priority_index]) high_priority_index = left_child;
        if(right_child < n && arr[right_child] < arr[high_priority_index]) high_priority_index = right_child;
        if(high_priority_index != i){
            swap(arr[high_priority_index], arr[i]);
            i = high_priority_index;
        }
    }while(i != prev);
}

void make_heap(int* arr, int n){
    for(int i = (n-2)/2; i >= 0; i--) min_heapify(arr, i, n);
}

int main(){
    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    make_heap(arr, n);
    
    min_heap obj(arr, n);
    while(!obj.isEmpty()){
        cout << obj.get() << " ";
        obj.remove();
    }
    cout << "\n";

}