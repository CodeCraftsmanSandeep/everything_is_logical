class Solution {
  public:
    int canReach(int arr[], int n) {
        int max_reachable = 0;
        for(int i = 0; i < n; i++){
            if(i > max_reachable) return false;
            max_reachable = max(max_reachable, i + arr[i]);
        }
        return true;
    }
};