class Solution {
public:
    int n;
    int  solve(int idx,vector<int>&nums,int prev,vector<vector<int>>&dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int take=0;
        if(prev==-1 || nums[idx]>nums[prev]){
            take=solve(idx+1,nums,idx,dp)+1;
        }
        int skip=solve(idx+1,nums,prev,dp);
        return dp[idx][prev+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,nums,prev,dp); ;
    }
};