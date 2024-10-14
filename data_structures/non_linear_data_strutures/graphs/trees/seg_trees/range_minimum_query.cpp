#include <iostream>
using namespace std;

template <typename T>
class RMQSegTree{
    T* seg;
    int n;
    T buildSegTree(int, int, int);
    T getMinHelper(int, int, int, int, int);

public:
    RMQSegTree(int n): n(n){
        int exact_size = 2 * (1 << (int)(ceil(log2(n)))) - 1;
        seg = new T[n];
        buildSegTree(0, n-1, 0);
    }

    int getMin(int l, int r){
        return getMinHelper(0, n-1, 0, l, r);
    }
};

template <typename T>
T RMQSegTree <T>::buildSegTree(int low, int high, int index){
    if(low == high){
        cin >> seg[index];
        return seg[index];
    }
    int mid = (low + high)/2;
    return seg[index] = min(buildSegTree(low, mid, 2 * index + 1), buildSegTree(mid + 1, high, 2 * index + 2));
}

template <typename T>
T RMQSegTree <T>::getMinHelper(int low, int high, int index, int l, int r){
    if((l <= low) && (high <= r)) return seg[index];
    if((high < l) || (r < low)) return INT_MAX;
    int mid = (low + high)/2;
    return min(getMinHelper(low, mid, 2 * index + 1, l, r), getMinHelper(mid + 1, high, 2 * index + 2, l, r));
}

int main(){
    int n;
    cin >> n;

    RMQSegTree <int> RMQ(n);

    int q;
    cin >> q;

    int l, r;
    while(q--){
        cin >> l >> r;
        cout << RMQ.getMin(l, r) << "\n";
    }
}