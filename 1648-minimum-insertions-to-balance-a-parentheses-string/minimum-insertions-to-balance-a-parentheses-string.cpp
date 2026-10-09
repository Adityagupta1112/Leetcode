class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        stack<char>st;
        int need=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    if(s[i+1]==')'){
                        need++;
                        i++;
                    }
                    else{
                        need+=2;
                    }
                }
                else{
                    if(i==n-1){
                        if(st.empty()){
                            need+=2;
                        }
                        else{
                            need++;
                            st.pop();
                        }
                    }
                    else if(s[i+1]==')'){
                        st.pop();
                        i++;
                    }
                    else{
                        need++;
                        st.pop();
                    }
                }
            }
        }
        if(!st.empty()){
            need+=st.size()*2;
        }
        return need;
    }
};