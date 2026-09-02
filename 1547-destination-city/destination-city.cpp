class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string>mp;
        for(int i=0;i<paths.size();i++){
            string start=paths[i][0];
            string end=paths[i][1];
            mp[start]=end;
        }
        for(int i=0;i<paths.size();i++){
            if(mp.find(paths[i][1])==mp.end()){
                return paths[i][1];
            }
        }
        return "";
    }
};