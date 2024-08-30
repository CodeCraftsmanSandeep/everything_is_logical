// the idea is just queue method
// but just using present space
// O(nlogn) time
// O(1) space
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int low = 0;
    	int high = -1;
    	int ans=0;
    	for(int i=0;i<n;i++) {
    	    high++;
    	    while(dep[low] < arr[i]) low++;
    	    ans = max(ans, high - low + 1);
    	}
    	return ans;
    }
};