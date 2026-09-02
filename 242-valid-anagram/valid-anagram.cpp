class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m!=n){
            return false;
        }
        unordered_map<char,int>mp;
        for(char &ch:s){
            mp[ch]++;
        }
        for(char &ch:t){
            if(!mp.count(ch) || mp[ch]<=0){
                return false;
            }
            mp[ch]--;
        }
        return true;
    }
};