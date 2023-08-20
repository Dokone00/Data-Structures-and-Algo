class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int cnt=0;
        if(s.length() == 1){
            return 1;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(s[i]==')' && !st.empty() && st.top()=='('){
                st.pop();
                cnt += 2;
            }
        }
        int ans = s.length() - cnt;
        return ans;
    }
};