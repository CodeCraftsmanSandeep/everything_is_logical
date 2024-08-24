#include <bits/stdc++.h>
using namespace std;

int* seg_tree;
struct Node{
    int k;
    int l, r;
    int index;

    Node(){}
    Node(int k, int l, int r, int index): k(k), l(l), r(r), index(index){}
};

// placing element at position index
void update(int root, int low, int high, int index){
    if(index < low || index > high) return;
    if(low == high){
        // leaf node
        seg_tree[root] = 1;
        return;
    }
    int mid = (low + high)/2;
    update(2*root + 1, low, mid, index);
    update(2*root + 2, mid + 1, high, index);
    seg_tree[root] = (seg_tree[2*root + 1] + seg_tree[2*root + 2]);
}

int get_count(int root, int low, int high, int l, int r){
    if((r < low) || (l > high)) return 0;
    if((l <= low) && (high <= r)) return seg_tree[root];
    int mid = (low + high)/2;
    return get_count(2*root + 1, low, mid, l, r) + get_count(2*root + 2, mid + 1, high, l, r);
}

int main(){
    int n;
    cin >> n;

    pair <int,int> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    seg_tree = (int*)calloc(4*n, sizeof(int));

    // nlogn
    sort(arr, arr + n);
    int q;
    cin >> q;

    vector <Node> query(q);

    for(int i = 0; i < q; i++){
        int l, r, k;
        cin >> l >> r >> k;
        query[i] = Node(k, l-1, r-1, i);
    }

    // qlogq
    sort(query.begin(), query.end(), [](Node nd1, Node nd2){
        return nd1.k >= nd2.k;
    }); // sorted in descneding order of q

    int ans[q];
    int j = n-1;
    // O(qlogn + nlogn) 
    for(int i = 0; i < q; i++){
        while(j >= 0 && arr[j].first > query[i].k){
            update(0, 0, n-1, arr[j--].second); // logn
        }
        ans[query[i].index] = get_count(0, 0, n-1, query[i].l, query[i].r); // logn
    }

    for(int i = 0; i < q; ++i) cout << ans[i] << "\n";
}