class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        set<pair<int,int>>s;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(); 
        for(int i=0;i<n;i++){
            pair<int,int>p={intervals[i][0],intervals[i][1]};
            if(s.find(p)!=s.end()){
                continue;
            }
            for(int j=0;j<n;j++){
                if(i!=j && (intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][1])){
                    s.insert(make_pair(intervals[j][0],intervals[j][1]));
                }
            }
        }
        return n-s.size();
    }
};