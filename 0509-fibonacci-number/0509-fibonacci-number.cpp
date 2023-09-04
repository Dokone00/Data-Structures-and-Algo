class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2 ){
            return 1;
        }
        int p=1,c=1;
        for(int i=3;i<=n;i++){
            int temp = c;
            c = p+c;
            p = temp;
        }
        return c;
        
    }
};