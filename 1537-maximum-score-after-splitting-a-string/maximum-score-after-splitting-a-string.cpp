class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int score=0;
        for(int i=0;i<n-1;i++){
            string left=s.substr(0,i+1);
            string right=s.substr(i+1);
            int count0=0;
            int count1=0;
            for(char ch:left){
                if(ch=='0'){
                    count0++;
                }
            }
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