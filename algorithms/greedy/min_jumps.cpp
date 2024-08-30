class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = 0;
        int jumps = 0;
        while(high < n-1){
            int max_reachable = low;
            for(int i = low; i <= high; i++){
                max_reachable = max(max_reachable, arr[i] + i);
            }
            if(max_reachable <= high) return -1;
            low = high + 1;
            high = max_reachable;
            jumps++;
        }
        return jumps;
    }
};