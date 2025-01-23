class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;

        int i = 0;
        while(i < num.size() && k > 0){
            char digit = num[i];
            while(!st.empty() && digit < st.top() && k > 0){
                st.pop();
                k--;
            }
            st.push(digit);
            i++;
        }
        while(i < num.size()) st.push(num[i++]);
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int zeros = 0;
        for(auto digit: ans){
            if(digit != '0') break;
            zeros++;
        }
        string removed_leading_zeros = ans.substr(zeros);
        if(removed_leading_zeros.size() == 0) return "0";
        return removed_leading_zeros;
    }
};