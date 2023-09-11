class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>>v;
        unordered_map<int,vector<int>>mp;


        for(int i=0;i<n;i++){
            int size=groupSizes[i];
            mp[size].push_back(i);
           if(mp[size].size()==size){
               v.push_back(mp[size]);
               mp[size].clear();
           }
        }
        return v;

    }
};