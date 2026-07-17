class StockSpanner {
public:
    vector<int> local;
    int size=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int soln=1;
        for(int i=size-1;i>=0;i--){
            if(local[i]>price)
                break;
            else
                soln++;
        }
        size++;
        local.emplace_back(price);
        return soln;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */