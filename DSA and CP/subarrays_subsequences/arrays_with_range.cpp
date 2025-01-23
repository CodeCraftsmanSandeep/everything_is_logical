// https://www.geeksforgeeks.org/array-range-queries-range-queries/
#include <iostream>
#include <vector>
using namespace std;

struct query{
    int type, l, r;
    void init(int type, int l, int r){
        this->type = type;
        this->l = l;
        this->r = r;
    }
};

// Auxillary space: O(m + n)
// Total time: O(n + m)
int main(){
    int n, m;
    cin >> n >> m;

    vector <query> queries(1+m);
    int type, l, r;
    for(int i = 1; i <= m; i++){
        cin >> type >> l >> r;
        queries[i].init(type, l, r);
    }

    vector <int> arr(1+n, 0);
    vector <int> query_freq(1+m, 0);
    int freq = 0;
    for(int q = m; q >= 1; q--){
        freq += query_freq[q];
        int impact = freq + 1;
        if(queries[q].type == 2){
            query_freq[queries[q].l - 1] -= impact;
            query_freq[queries[q].r] += impact;
        }else{
            arr[queries[q].l - 1] -= impact;
            arr[queries[q].r] += impact;
        }
    }
    for(int i = n-1; i >= 0; i--) arr[i] += arr[i+1];

    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << "\n";
}