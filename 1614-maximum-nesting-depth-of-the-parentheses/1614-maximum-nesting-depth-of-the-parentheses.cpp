class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
            }
            if(s[i]==')'){
                ans = max(cnt,ans);
                cnt--;
            }

        }
        return ans;
    }
};