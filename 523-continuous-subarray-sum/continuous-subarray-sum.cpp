class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int prefix=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            int rem=prefix%k;
            if(mp.count(rem)){
                if(i-mp[rem]>=2){
                    return true;
                }
            }
            else{
                mp[rem]=i;
            }
        }
        return false;
    }
};