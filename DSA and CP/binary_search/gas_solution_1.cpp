// using priority queue
#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	priority_queue <pair <double, int> > pq;
	for(int i = 1; i < n; i++) pq.push({arr[i] - arr[i-1], i});
	vector <int> middle(n, 0);

	while(k--){
		auto top = pq.top();
		pq.pop();

		int i = top.second;
		middle[i]++;
		pq.push({(arr[i] - arr[i-1]) / (double)(middle[i] + 1), i});
	}
	return pq.top().first;
}