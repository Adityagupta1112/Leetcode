class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        unordered_map<int,int>mc;                                           //coloum
        unordered_map<int,int>mr;
        unordered_map<int,int>m;
        for(int i=0;i<r;i++){
             mc.clear();
            for(int j=0;j<c;j++){
                if(isdigit(board[i][j])){
                    if(mc.find(board[i][j])==mc.end()){
                        mc[board[i][j]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        for(int i=0;i<c;i++){ 
            mr.clear();                   //board[j][i]                      //row
            for(int j=0;j<r;j++){
                if(isdigit(board[j][i])){
                    if(mr.count(board[j][i])==0){
                        mr[board[j][i]]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        for(int boxrow=0;boxrow<3;boxrow++){
            for(int boxcol=0;boxcol<3;boxcol++){
                m.clear();
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(isdigit(board[i+3*boxrow][j+3*boxcol])){
                            if(m.count(board[i+3*boxrow][j+3*boxcol])==0){
                                m[board[i+3*boxrow][j+3*boxcol]]=1;
                            }
                            else{
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};