class Solution {
  int precedence(char op){
      switch(op){
          case('('): return 0;
          case('+'): return 1;
          case('-'): return 1;
          case('*'): return 2;
          case('/'): return 2;
          case('^'): return 3;
      }
  }
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s){
        string postFix;
        stack <char> st;
        
        for(auto ch: s){
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) postFix += ch;
            else if(ch == '(') st.push(ch);
            else if(ch == ')'){
                while(st.top() != '('){
                    postFix += st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while((!st.empty()) && (precedence(ch) <= precedence(st.top()))){
                    postFix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            postFix += st.top();
            st.pop();
        }
        return postFix;
    }
};