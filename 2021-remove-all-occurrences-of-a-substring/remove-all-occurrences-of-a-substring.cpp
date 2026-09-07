class Solution {
public:
    bool check(stack<char>&st,string &part,int n){
        stack<char>temp=st;
        for(int i=n-1;i>=0;i--){
            if(temp.top()!=part[i]){
                return false;
            }
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        int n=part.size();
        stack<char>st;
        for(char ch:s){
            st.push(ch);
            if(st.size()>=n && check(st,part,n)){
                for(int i=0;i<n;i++){
                    st.pop();
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};