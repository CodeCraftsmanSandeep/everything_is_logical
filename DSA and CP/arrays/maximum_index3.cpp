// only using rightMax
// We can also find the solution, also by using only leftMin
class Solution{
public:
    int maxIndexDiff(int arr[], int n){
        vector <int> rightMax(n);
        rightMax[n-1] = arr[n-1];
        for(int i = n-2; i>= 0; i--) rightMax[i] = max(rightMax[i+1], arr[i]);
        
        int i = 0;
        int j = 0;
        int max_diff = 0;
        while(i < n && j < n){
            if(rightMax[j] >= arr[i]) max_diff = max(max_diff, j++ - i);
            else i++;
        }
        return max_diff;
    }
};