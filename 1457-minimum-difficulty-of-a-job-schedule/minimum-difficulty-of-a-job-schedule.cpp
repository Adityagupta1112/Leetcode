class Solution {
public:
    int solve(int idx,vector<int>&jobDifficulty,int d,int n,vector<vector<int>>&dp){
        if(d==1){
            int max_difficulty=jobDifficulty[idx];
            for(int i=idx;i<n;i++){
                max_difficulty=max(max_difficulty,jobDifficulty[i]);
            }
            return max_difficulty;
        }
        if(dp[idx][d]!=-1){
            return dp[idx][d];
        }
        int max_difficulty=jobDifficulty[idx];
        int final_difficulty=INT_MAX;
        for(int i=idx;i<=n-d;i++){
            max_difficulty=max(max_difficulty,jobDifficulty[i]);
            int result=max_difficulty+solve(i+1,jobDifficulty,d-1,n,dp);
            final_difficulty=min(final_difficulty,result); 
        }
        return dp[idx][d]=final_difficulty;;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        if(d>n){
            return -1;
        }
        return solve(0,jobDifficulty,d,n,dp);
    }
};