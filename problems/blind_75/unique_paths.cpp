class Solution {
public:
    int fact(int n, int m){
        if(m < n) swap(m, n);
        if(m <= 1) return 1;
        long long int num = 1;
        int den = 1;
        for(int i = m; i <= n + m - 2; i++){
            num = (num * i)/(den++);
        }
        return num;
    }
    int uniquePaths(int m, int n) {
        return fact(n, m);
    }
};