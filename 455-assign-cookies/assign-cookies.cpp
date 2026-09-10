class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int n=g.size();
        int m=s.size();
        // if(n==0 || m==0){
        //     return 0;
        // }
        int count=0;
        int idx=m-1;

        for(int i=n-1;i>=0;i--){
            if(idx>=0 && s[idx]>=g[i]){
                count++;
                idx--;
            }
        }
        return count;
    }
};