// question link: https://www.geeksforgeeks.org/problems/maximum-prefix-sum-for-a-given-range0227/1
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class seg_tree{
    T* seg;
    int n;
    vector <T> arr;
    
    T getMaxHelper(const int, const int, const int, const int, const int);
    T buildSegTree(const int, const int, const int, const vector <T>&);
    
public:
    
    seg_tree(const int n, vector <T>& arr){
        // tight upper bound on segment tree size which is often approximated to 4n
        const int exact_size = 2 * (1 << (int)(ceil(log2(n)))) - 1; 
        seg = (T*)malloc(exact_size * sizeof(T));
        this->n = n;
        buildSegTree(0, n-1, 0, arr);
        this->arr = arr;
    }
    
    T getMax(const int, const int );
};

template <typename T> 
T seg_tree<T>::buildSegTree(const int low, const int high, const int index, const vector <T>& arr){
    if(low == high) return seg[index] = arr[low];
    const int mid = (low + high)/2;
    return seg[index] = max(buildSegTree(low, mid, 2*index + 1, arr), buildSegTree(mid + 1, high, 2*index + 2, arr));
}

template <typename T>
T seg_tree<T>::getMax(const int l, const int r){
    if(l == 0) return getMaxHelper(l, r, 0, n-1, 0);
    return getMaxHelper(l, r, 0, n-1, 0) - arr[l-1];
}

template <typename T>
T seg_tree<T>::getMaxHelper(const int l, const int r, const int low, const int high, const int index){
    if(r < low || l > high) return INT_MIN;
    if(l <= low && r >= high) return seg[index];
    const int mid = (low + high)/2;
    return max(getMaxHelper(l, r, low, mid, 2*index + 1), getMaxHelper(l, r, mid + 1, high, 2*index + 2));
}

class Solution {
  public:
    vector<int> maxPrefixes(vector<int>& arr, vector<int>& leftIndex, vector<int>& rightIndex) {
        const int n = arr.size();
        for(int i = 1; i < n; i++) arr[i] += arr[i-1];
        
        seg_tree <int> comp(n, arr);
        
        const int q = leftIndex.size();
        vector <int> ans;
        for(int i = 0; i < q; i++){
            int l = leftIndex[i];
            int r = rightIndex[i];
            
            ans.push_back(comp.getMax(l, r));
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int q;
    cin >> q;

    vector <int> leftIndex(q), rightIndex(q);
    for(int i = 0; i < q; i++) cin >> leftIndex[i];
    for(int i = 0; i < q; i++) cin >> rightIndex[i];

    Solution obj;
    vector <int> ans = obj.maxPrefixes(arr, leftIndex, rightIndex);
    for(auto ele: ans) cout << ele << " ";
    cout << "\n";

    return 0;
}
