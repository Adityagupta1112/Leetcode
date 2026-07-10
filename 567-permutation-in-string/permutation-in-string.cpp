class Solution {
public:
    bool helper(string&s, unordered_map<char,int>&mp){
        
        for(char ch:s){
            if(mp[ch]!=0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int m=s1.size();
        int n=s2.size();
        for(int i=0;i<m;i++){
            mp[s1[i]]++;
        }
        while(j<n){
            while(j-i+1>m){  
                mp[s2[i]]+=1;
                i++;
            }
            if(mp.count(s2[j])){
                mp[s2[j]]--;
            }
            if(helper(s1,mp)){
                return true;
            }
            j++;
        }
        return false;
    }
};