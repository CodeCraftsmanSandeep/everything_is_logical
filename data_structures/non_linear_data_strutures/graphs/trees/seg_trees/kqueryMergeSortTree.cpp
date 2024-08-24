#include <bits/stdc++.h>
using namespace std;

vector <int> seg_tree[4*30000];

void buildTree(int root, int low, int high){
    if(low == high){
        int num;
        cin >>num;
        seg_tree[root].push_back(num);
        return;
    }
    int mid = (low + high)/2;
    buildTree(2*root+1, low, mid);
    buildTree(2*root+2, mid+1, high);
    seg_tree[root].resize(seg_tree[2*root+1].size() + seg_tree[2*root+2].size());
    merge(seg_tree[2*root + 1].begin(), seg_tree[2*root + 1].end(), 
        seg_tree[2*root + 2].begin(), seg_tree[2*root + 2].end(), 
        seg_tree[root].begin());
}

int get_sum(int root, int low, int high, int l, int r, int k){
    if(r < low || l > high) return 0; // no overlap
    if((l <= low) && (high <= r)){
        return upper_bound(seg_tree[root].begin(), seg_tree[root].end(), INT_MAX) - upper_bound(seg_tree[root].begin(), seg_tree[root].end(), k);
    }
    int mid = (high + low)/2;
    int left = get_sum(2*root + 1, low, mid, l, r, k);
    int right = get_sum(2*root + 2, mid + 1, high, l, r, k);
    return left + right;
}

int main(){
    int n;
    cin >> n;
    
    buildTree(0, 0, n-1);

    int q;
    cin >> q;

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;

        l--;
        r--;
        cout << get_sum(0, 0, n-1, l, r, k) << "\n";
    }
}