// approach from gfg
// O(n) time
// O(n) space
class Solution{
    public:
    long long trappingWater(int arr[], int n){
        vector <int> pref_max(n);
        vector <int> suff_max(n);
        
        pref_max[0] = arr[0];
        for(int i = 1; i < n; i++) pref_max[i] = max(pref_max[i-1], arr[i]);
        
        suff_max[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--) suff_max[i] = max(suff_max[i+1], arr[i]);
        
        long long int water = 0;
        for(int i = 0; i < n; i++){
            water += min(pref_max[i], suff_max[i]) - arr[i];
        }
        return water;
    }
};