// using binary search
bool isPossible(vector <int>& arr, int k, double dis){
	int n = arr.size();
	int prev = arr[0];

	int curr = 0;
	for(int i = 1; i < n; i++){
		int need = (int)((arr[i] - arr[i-1])/(dis));
		curr += need;
	}

	return (curr <= k);
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	
	double low = 0;
	double high = -1;
	for(int i = 1; i < n; i++) high = max(high, (double)(arr[i] - arr[i-1]));
	while((high - low) >= 1e-6){
		double mid = (low + high) / 2;

		if(isPossible(arr, k, mid)) high = mid;
		else low = mid;
	}
	return high;
}