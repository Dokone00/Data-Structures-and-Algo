class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int i=0;
        int s = flowerbed.size();
        if(s==1 && flowerbed[s-1] == 0){
            return true;
        }
        while(i<s-1 && cnt<n){
            if((i==0 && flowerbed[i]==0 && flowerbed[i+1]==0) || (i==s-2 && flowerbed[i]==0 && flowerbed[i+1]==0)){
                flowerbed[i]=1;
                cnt++;
                i++;
            }
            else if(flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i-1]==0){
                flowerbed[i]=1;
                cnt++;
                i++;
            }
            else{
                i++;
            }
        }
        return cnt>=n;
        
    }
};