class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int idx=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(mp.count(ch)){
                idx=max(mp[ch],idx);
            }
            mp[ch]=i;
            int len=i-idx;
            ans=max(ans,len);
        }
        return ans;
    }
};