class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int prefix=0;
        unordered_map<int,int>mp;
        int count=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int need=prefix-goal;
            if(mp.count(need)){
                count+=mp[need];
            }
            mp[prefix]++;
        }
        return count;
    }
};