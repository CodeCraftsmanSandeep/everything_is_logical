#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;

    int q;
    cin >> q;

    // let us take one-base indexing
    vector < pair <int, pair <int, int>> > queries;
    vector <int> freq_quries(1+q, 0);
    queries.push_back({ -1, {-1, -1}});
    for(int i = 0; i < q; i++){
        int type, l, r;
        cin >> type >> l >> r;

        queries.push_back({type, {l, r}});
        if(type == 1){

        }else{
            
        }
    }
}

int main(){
    solve();
}