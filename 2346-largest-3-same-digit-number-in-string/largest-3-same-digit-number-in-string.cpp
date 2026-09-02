class Solution {
public:
    string largestGoodInteger(string num) {
       vector<string>ans;
       int n=num.size();
       for(int i=0;i<=n-3;i++){
        int count=0;
        for(int j=i;j<i+3;j++){
            if(num[i]==num[j]){
                count++;
            }
        }
        if(count==3){
            ans.push_back(num.substr(i,3));
        }
       }
       int maxInt=INT_MIN;
       int idx=-1;
       for(int i=0;i<ans.size();i++){
        int val=ans[i][0]-'0';
        if(val>maxInt){
            maxInt=val;
            idx=i;
        }
       }
       return idx==-1?"":ans[idx];
    }
};