class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.size();
        vector<int>lastSeen(n,-1);
        vector<int>chars(26,-1);
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            lastSeen[i]=chars[idx];
            if(chars[idx]!=-1){
                continue;
            }
            chars[idx]=i;
        }
        int ans=-1;
        for(int i=0;i<lastSeen.size();i++){
            if(lastSeen[i]==-1){
                continue;
            }
            int len=i-lastSeen[i]-1;
            ans=max(ans,len);
        }
        return ans;
    }
};