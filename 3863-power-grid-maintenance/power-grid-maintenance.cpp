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
        if(rank[par_u]>rank[par_v]){
            parent[par_v]=par_u;
        }
        else if(rank[par_v]>rank[par_u]){
            parent[par_u]=par_v;
        }
        else{
            parent[par_u]=par_v;
            rank[par_v]++;
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        parent.resize(c);
        rank.resize(c,1);
        vector<int>ans;

        vector<bool>offline(c,false);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0]-1;
            int v=connections[i][1]-1;
            Union(u,v);
        }

        unordered_map<int,set<int>>mp;

        for(int i=0;i<c;i++){
            int par=find(i);
            mp[par].insert(i);
        }

        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1]-1;
            if(u==2){
                if(offline[v]){
                    continue;
                }
                else{
                    offline[v]=true;
                    mp[find(v)].erase(v);
                }
            }
            else{
                if(!offline[v]){
                    ans.push_back(v+1);
                }
                else{
                    int par=find(v);
                    auto &s=mp[par];
                    if(s.empty()){
                        ans.push_back(-1);
                    }
                    else{
                        ans.push_back(*s.begin()+1);
                    }
                }
            }
        }
        return ans;
    }
};