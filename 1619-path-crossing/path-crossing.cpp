class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0;
        int y=0;
        unordered_set<string>s;
        s.insert("0_0");
        for(char ch:path){
            if(ch=='N'){
                y++;
            }
            else if(ch=='S'){
                y--;
            }
            else if(ch=='E'){
                x++;
            }
            else{
                x--;
            }
            string str=to_string(x)+"_"+to_string(y);
            if(s.count(str)){
                return true;
            }
            s.insert(str);
        }
        return false;
    }
};