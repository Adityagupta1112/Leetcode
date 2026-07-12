class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.size();
        int i=0;
        int j=0;
        int maxLength=0;
        int maxFreq=0;
        while(j<n){
            char ch=s[j];
            mp[ch]++;
            maxFreq=max(maxFreq,mp[ch]);
            while(j-i+1-maxFreq>k){
                mp[s[i]]--;
                i++;
            }
            maxLength=max(maxLength,j-i+1);
            j++;
        }
        return maxLength;
    }
};