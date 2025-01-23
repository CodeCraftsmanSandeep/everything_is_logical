int recurse(int W, vector <int>& wt, vector <int>& val, int i){
    if(i < 0) return 0;
    if(wt[i] <= W) return max(val[i] + recurse(W-wt[i], wt, val, i-1), recurse(W, wt, val, i-1));
    return recurse(W, wt, val, i-1);
}

int knapSack(int W, vector <int>& wt, vector <int>& val){
    return recurse(W, wt, val, wt.size() - 1);
}