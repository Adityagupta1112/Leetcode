class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string>str;
        int count=0;
        string temp="";
        for(char ch:s){
            temp.push_back(ch);
            if(ch=='('){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                str.push_back(temp);
                temp="";
            }
        }
        string ans="";
        for( string st:str){
            string strs=st.substr(1,st.size()-2);
            ans=ans+strs;
        }
        return ans;
    }
};