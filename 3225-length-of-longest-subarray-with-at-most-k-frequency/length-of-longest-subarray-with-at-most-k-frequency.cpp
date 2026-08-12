class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxLength=0;
        int st=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]=mp.count(nums[i])? mp[nums[i]]+1 :1;
            while(mp[nums[i]]>k){
                mp[nums[st]]--;
                st++;
            }
            maxLength=max(maxLength,i-st+1);
        }
        return maxLength;
    }
};