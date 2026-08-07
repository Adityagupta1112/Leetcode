class Solution {
public:
    vector<vector<int>>dp;
    int m,n;
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i==m-1 && j==n-1){
            return grid[m-1][n-1];
        }
        if(i>=m || j>=n){
            return INT_MAX;
        }
        if(dp[i][j] !=-1){
            return dp[i][j];
        }
        
        int right=solve(i,j+1,grid);
        int down=solve(i+1,j,grid);
        return dp[i][j]=grid[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return solve(0,0,grid);
    }
};