class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        queue<int>q;
        vector<int>visited(n,false);
        q.push(source);
        visited[source]==true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(curr==destination){
                return true;
            }
            for(int v:mp[curr]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
        return false;
    }
};