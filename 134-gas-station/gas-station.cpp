class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgas=0;
        int totalcost=0;
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalcost>totalgas){
            return -1;
        }
        int currGas=0;
        int ans=0;
        for(int i=0;i<n;i++){
            currGas+=(gas[i]-cost[i]);
            if(currGas<0){
                currGas=0;
                ans=i+1;
            }
        }
        return ans;
    }
};