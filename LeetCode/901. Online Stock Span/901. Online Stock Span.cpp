class StockSpanner {
private:
    int sz, prices[100000], left[100000];
public:
    StockSpanner() {
        sz = 0;
    }
    int next(int price) {
        int res = 1,
            i = sz - 1,
            lastValidI = -1;
        
        while(~i && price >= prices[i])
        {
            res += (i - left[i]) + 1;
            lastValidI = i;
            i = left[i] - 1;
        }
        
        left[sz] = (~lastValidI ? lastValidI : sz);
        prices[sz++] = price;
        return res;
    }
};
