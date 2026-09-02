class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(char ch:t){
            if(mp.count(ch)){
                mp[ch]++;
            }
            else{
                mp[ch]=1;
            }
        }
        for(char ch:s){
            mp[ch]--;
        }
        char ans;
        for(auto &it:mp){
            if(it.second!=0){
                ans= it.first;
                break;
            }
        }
        return ans;
    }
};