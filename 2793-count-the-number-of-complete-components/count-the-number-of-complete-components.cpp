class Solution {
public:
    unordered_map<int,vector<int>>mp;

    void DFS(int u,int &node,int &edge,vector<bool>&visited){
        visited[u]=true;
        node++;
        edge+=mp[u].size();
        for(int v:mp[u]){
            if(!visited[v]){
                DFS(v,node,edge,visited);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>visited(n,false);
        int count=0;
        
        for(int i=0;i<n;i++){
            int node=0;
            int edge=0;
            if(!visited[i]){
                DFS(i,node,edge,visited);
                if(node*(node-1)==edge){
                    count++;
                }
            }
        }
        return count;
    }
};