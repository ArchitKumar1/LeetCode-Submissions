// https://leetcode.com/problems/stock-price-fluctuation

class StockPrice {
public:
    multiset<int> s;
    unordered_map<int,int> m1;
    multiset<int> ls;
    StockPrice() {
        m1.reserve(1000000);
    }
    
    void update(int t, int price) {
        if(m1.find(t) != m1.end()){
            s.find(s.erase(m1[t]));
        }
        s.insert(price);
        ls.insert(t);
        m1[t] = price;
    }
    
    int current() {
        return m1[*ls.rbegin()];
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */