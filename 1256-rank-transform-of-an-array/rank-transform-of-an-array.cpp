class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        sort(arr.begin(),arr.end());
        vector<int>result(n);
        int rank=1;
        unordered_set<int>s;

        for(int num:arr){
            if(s.count(num)){
                continue;
            }
            for(int idx:mp[num]){
                result[idx]=rank;
            }
            s.insert(num);
            rank++;
        }

        return result;
    }
};