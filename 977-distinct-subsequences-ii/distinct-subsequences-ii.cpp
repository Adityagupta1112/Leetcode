class Solution {
public:
    int MOD=1e9+7;
    int solve(int n,vector<int>prev,vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int total=(2*solve(n-1,prev,dp))%MOD;
        if(prev[n]!=0){
            int dublicate=solve(prev[n]-1,prev,dp);
            total=(total-dublicate+MOD)%MOD;
        }
        return dp[n]=total;
    }
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>prev(n+1,0);
        vector<int>lastSeen(26,0);
        for(int i=1;i<=n;i++){
            int idx=s[i-1]-'a';
            prev[i]=lastSeen[idx];
            lastSeen[idx]=i;
        }
        vector<int>dp(n+1,-1);
        return (solve(n,prev,dp)-1+MOD)%MOD;
    }
};