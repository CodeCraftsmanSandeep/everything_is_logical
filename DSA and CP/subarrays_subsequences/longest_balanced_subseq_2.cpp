#include <vector>
#include <iostream>
using namespace std;

// Preprocessing time: O(nlogn)
// Time per query: O(log2(r - l))
// Auxillary space: O(n)
// This is not tested on many test cases, as I did not found a question to submit

typedef struct meta_data{
    int open;
    int closed;
    int matched;

    meta_data(): open(0), closed(0), matched(0) {}
    meta_data(int open, int closed, int matched): open(open), closed(closed), matched(matched) {}
} node;

void construct_seg_tree(int index, int low, int high, const string& str, vector <node>& seg){
    if(low == high){
        if(str[low] == ')') seg[index].closed = 1;
        else seg[index].open = 1;
        return;
    }
    int mid = (low + high)/2;
    construct_seg_tree(2*index + 1, low, mid, str, seg);
    construct_seg_tree(2*index + 2, mid + 1, high, str, seg);

    int matching = min(seg[2*index + 1].open, seg[2*index + 2].closed);
    seg[index].matched = seg[2*index + 1].matched + seg[2*index + 2].matched + 2*matching;
    seg[index].open = seg[2*index + 1].open - matching + seg[2*index + 2].open;
    seg[index].closed = seg[2*index + 1].closed + seg[2*index + 2].closed - matching;
}

node find_balanced(int index, int low, int high, int l, int r, const string& str, vector <node>& seg){
    if(high < l || r < low) return node(0, 0, 0);
    if(low >= l && high <= r) return seg[index];
    
    int mid = (low + high)/2;
    node left = find_balanced(2*index + 1, low, mid, l, r, str, seg);
    node right = find_balanced(2*index + 2, mid + 1, high, l, r, str, seg);
    
    int matching = min(left.open, right.closed);
    node curr_node;
    curr_node.matched = left.matched + right.matched + 2 * matching;
    curr_node.open = left.open - matching + right.open;
    curr_node.closed = left.closed + right.closed - matching;

    return curr_node;
}


void solve(int n, string str){
    vector <node> seg(4*n);

    construct_seg_tree(0, 0, n-1, str, seg);

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r; // assuming zero-based indexing
        
        node ans_node = find_balanced(0, 0, n-1, l, r, str, seg);
        cout << ans_node.matched << "\n";
    }
}

int main(){
    int n;
    cin >> n;

    string str;
    cin >> str;

    solve(n, str);
}

/*
input:
12
())(())(())(
3
0 11
1 9
5 8

output:
10
6
0

*/