// this code is made simle by using dummies 😮‍💨😮‍💨😮‍💨
class cacheNode;

class LRUCache{
    int capacity;
    vector <cacheNode*> arr;
    cacheNode* head;
    cacheNode* tail;
    int curr_ele;
public:
    LRUCache(int );
    int get(int );
    void put(int, int);
    void latestAccess(cacheNode* );
};

class cacheNode{
    int data;
    int key;
    cacheNode* prev;
    cacheNode* next;
public:
    cacheNode(): prev(nullptr), next(nullptr) {}
    cacheNode(int key, int data): key(key), data(data), prev(nullptr), next(nullptr) {}

    friend LRUCache::LRUCache(int);
    friend int LRUCache::get(int);
    friend void LRUCache::put(int, int);
    friend void LRUCache::latestAccess(cacheNode* );
};

LRUCache::LRUCache(int capacity): capacity(capacity), head(nullptr), tail(nullptr), curr_ele(0){
    arr.resize((int)1e5 + 1, nullptr);
    head = new cacheNode(-1, -1);
    tail = new cacheNode(-1, -1);
    head->next = tail;
    tail->prev = head;
}

void LRUCache::latestAccess(cacheNode* node){
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

int LRUCache::get(int key){
    if(arr[key] == nullptr) return -1;
    arr[key]->next->prev = arr[key]->prev;
    arr[key]->prev->next = arr[key]->next;
    latestAccess(arr[key]);
    return arr[key]->data;
}

void LRUCache::put(int key, int value){
    if(arr[key] == nullptr){
        if(curr_ele == this->capacity){
            arr[tail->prev->key] = nullptr;
            cacheNode* prev_node = tail->prev;
            tail->prev = tail->prev->prev;
            tail->prev->next = tail;

            // reusing the same node instead of deleting
            arr[key] = prev_node; 
            prev_node->key = key;
            prev_node->data = value;
        } else{
            arr[key] = new cacheNode(key, value);
            curr_ele++;
        }
    }else{
        arr[key]->next->prev = arr[key]->prev;
        arr[key]->prev->next = arr[key]->next;
        arr[key]->data = value;
    }

    latestAccess(arr[key]);
}