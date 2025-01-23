class Solution {
  public:
    int maxLength(string& str) {
        stack <pair <char, int>> st;
        st.push({'#', 0});
        int max_len = 0;
        for(char& ch: str){
            if(ch == ')'){
                if(st.top().first == '('){
                    auto it = st.top();
                    st.pop();
                    st.top().second += it.second + 2;
                    max_len = max(max_len, st.top().second);
                }else st.push({')', 0});
            }else st.push({ch, 0});
        }
        return max_len;
    }
};