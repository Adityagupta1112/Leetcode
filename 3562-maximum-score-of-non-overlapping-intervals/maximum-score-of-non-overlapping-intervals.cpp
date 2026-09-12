class Solution {
public:
    struct Node{
        long long score=0;
        vector<int>idx;
    };
    int n;
    vector<int>nextIdx;

    int findNext(vector<vector<int>>&intervals,int end){
        int l=0;
        int r=n-1;
        int result=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(intervals[mid][0]>end){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }

    Node solve(vector<vector<int>>&intervals,int i,int k,vector<vector<Node>>&dp){
        if(i>=n || k==0){
            return Node();
        }

        if(dp[i][k].score!=0){
            return dp[i][k];
        }

        Node skip=solve(intervals,i+1,k,dp);

        int j=nextIdx[i];
        int idx=intervals[i][3];

        Node temp=solve(intervals,j,k-1,dp);

        Node take;
        take.score=intervals[i][2] +temp.score;
        take.idx=temp.idx;
        take.idx.push_back(idx);
        sort(begin(take.idx),end(take.idx));

        Node result;

        if(take.score>skip.score){
            result=take;
        }
        else if(take.score<skip.score){
            result=skip;
        }
        else{
            result=take.idx>skip.idx?skip:take;
        }
        return dp[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n=intervals.size();
        nextIdx.resize(n);
        for(int i=0;i<n;i++){
            intervals[i].push_back(i);
        }
        sort(begin(intervals),end(intervals));
        for(int i=0;i<n;i++){
            int end=intervals[i][1];
            nextIdx[i]=findNext(intervals,end);
        }
        vector<vector<Node>>dp(n+1,vector<Node>(5));

        return solve(intervals,0,4,dp).idx;
    }
};