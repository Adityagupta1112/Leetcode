class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int num:nums){
            mp[num]++;
        }
        for(auto &it:mp){
            pq.push({it.second,it.first});
            while(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>result;
        while(!pq.empty()){
            auto[freq,el]=pq.top();
            pq.pop();
            result.push_back(el);
        }
        return result;
    }
};