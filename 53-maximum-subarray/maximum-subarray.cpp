class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int num=nums[i];
            dp[i]=max(dp[i-1]+num,num);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};