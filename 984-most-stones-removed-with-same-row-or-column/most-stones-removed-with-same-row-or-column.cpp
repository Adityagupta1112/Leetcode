class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int find(int i){
        if(par[i]==i){
            return i;
        }
        return par[i]=find(par[i]);
    }
    void mergerank(int u,int v){
        int par_u=find(u);
        int par_v=find(v);
        if(par_u==par_v){
            return ;
        }
        if(rank[par_u]>rank[par_v]){
            par[par_v]=par_u;
        }
        else if(rank[par_v]>rank[par_u]){
            par[par_u]=par_v;
        }
        else{
            par[par_u]=par_v;
            rank[par_v]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        par.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    mergerank(i,j);
                }
            }
        }
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            int val=find(i);
            s.insert(val);
        }
        return n-s.size();
    }
};