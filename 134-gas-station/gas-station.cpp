class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalgas=0;
        int totalcost=0;
        int maxDiff=INT_MIN;
        int idx=-1;
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
            int leftGas=gas[i]-cost[i];
            if(leftGas>maxDiff){
                maxDiff=leftGas;
                idx=i;
            }
        }
        if(totalcost>totalgas){
            return -1;
        }
        int i=idx;
        int currGas=maxDiff;
        int j=i+1;
        while(j<n && i!=j){
            int left=gas[j]-cost[j];
            currGas+=left;
            if(currGas<0){
                while(currGas<0){
                    i=(i+1)%n;
                    currGas=gas[i]-cost[i];
                }
                j=(i+1)%n;
                continue;
            }
            j=(j+1)%n;
        }
        return i;
    }
};