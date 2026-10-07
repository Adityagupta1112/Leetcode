class Solution {
public:
    
    int solve(int idx,vector<int>&jobDifficulty,int d,vector<vector<int>>&dp){
        if(d==1){
            int maxDiff=jobDifficulty[idx];
            for(int i=idx;i<jobDifficulty.size();i++){
                maxDiff=max(maxDiff,jobDifficulty[i]);
            }
            return maxDiff;
        }
        if(dp[idx][d]!=-1){
            return dp[idx][d];
        }
        int maxDiff=jobDifficulty[idx];
        int finalDiff=INT_MAX;
        for(int i=idx;i<jobDifficulty.size()-d+1;i++){
            maxDiff=max(maxDiff,jobDifficulty[i]);
            int result=maxDiff+solve(i+1,jobDifficulty,d-1,dp);
            finalDiff=min(finalDiff,result);
        }
        return dp[idx][d]=finalDiff;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n){
            return -1;
        }
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return solve(0,jobDifficulty,d,dp);
    }
};