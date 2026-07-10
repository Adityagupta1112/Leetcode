class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>vec1(26,0);
        vector<int>vec2(26,0);
        vector<int>result;
        int m=p.size();
        int n=s.size();
        if(m>n){
            return result;
        }
        for(char ch:p){
            vec1[ch-'a']++;
        }
        for(int i=0;i<m;i++){
            vec2[s[i]-'a']++;
        }
        if(vec1==vec2){
            result.push_back(0);
        }
        for(int i=m;i<n;i++){
            vec2[s[i]-'a']++;
            vec2[s[i-m]-'a']--;
            if(vec1==vec2){
                result.push_back(i-m+1);
            }
        }
        return result;
    }
};