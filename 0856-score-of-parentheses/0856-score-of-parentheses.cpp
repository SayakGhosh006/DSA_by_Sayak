class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int>st;
        st.push(0);
        for(auto ch:s){
            if(ch=='(')
                st.push(0);
             else{
                 int top=st.top();
                 st.pop();
                 int A=max(2*top,1);
                 int b=st.top();
                 st.pop();
                st.push(A+b);
            }
        }
        return st.top();
    }
};