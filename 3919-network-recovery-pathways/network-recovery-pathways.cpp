class Solution {
public:
    bool isValid(unordered_map<int,vector<pair<int,long long>>>&mp,long long &k,int &n,long long &limit){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            int u=pq.top().second;
            long long currWt=pq.top().first;
            pq.pop();
            if(u==n-1){
                return dist[u]<=k;
            }
            if(dist[u]<currWt){
                continue;
            }
            for(auto &neigh:mp[u]){
                int v=neigh.first;
                long long wt=neigh.second;
                
                if(wt>=limit && dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        unordered_map<int,vector<pair<int,long long>>>mp;
        long long maxwt=0;
        int n=online.size();
        if(!online[0] && !online[n-1]){
            return -1;
        }
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            long long wt=edge[2];
            if(online[u] && online[v]){
                maxwt=max(maxwt,wt);
                mp[u].push_back({v,wt});
            } 
        }
        
        long long  st=0;
        long long en=maxwt;
        long long ans=-1;
        while(st<=en){
            long long mid=st+(en-st)/2;
            if(isValid(mp,k,n,mid)){
                ans=mid;
                st=mid+1;
            }
            else{
                en=mid-1;
            }
        }
        return (int)ans;
    }
};