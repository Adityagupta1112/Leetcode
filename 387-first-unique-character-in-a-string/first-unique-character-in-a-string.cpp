class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(mp[ch]==1){
                return i;
            }
        }
        return -1;
    }
};