class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.size();
        int n=s.size();
        if(m>n){
            return "";
        }
        unordered_map<char,int>need;
        for(char ch:t){
            need[ch]++;
        }
        int required=m;
        int start=0;
        int left=0;
        int right=0;
        int minLen=INT_MAX;
        while(right<n){
            if(need.count(s[right])){
                if(need[s[right]]>0){
                    required--;
                }
                need[s[right]]--;
            }
            while(required==0){
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                if (need.count(s[left])) {
                    need[s[left]]++;
                    if (need[s[left]] > 0){
                        required++;
                    }     
                }
                left++;
            }
            right++;
        }
        return minLen==INT_MAX?"": s.substr(start,minLen);
    }
};