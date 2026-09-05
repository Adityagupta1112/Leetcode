class Solution {
public:
    vector<vector<int>>direction={{1,0},{0,1},{-1,0},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>>q;
        int row=maze.size();
        int col=maze[0].size();
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int step=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<int,int>curr=q.front();
                q.pop();
                
                if((curr.first==0 || curr.second==0 || curr.first==row-1 || curr.second==col-1 )&& step!=0){
                    return step;
                }
                for(auto &dir:direction){
                    int new_i=curr.first+dir[0];
                    int new_j=curr.second+dir[1];
                    if(new_i>=0 && new_j>=0 && new_i<row && new_j<col && maze[new_i][new_j]=='.'){
                        q.push({new_i,new_j});
                        maze[new_i][new_j]='+';
                    }
                }
            }
            step++;
        }
        return -1;
    }
};