// this file is just for scratch
// this is not any resourse

#include <vector>
#include <iostream>
using namespace std;

class LRUCache {
    int capacity;
    vector <int> arr(10, -1);

public:
    LRUCache(int capacity): capacity(capacity){
    
    }
    
    int get(int key) {
        return 10;
    }
    
    void put(int key, int value) {

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    vector <int> arr(5, 10);
    arr.resize(10, -1);
    cout << arr[0] << arr[5] << "\n";
    
}