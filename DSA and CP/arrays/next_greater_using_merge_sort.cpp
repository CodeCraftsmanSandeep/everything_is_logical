// solving it using merge sort code
class Solution{
    void merge(vector <int>& arr, vector <int>& index, vector <int>& count, int low, int mid, int high){
        int n1 = mid - low + 1;
        int n2 = high - mid;
        
        int left_arr[n1], left_index[n1];
        for(int i = low; i <= mid; i++){
            left_arr[i - low] = arr[i];
            left_index[i - low] = index[i];
        }
        
        int right_arr[n2], right_index[n2];
        for(int i = mid + 1; i <= high; i++){
            right_arr[i - mid - 1] = arr[i];
            right_index[i - mid - 1] = index[i];
        }
        
        int left_ptr = 0;
        int right_ptr = 0;
        int k = low;
        
        while(left_ptr < n1 && right_ptr < n2){
            if(left_arr[left_ptr] < right_arr[right_ptr]){
                arr[k] = left_arr[left_ptr];
                index[k] = left_index[left_ptr];
                
                count[left_index[left_ptr]] += n2 - right_ptr;
                
                left_ptr++;
                k++;
            }else{
                arr[k] = right_arr[right_ptr];
                index[k] = right_index[right_ptr];
                
                right_ptr++;
                k++;
            }
        }
        
        while(left_ptr < n1){
            arr[k] = left_arr[left_ptr];
            index[k] = left_index[left_ptr];
            
            k++;
            left_ptr++;
        }
        
        while(right_ptr < n2){
            arr[k] = right_arr[right_ptr];
            index[k] = right_index[right_ptr];
            
            k++;
            right_ptr++;
        }
    }
    
    void merge_sort(vector <int>& arr, vector <int>& index, vector <int>& count, int low, int high){
        if(low < high){
            int mid = (low + high) / 2;
            merge_sort(arr, index, count, low, mid);
            merge_sort(arr, index, count, mid + 1, high);
            
            merge(arr, index, count, low, mid, high);
        }
    }
    
public:
    // using merge sort
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector <int> count(n, 0);
        vector <int> index(n);
        iota(index.begin(), index.end(), 0);
        
        merge_sort(arr, index, count, 0, n-1);
        
        vector <int> ans;
        for(auto index: indices) ans.push_back(count[index]);
        return ans;
    }
};

// we can also solve it using segment tree