class Solution {
public:
    bool isValid(string& str, int i){
        if(str[i-1] == '0') return false;
        string num;
        num += str[i-1];
        num += str[i];
        cout << num << "\n";
        return num <= "26";
    }
    int numDecodings(string s){
        int n = s.size();
        string str = "9" + s;
        int prev = 1;
        int prev_prev = 1;
        for(int i = 1; i <= n; i++){
            int curr;
            if(str[i] == '0'){
                if(!isValid(str, i)) return 0;
                curr = prev_prev;
            }else{
                curr = prev;
                if(isValid(str, i)) curr += prev_prev;
            }
            prev_prev = prev;
            prev = curr;
        }
        return prev;   
    }
};