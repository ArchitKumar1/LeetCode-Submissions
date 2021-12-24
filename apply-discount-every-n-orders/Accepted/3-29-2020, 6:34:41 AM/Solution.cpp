// https://leetcode.com/problems/apply-discount-every-n-orders

class Cashier {
public:
    int N ;
    int curr = 0;
    map<int,int> m1;
    int D;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        N = n;
        D = discount;
        for(int i = 0;i<products.size();i++){
            m1[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double bil = 0;
        for(int i = 0;i<product.size();i++){
            bil += m1[product[i]] *amount[i];
        }
        if(curr == N - 1){
            bil -= D*bil/100;
        }
        curr = (curr+1)%N;
        return bil;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */