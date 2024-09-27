// Implementing LRU cache without using any duplicates is little complicated 
// I spent 2 hours to fix the bugs in this!! :-(

class cacheNode;

class LRUCache{
    int capacity;
    vector <cacheNode*> arr;
    cacheNode* head;
    cacheNode* tail;
    int curr_ele;
public:
    LRUCache(int capacity): capacity(capacity), head(nullptr), tail(nullptr), curr_ele(0){
        arr.resize((int)1e5 + 1, nullptr);
    }
    int get(int );
    void put(int, int);
};

class cacheNode{
    int data;
    int key;
    cacheNode* prev;
    cacheNode* next;
public:
    cacheNode(): prev(nullptr), next(nullptr) {}

    friend int LRUCache::get(int);
    friend void LRUCache::put(int, int);
};

int LRUCache::get(int key){
    if(arr[key] == nullptr) return -1;
    if(arr[key]->prev != nullptr){
        if(arr[key]->next == nullptr){
            tail = arr[key]->prev;
            if(tail != nullptr) tail->next = nullptr;
        }else arr[key]->next->prev = arr[key]->prev;

        arr[key]->prev->next = arr[key]->next;
        arr[key]->next = head;
        arr[key]->prev = nullptr;
        head->prev = arr[key];
        head = arr[key];
    }
    return arr[key]->data;
}

void LRUCache::put(int key, int value){
    if(arr[key] == nullptr){
        if(curr_ele == this->capacity){
            arr[tail->key] = nullptr;
            cacheNode* prev_node = tail->prev;
            delete tail;
            tail = prev_node;
            if(tail != nullptr) tail->next = nullptr;
            else head = nullptr;
            curr_ele--;
        }
        arr[key] = new cacheNode();
        arr[key]->key = key;
        curr_ele++;
    }else{
        if(arr[key]->next != nullptr) arr[key]->next->prev = arr[key]->prev;
        else{
            tail = arr[key]->prev;
            if(tail != nullptr) tail->next = nullptr;
        }

        if(arr[key]->prev != nullptr) arr[key]->prev->next = arr[key]->next;
        else{
            head = arr[key]->next;
            if(head != nullptr) head->prev = nullptr;
        }
    }

    arr[key]->data = value;
    arr[key]->next = head;
    arr[key]->prev = nullptr;
    if(head != nullptr) head->prev = arr[key];
    else tail = arr[key];
    head = arr[key];
}