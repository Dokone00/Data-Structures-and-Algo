class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int lpos = 1;
        int rpos = n-2;
        int water = 0;
        while(lpos <= rpos)
        {
            if(height[lpos] >= lmax)
            {
                lmax = height[lpos];
                lpos++;
            }
            else if(height[rpos] >= rmax)
            {
                rmax = height[rpos];
                rpos--;
            }
            else if(lmax <= rmax && height[lpos] < lmax)
            {
                water += lmax - height[lpos];
                lpos++;
            }
            else
            {
                water += rmax - height[rpos];
                rpos--;
            }
        
        }
        return water;

        // int n = height.size();
        // vector<int> right(n , 0);
        // vector<int> left(n,0);
        // stack<int>s;

        // for(int i=n-1;i>=0;i--){
        //     if(s.empty()){
        //         right[i] = 0;
        //         s.push(height[i]);
        //     }
        //     if(height[i]>s.top()){
        //         right[i] = 0;
        //         s.pop();
        //         s.push(height[i]);
        //     }
        //     else{
        //         right[i]=s.top();
        //     }
            
        // }

        // s.pop();
        // for(int i=0;i<n;i++){
        //     if(s.empty()){
        //         left[i] = 0;
        //         s.push(height[i]);
        //     }
        //     if(height[i]>s.top()){
        //         left[i] = 0;
        //         s.pop();
        //         s.push(height[i]);
        //     }
        //     else{
        //         left[i]=s.top();
        //     }
            
        // }
        // int ans = 0;
        // for(int i = 0;i < n ; i++){
            
        //     int mini = min(left[i],right[i]);
        //     if(mini == 0){
        //         ans += mini;
        //     }
        //     else{
        //         ans += mini - height[i];
        //     }
        // }
        // return ans;

    }
};