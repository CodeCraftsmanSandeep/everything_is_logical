class Solution{
public:
	long long maxProduct(vector<int>& arr, int n) {
	    long long pref = 1;
	    long long ans = INT_MIN;
	    long long last_neg = 1;
	    for(int i = 0; i < n; i++){
	        if(arr[i] == 0){
	            pref = 1;
	            last_neg = 1;
	            ans = max(ans, (long long)0);
	        }else{
	            pref *= arr[i];
	            ans = max(ans, pref);
	            if(pref < 0){
	                if(last_neg < 0) ans = max(ans, pref/last_neg);
	                else last_neg = pref;
	            }
	        }
	    }
	    return ans;
	}
};