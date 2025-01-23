class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    struct custom_comp{
	        bool operator()(int ele1, int ele2){
	            return ele1 >= ele2; 
	        }
	    };
	    
	    // O(k) time
	    priority_queue <int, vector <int>, custom_comp> pq(arr, arr + k);
	    
	    // O((n-k)*logk) time
	    for(int i = k; i < n; i++){
	        if(pq.top() < arr[i]){
	            pq.pop();
	            pq.push(arr[i]);
	        }
	    }
	    
	    // O(klogk) time
	    vector <int> kLargestElements(k);
	    for(int i = k-1; i >= 0; i--){
	        kLargestElements[i] = pq.top();
	        pq.pop();
	    }
	    return kLargestElements;
	}

};