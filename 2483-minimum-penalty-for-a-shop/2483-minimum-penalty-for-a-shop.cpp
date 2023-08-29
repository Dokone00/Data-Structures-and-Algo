class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int cnt = 0;
        int cnt1 = 0;
        int ans = 0;
        int max = 0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                cnt++;
            }
        }
        if(cnt == n){
            return n;
        }
        else if(cnt == 0){
            return cnt;
        }else{
            
            for(int i=0;i<n;i++){
                if(customers[i]=='Y'){
                    cnt1++;
                }
                else{
                    cnt1--;
                }
                if(cnt1>max){
                    max=cnt1;
                    ans = i+1;
                }
            }
        }
        // if(cnt<cnt1){
        //     return 0;
        // }
        return ans;
        
        
    }
};