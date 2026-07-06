class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>temp=strs;
        int n=strs.size();
        for(auto &str:strs){
            sort(str.begin(),str.end());
        }
        unordered_map<string,vector<int>>mp;
    
        for(int i=0;i<n;i++){
            if(mp.count(strs[i])){
                mp[strs[i]].push_back(i);
            }
            else{
                mp[strs[i]]={i};
            }
        }
        vector<vector<string>>result;
        for(auto &it:mp){
            vector<string>arr;
            for(int idx:it.second){
                arr.push_back(temp[idx]);
            }
            result.push_back(arr);
        }
        return result;
    }
};