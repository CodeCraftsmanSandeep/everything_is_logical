// using segment tree
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class segmentTree{
    vector <T> seg;
    int n;
    function <T(const T, const T)> comparator;

    T getRepHelper(const int, const int, const int, const int, const int);
    void updateHelper(const int, const T, const int, const int, const int);
public:
    segmentTree(int, function <T(const T, const T)>);
    T getRep(const int, const int);
    void update(const int , const T );
};

template <typename T>
segmentTree<T>::segmentTree(int n, function <T(const T, const T)> comparator): n(n), comparator(comparator){
    seg.resize(4 * n, 0);
    return;
}

template <typename T>
void segmentTree<T>::updateHelper(const int index, const T val, const int seg_index, const int low, const int high){
    if(low == high){
        seg[seg_index] = val;
        return;
    }
    int mid = (low + high)/2;
    if(index <= mid) updateHelper(index, val, 2 * seg_index + 1, low, mid);
    else updateHelper(index, val, 2 * seg_index + 2, mid + 1, high);

    seg[seg_index] = comparator(seg[2 * seg_index + 1], seg[2 * seg_index + 2]);
    return;
}

template <typename T>
void segmentTree<T>::update(const int index, const T val){
    updateHelper(index, val, 0, 0, n-1);
    return;
}

template <typename T>
T segmentTree<T>::getRepHelper(const int low_index, const int high_index, const int seg_index, const int seg_low_index, const int seg_high_index){
    if(low_index <= seg_low_index && seg_high_index <= high_index) return seg[seg_index];
    if(seg_low_index > high_index || seg_high_index < low_index) return 0;

    int mid = (seg_low_index + seg_high_index) / 2;
    return comparator(
        getRepHelper(low_index, high_index, 2 * seg_index + 1, seg_low_index, mid),
        getRepHelper(low_index, high_index, 2 * seg_index + 2, mid + 1, seg_high_index)
    );
}

template <typename T>
T segmentTree<T>::getRep(const int low_index, const int high_index){
    return getRepHelper(low_index, high_index, 0, 0, n-1);
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <pair <int, int>> vec(n);
        for(int i = 0; i < n; i++){
            vec[i].first = nums[i];
            vec[i].second = i;
        }

        sort(vec.begin(), vec.end());
        function <int(const int, const int)> maxFunc = [](const int a, const int b){
            if(a <= b) return b;
            return a;
        };

        segmentTree <int>* maxSegTreeObj = new segmentTree <int> (n, maxFunc);
        int i = 0;
        while(i < n){
            vector <int> maxSeqLen;
            for(int j = i; j < n && vec[i].first == vec[j].first; j++) maxSeqLen.push_back(1 + maxSegTreeObj->getRep(0, vec[j].second-1));
            for(auto len: maxSeqLen) maxSegTreeObj->update(vec[i++].second, len);
        }

        return maxSegTreeObj->getRep(0, n-1);
    }
};