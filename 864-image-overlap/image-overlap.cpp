class Solution {
public:
    int ans=0;
    void solve(int rowoff,int coloff,vector<vector<int>>&img1,vector<vector<int>>&img2){
        int n=img1.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int new_i=i+rowoff;
                int new_j=j+coloff;
                if(new_i>=n || new_j>=n || new_i<0 || new_j<0){
                    continue;
                }
                if(img1[new_i][new_j]==1 && img2[i][j]==1){
                    count++;
                }
            }
        }
        ans=max(count,ans);
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        for(int rowoff=1-n;rowoff<=n-1;rowoff++){
            for(int coloff=1-n;coloff<=n-1;coloff++){
                solve(rowoff,coloff,img1,img2);
            }
        }
        return ans;
    }
};