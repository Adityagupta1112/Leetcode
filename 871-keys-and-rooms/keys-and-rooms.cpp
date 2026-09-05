class Solution {
public:
    void solve(int src,vector<bool>&visited,vector<vector<int>>&rooms){
        visited[src]=true;
        for(int v:rooms[src]){
            if(!visited[v]){
                solve(v,visited,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        solve(0,visited,rooms);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};