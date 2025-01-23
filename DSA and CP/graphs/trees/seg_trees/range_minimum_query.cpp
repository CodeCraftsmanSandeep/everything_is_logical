#include <bits/stdc++.h>
using namespace std;

template <typename T>
class RMQSegTree{
    T* seg;
    int n;
    void buildSegTree(int, int, int);
    T getMinHelper(int, int, int, int, int);
	T updateHelper(int, int, int, int, int);

public:
    RMQSegTree(int n): n(n){
        int exact_size = 2 * (1 << (int)(ceil(log2(n)))) - 1 + 1;
		exact_size = 4 * n;
        seg = new T[exact_size];
        buildSegTree(1, n, 1);
    }

    int getMin(int l, int r){
        return getMinHelper(1, n, 1, l, r);
    }

	void update(int i, int x){
		updateHelper(1, n, 1, i, x);
	}
};

template <typename T>
T RMQSegTree <T>::updateHelper(int low, int high, int segIndex, int i, int x){
	// no update needed
	if((high < i) || (low > i)) return seg[segIndex];
	
	// update needed
	if(low == high) return seg[segIndex] = x;
	
	int mid = (low + high)/2;
	return seg[segIndex] = min(updateHelper(low, mid, 2*segIndex, i, x), updateHelper(mid + 1, high, 2*segIndex + 1, i, x));
}

template <typename T>
void RMQSegTree <T>::buildSegTree(int low, int high, int segIndex){
    if(low == high){
		cin >> seg[segIndex];
		return;
	}
    int mid = (low + high)/2;
	buildSegTree(low, mid, 2 * segIndex);
	buildSegTree(mid + 1, high, 2 * segIndex + 1);
    seg[segIndex] = min(seg[2 * segIndex], seg[2 * segIndex + 1]);
}

template <typename T>
T RMQSegTree <T>::getMinHelper(int low, int high, int index, int l, int r){
    if((l <= low) && (high <= r)) return seg[index];
    if((high < l) || (r < low)) return INT_MAX;
    int mid = (low + high)/2;
    return min(getMinHelper(low, mid, 2 * index, l, r), getMinHelper(mid + 1, high, 2 * index + 1, l, r));
}

int main(){
    int n;
    cin >> n;

    int q;
    cin >> q;

    RMQSegTree <int> RMQ(n);

	char type;
    int l, r;
	int i, x;
    while(q--){
		cin >> type;
		if(type == 'q'){
        	cin >> l >> r;
        	cout << RMQ.getMin(l, r) << "\n";
		}else{
			cin >> i >> x;
			RMQ.update(i, x);
		}
    }
}