class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0];
        int y1=rec1[1];
        int x2=rec1[2];
        int y2=rec1[3];
        if(x2<=rec2[0] || x1>=rec2[2]){
            return false;
        }
        if(rec2[1]>=y2 || y1>=rec2[3]){
            return false;
        }
        return true;
    }
};