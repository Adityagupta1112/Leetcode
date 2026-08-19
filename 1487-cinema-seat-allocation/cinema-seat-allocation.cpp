class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int count=2*n;
        unordered_map<int,vector<bool>>mp;
        for(int i=0;i<reservedSeats.size();i++){
            int row=reservedSeats[i][0]-1;
            int seat=reservedSeats[i][1]-1;
            if(!mp.count(row)){
                mp[row]=vector<bool>(10,false);
            }
            mp[row][seat]=true;
        }
        for(auto &it : mp){
           
            vector<bool>seats=it.second; 
            bool left=true;
            bool middle=true;
            bool right=true;
            for(int j=1;j<5;j++){
                if(seats[j]){
                    left=false;
                    break;
                }
            }
            for(int j=3;j<7;j++){
                if(seats[j]){
                    middle=false;
                    break;
                }
            }
            for(int j=5;j<9;j++){
                if(seats[j]){
                    right=false;
                    break;
                }
            }
            if(left && right){
                continue;
            }
            else if(left || middle || right){
                count--;
            }
            else{
                count-=2;
            }
        }
        return count;
    }
};