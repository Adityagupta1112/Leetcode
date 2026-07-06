class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto lambda=[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        };
        sort(intervals.begin(),intervals.end(),lambda);
        pair<int,int>p={intervals[0][0],intervals[0][1]};
        int n=intervals.size();
        int count=1;
        for(int i=1;i<n;i++){
            if(p.first<=intervals[i][0]  && p.second>=intervals[i][1]){
                continue;
            }
            p.first=intervals[i][0];
            p.second=intervals[i][1];
            count++;
        }
        return count;
    }
};