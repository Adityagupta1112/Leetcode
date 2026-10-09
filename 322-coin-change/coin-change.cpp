class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j){
                    int take=INT_MAX;
                    if(dp[i][j-coins[i-1]]!=INT_MAX){
                        take=1+dp[i][j-coins[i-1]];
                    }
                    int skip=dp[i-1][j];
                    dp[i][j]=min(take,skip); 
                }
                else{
                    dp[i][j]=dp[i-1][j]; 
                }
            }
        }
        return dp[n][amount]==INT_MAX?-1:dp[n][amount];
    }
};