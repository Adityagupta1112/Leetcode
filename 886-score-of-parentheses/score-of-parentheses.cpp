class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int n=s.size();
        int score=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                st.push(score);
                score=0;
            }
            else{
                if(st.empty()){
                    continue;
                }
                else if(s[i-1]=='('){
                    score=st.top()+1;
                }
                else{
                    score=st.top()+2*score;
                }
                st.pop();
            }
        }
        st.push(score);
        return st.top();
    }
};