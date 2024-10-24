class Solution {
public:
    // O(nlogn) using binary search
    int leastIndex(vector <int>& LIS, int low, int high, int ele){
        while(low < high){
            int mid = (low + high)/2;
            if(LIS[mid] < ele) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector <int> LIS;
        LIS.push_back(arr[0]);
        for(int i = 1; i < n; i++){
            if(LIS.back() < arr[i]) LIS.push_back(arr[i]);
            else{
                // least j such that LIS[j] > arr[i]
                LIS[leastIndex(LIS, 0, LIS.size() - 1, arr[i])] = arr[i];
            }
        }
        return  LIS.size();
    }
};