class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int prefix=0;
        mp[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int need=prefix-k;
            if(mp.count(need)){
                count+=mp[need];
            }
            mp[prefix]++;
        }
        return count;
    }
};