class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        set<pair<int,int>>s;
        int n=intervals.size(); 
        for(auto& interval:intervals){
            pair<int,int>p={interval[0],interval[1]};
            s.insert(p);
        }
        for(int i=0;i<n;i++){
            pair<int,int>p={intervals[i][0],intervals[i][1]};
            if(s.find(p)==s.end()){
                continue;
            }
            for(int j=0;j<n;j++){
                if(i!=j && (intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][1])){
                    s.erase(make_pair(intervals[j][0],intervals[j][1]));
                }
            }
        }
        return s.size();
    }
};