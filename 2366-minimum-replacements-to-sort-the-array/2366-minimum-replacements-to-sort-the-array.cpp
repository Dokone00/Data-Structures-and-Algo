class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long cnt = 0;
        int temp = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]> temp){
                int k=nums[i];
                int q = k/temp;
                if(k%temp==0){
                    cnt = cnt+q-1;
                }
                else{
                    temp = k/(q+1);
                    cnt+=q;
                }
                
            }
            else{
                temp = nums[i];
            }
        }
        return cnt;
    }
};