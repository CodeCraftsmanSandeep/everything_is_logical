// using heap
// space: O(k)
// time: 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n, k;

    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    k = min(k+1, n);
    // time: O(k+1)
    priority_queue <int, vector <int>, greater <int>> pq(arr, arr + k);

    int j = k;
    int i = 0;
    // (n-k)*log(k+1)
    while(!pq.empty()){
        arr[i++] = pq.top();
        pq.pop();
        if(j < n) pq.push(arr[j++]);
    }

    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}
