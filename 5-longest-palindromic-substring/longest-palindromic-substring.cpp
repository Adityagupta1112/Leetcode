class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int maxLength=1;
        int stIdx=0;
        for(int len=2;len<=n;len++){
            for(int i=0;i<n;i++){
                int j=i+len-1;
                if(j>=n){
                    continue;
                }
                if(i+1==j){
                    dp[i][j]=(s[i]!=s[j])?0:1;
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                if(dp[i][j]==1 && len>maxLength){
                    stIdx=i;
                    maxLength=len;
                }
            }
        }
        return s.substr(stIdx,maxLength);
    }
};