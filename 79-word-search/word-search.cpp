class Solution {
public:
    int m,n;
    vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
    bool solve(int idx,int i,int j,vector<vector<char>>&board,string & word){
        if(idx==word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$'){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        for(const auto& dir:direction){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(solve(idx+1,new_i,new_j,board,word)){
                return true;
            }
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(0,i,j,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};