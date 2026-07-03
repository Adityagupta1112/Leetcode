class Solution {
public:
    int n;
    void helper(string &s,vector<vector<bool>>&dp){
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=len+i-1;
                if(len==2 && s[i]==s[j]){
                    dp[i][j]=true;
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
            }
        }
    }
    int countSubstrings(string s) {
        n=s.size();
        int count=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        helper(s,dp);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};