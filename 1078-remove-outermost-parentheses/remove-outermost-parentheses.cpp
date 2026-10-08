class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string temp="";
        string ans="";
        for(char ch:s){
            temp.push_back(ch);
            if(ch=='('){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                string strs=temp.substr(1,temp.size()-2);
                ans=ans+strs;
                temp="";
            }
        }
        
        return ans;
    }
};