class Solution {
public:
    void helper(int n,vector<string>&dp,int close,int open,string &str){
        if(str.size()==2*n){
            dp.push_back(str);
            return;
        }
        if(open<n){
            str.push_back('(');
            helper(n,dp,close,open+1,str);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            helper(n,dp,close+1,open,str);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
      vector<string>dp;
      int close=0;
      int open=0;
      string str="";
      helper(n,dp,close,open,str); 
      return dp; 
    }
};