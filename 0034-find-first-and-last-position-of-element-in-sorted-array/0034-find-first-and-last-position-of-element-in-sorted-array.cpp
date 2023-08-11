class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0,end = nums.size() - 1;
        int ans[] = {-1,-1};
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid]==target){
                ans[0] = mid;
                end = mid -1;
            }
            else if(nums[mid]<target){
                start = mid+1;
            }
            else{end= mid -1;}
        }
        int start1 = 0;
        int end1 = nums.size() - 1;
        while(start1<=end1){
            int mid1 = start1 + (end1 - start1)/2;
            if(nums[mid1]==target){
                ans[1] = mid1;
                start1 = mid1 +1;
            }
            else if(nums[mid1]<target){
                start1 = mid1+1;
            }
            else{end1= mid1 -1;}
        }
        return vector<int>(ans, ans + 2);
    }
};