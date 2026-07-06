class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int u,int v){
        int par_u=find(u);
        int par_v=find(v);
        if(par_u==par_v){
            return;
        }
        if(rank[par_u]<rank[par_v]){
            parent[par_u]=par_v;
        }
        else if(rank[par_u]>rank[par_v]){
            parent[par_v]=par_u;
        }
        else{
            parent[par_u]=par_v;
            rank[par_v]++;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto& allowed:allowedSwaps){
            int u=allowed[0];
            int v=allowed[1];
            Union(u,v);
        }
        unordered_map<int,unordered_map<int,int>>mp;
        for(int i=0;i<n;i++){
            int par=find(i);
            mp[par][source[i]]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int par=find(i);
            if(mp[par][target[i]]>0){
                mp[par][target[i]]--;
                continue;
            }
            count++;
        }
        return count;
    }
};