class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int score=0;
        int count0=0;
        int count1=0;
        for(char ch:s){
            if(ch=='1'){
                count1++;
            }
        }
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                count0++;
            }
            else{
                count1--;
            }
            score=max(score,count1+count0);
        }
        return score;
    }
};