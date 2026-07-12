class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int n=s.size();
        int ans=0;
        while(j<n){
            char ch=s[j];
            while(mp.count(ch) && i<=mp[ch]){
                i=mp[ch]+1;
            }
            mp[ch]=j;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};