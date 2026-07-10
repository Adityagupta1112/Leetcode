class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
        int maxlength=0;
        int maxFreq=0;
        int n=s.size();
        while(j<n){
            char ch=s[j];
            if(mp.count(ch)){
                mp[ch]+=1;
            }
            else{
                mp[ch]=1;
            }
            maxFreq=max(maxFreq,mp[ch]);
            while(j-i+1-maxFreq > k){
                char c=s[i];
                mp[c]-=1;
                i++;
            }
            maxlength=max(maxlength,j-i+1);
            j++;
        }
        return maxlength;
    }
};