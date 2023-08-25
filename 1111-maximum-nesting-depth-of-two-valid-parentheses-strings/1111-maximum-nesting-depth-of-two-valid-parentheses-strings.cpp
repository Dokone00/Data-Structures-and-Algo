class Solution {
public:
    vector<int> maxDepthAfterSplit(string s){
        vector<int>v;
        int mx=0;
        for(auto i:s){
            if(i=='('){
                mx++;
            }
            v.push_back(mx&1);
            if(i==')'){
                mx--;
            }
        }
        return v;
    }
};