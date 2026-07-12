class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        int count=0;
        for(auto &it :mp){
            count+=it.second/2;
            mp[it.first]=it.second%2;
        }
        count=count*2;
        for(auto &it:mp){
            if(it.second==1){
                count++;
                break;
            }
        }
        return count;
    }
};