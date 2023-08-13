class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    int i =0;
    int next(int price) {
        while(s.size()!=0 && s.top().first <= price){
            s.pop();
        }
        int span = 0;
        if(s.size() == 0){
            span = i+1;
        }
        else{
            span = (i-s.top().second);
        }
        s.push({price,i});
        i++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */