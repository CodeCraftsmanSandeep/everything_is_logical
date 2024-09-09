// solution using stack (inspired from GFG article)
class Solution{
public:
    int maxIndexDiff(int arr[], int n){
        stack <int> index;
        index.push(0);
        for(int i = 1; i < n; i++) if(arr[index.top()] > arr[i]) index.push(i);
        
        int i = n-1;
        int max_diff = 0;
        while(i >= 0 && !index.empty()){
            if(arr[index.top()] <= arr[i]){
                max_diff = max(max_diff, i - index.top());
                index.pop();
            }else i--;
        }
        return max_diff;
    }
};