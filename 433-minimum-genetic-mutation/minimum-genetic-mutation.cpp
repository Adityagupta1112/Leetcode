class Solution {
public:
    vector<char>choices={'A','C','G','T'};
    queue<string>q;
    unordered_set<string>visited;
    unordered_set<string>s;
    void solve(string &curr,queue<string>&q,vector<string>&bank){
        for(int i=0;i<8;i++){
            char change=curr[i];
            for(int j=0;j<4;j++){
                curr[i]=choices[j];
                if(s.count(curr) && !visited.count(curr)){
                    q.push(curr);
                    visited.insert(curr);
                }
            }
            curr[i]=change;
        }
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        for(auto & str:bank){
            s.insert(str);
        }
        q.push(startGene);
        int total_step=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string curr=q.front();
                q.pop();
                if(curr==endGene){
                    return total_step;
                }
                solve(curr,q,bank);
            }
            total_step++;
        }
        return -1;
    }
};