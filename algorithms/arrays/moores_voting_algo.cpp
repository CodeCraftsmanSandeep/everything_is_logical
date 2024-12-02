class Solution {
  public:
  // moore's voting algorithm
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int candidate = 0;
        for(auto ele: arr){
            if(candidate == ele) count++;
            else if(count != 0) count--;
            else{
                count = 1;
                candidate = ele;
            }
        }
        int freq = 0;
        for(auto ele: arr){
            if(ele == candidate) freq++;
        }
        return (freq >= n/2 + 1) ? candidate : -1;
    }
};