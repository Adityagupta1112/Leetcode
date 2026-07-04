class Solution {
public:
    unordered_map<int,vector<pair<int,int>>>mp;
    vector<bool>visited;
    int minwt=INT_MAX;
    void DFS(int u){
        visited[u]=true;
        for(auto & neigh:mp[u]){
            int v=neigh.first;
            int wt=neigh.second;
            minwt=min(minwt,wt);
            if(!visited[v]){
                DFS(v);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        visited.resize(n,false);
        for(auto &road:roads){
            int u=road[0]-1;
            int v=road[1]-1;
            int wt=road[2];
            mp[u].push_back({v,wt});
            mp[v].push_back({u,wt});
        }
        DFS(0);
        return minwt;
    }
};