class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector <int> index(n);
        iota(index.begin(), index.end(), 0);
        
        auto custom_comp = [&val, &wt](const int i1, const int i2){
            double f1 = val[i1] * 1.0 / wt[i1];
            double f2 = val[i2] * 1.0 / wt[i2];
            
            return f1 >= f2;
        };
        sort(index.begin(), index.end(), custom_comp);
        
        int start = 0;
        double total_val = 0;
        while(capacity > 0 && start < n){
            int i = index[start++];
            
            if(wt[i] <= capacity){
                capacity -= wt[i];
                total_val += val[i];
            }else{
                total_val += val[i] * 1.0 / wt[i] * capacity;
                capacity = 0;
            }
        }
        return total_val;
    }
};