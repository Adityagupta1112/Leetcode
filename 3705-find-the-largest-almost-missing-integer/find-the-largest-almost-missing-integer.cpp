class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=-1;
        for(int i=0;i<=n-k;i++){
            int count=0;
            set<int>s;
            for(int j=i;j<i+k;j++){
                s.insert(nums[j]);
            }
            for(int v:s){
                if(mp.count(v)){
                    mp[v]++;
                }
                else{
                    mp[v]=1;
                }
            }
        }
        for(auto &it:mp){
            if(it.second==1){
                ans=max(ans,it.first);
            }
        }
        return ans;
    }
};