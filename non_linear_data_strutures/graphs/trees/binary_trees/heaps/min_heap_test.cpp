#include "min_heap.hpp"

int main(){
    min_heap <double> my_heap;
    my_heap.insert(10);
    my_heap.insert(100);
    my_heap.insert(-10.923);

    while(!my_heap.isEmpty()){
        cout << my_heap.get() << "\n";
        my_heap.remove();
    }
}