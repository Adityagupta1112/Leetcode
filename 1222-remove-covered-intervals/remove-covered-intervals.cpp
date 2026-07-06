class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>result;
        auto lambda=[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        };
        sort(intervals.begin(),intervals.end(),lambda);
        result.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(result[result.size()-1][0]<=intervals[i][0]  && result[result.size()-1][1]>=intervals[i][1]){
                continue;
            }
            result.push_back(intervals[i]);
        }
        return result.size();
    }
};