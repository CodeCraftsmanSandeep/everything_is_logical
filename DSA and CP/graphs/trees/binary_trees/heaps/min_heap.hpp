#include <iostream>
using namespace std;


template <typename T> class min_heap{
private:
    T* arr;
    int actual_size = 0;
    int reserved_size = 0;
    int max_size = 1e5;
    void reallocate();
    void min_heapify(int);
    void shiftUp(int);

public:
    int size();
    void insert(T);
    void remove();
    T get();
    bool isEmpty();

    min_heap(){
    }

    min_heap(T*& arr, int size): arr(arr), actual_size(size), reserved_size(size){
    }
};

template <typename T> void min_heap<T>:: reallocate(){
    int new_size = min(2*reserved_size + 1, max_size);
    if(new_size <= reserved_size){
        throw "Out of memory size";
    }
    T* new_arr = new T[new_size];
    for(int i = 0; i < actual_size; i++) new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr;
    return;
}

template <typename T> bool min_heap<T>::isEmpty(){
    return actual_size == 0;
}

template <typename T> int min_heap<T>::size(){
    return actual_size;
}

template <typename T> void min_heap<T>::shiftUp(int i){
    int parent = (i-1)/2;
    while(i > 0 && arr[parent] > arr[i]){
        swap(arr[parent], arr[i]);
        i = parent;
        parent = (i-1)/2;
    }
}

template <typename T> void min_heap<T>::insert(T data){
    if(actual_size == reserved_size){
        reallocate();
    }
    arr[actual_size++] = data;
    shiftUp(actual_size - 1);
}

template <typename T> T min_heap<T>::get(){
    if(actual_size == 0){
        throw runtime_error("PQ is empty, cannot get high priority element.\n");
    }
    return arr[0];
}

template <typename T> void min_heap<T>::min_heapify(int i){
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;
    int high_priority_index = i;
    if(left_child < actual_size && arr[left_child] < arr[high_priority_index]) high_priority_index = left_child;
    if(right_child < actual_size && arr[right_child] < arr[high_priority_index]) high_priority_index = right_child;
    if(high_priority_index != i){
        swap(arr[high_priority_index], arr[i]);
        min_heapify(high_priority_index);
    }
}

template <typename T> void min_heap<T>::remove(){
    if(actual_size == 0){
        throw runtime_error("PQ is empty, cannot delete high priority element.\n");
    }
    if(actual_size == 1){
        actual_size--;
        return;
    }
    swap(arr[0], arr[actual_size-1]);
    actual_size--;
    min_heapify(0);
}

