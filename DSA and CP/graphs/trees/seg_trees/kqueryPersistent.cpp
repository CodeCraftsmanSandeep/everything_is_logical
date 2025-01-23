// using persistent segmenet trees
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int count;
    Node* left;
    Node* right;

    Node(): count(0), left(nullptr), right(nullptr) {}
};

Node* buildTree(int low, int high){
    Node* curr = new Node();
    if(low < high){
        int mid = (low + high)/2;
        curr->left = buildTree(low, mid);
        curr->right = buildTree(mid + 1, high);
    }
    return curr;
}

Node* update(Node* prev, int low, int high, int index){
    Node* curr = new Node();
    if(low == high){
        curr->count = 1;
        return curr;
    }
    int mid = (low + high)/2;
    if(index <= mid){
        curr->left = update(prev->left, low, mid, index);
        curr->right = prev->right;
    }else{
        curr->left = prev->left;
        curr->right = update(prev->right, mid + 1, high, index);
    }
    curr->count = curr->left->count + curr->right->count;
    return curr;
}

int get_version(pair <int,int> arr[], int n, int k){
    int low = 1;
    int high = n;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid].first > k) low = mid + 1;
        else high = mid-1;
    }
    return high;
}

int get_count(Node* root, int low, int high, int l, int r){
    if((r < low) || (l > high)) return 0;
    if((l <= low) && (high <= r)) return root->count;

    int mid = (low + high)/2;
    return get_count(root->left, low, mid, l, r) + get_count(root->right, mid + 1, high, l, r);
}

int main(){
    int n;
    cin >> n;

    pair <int, int> arr[1+n];
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr + 1, arr + n + 1, [](const pair <int, int>& a1, const pair <int, int>& a2){
        return a1.first >= a2.first;
    });

    Node* versions[1+n];
    versions[0] = buildTree(1, n);
    for(int i = 1; i <= n; i++) versions[i] = update(versions[i-1], 1, n, arr[i].second);

    int q;
    cin >> q;

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;

        int v = get_version(arr, n, k);
        cout << get_count(versions[v], 1, n, l, r) << "\n";
    }
}