class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>temp=strs;
        for(auto &str:temp){
            sort(str.begin(),str.end());
        }
        unordered_map<string,vector<int>>mp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            if(mp.count(temp[i])){
                mp[temp[i]].push_back(i);
            }
            else{
                mp[temp[i]]={i};
            }
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            vector<string>str;
            for(int idx:it.second){
                str.push_back(strs[idx]);
            }
            ans.push_back(str);
        }
        return ans;
    }
};