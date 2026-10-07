class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int num=nums[i];
            if(num>=0){
                dp[i]=max(dp[i-1]+num,num);
            }
            else{
                dp[i]=max(dp[i-1]+num,num);
            }
        }
        int ans=INT_MIN;
        for(int v:dp){
            ans=max(ans,v);
        }
        return ans;
    }
};