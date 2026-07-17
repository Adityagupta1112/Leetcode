class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int n=s.size();
        int j=0;
        int maxLength=0;
        unordered_map<char,int>mp;
        while(j<n){
            char ch=s[j];
            while(mp.count(ch) && i<=mp[ch]){
                i=mp[ch]+1;
            }
            mp[ch]=j;
            maxLength=max(maxLength,j-i+1);
            j++;
        }
        return maxLength;
    }
};