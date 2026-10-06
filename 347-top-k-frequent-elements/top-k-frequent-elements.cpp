class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        priority_queue<int>pq;
        for(auto &it:mp){
            pq.push(it.second);
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            int freq=pq.top();
            for(auto &it:mp){
                if(it.second==freq){
                    ans.push_back(it.first);
                    mp[it.first]=0;
                }
            }
            pq.pop();
        }
        return ans;
    }
};