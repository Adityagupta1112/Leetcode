class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int score=0;
        int count0=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                count0++;
            }
            string right=s.substr(i+1);
            int count1=0;
            for(char ch:right){
                if(ch=='1'){
                    count1++;
                }
            }
            score=max(score,count1+count0);
        }
        return score;
    }
};